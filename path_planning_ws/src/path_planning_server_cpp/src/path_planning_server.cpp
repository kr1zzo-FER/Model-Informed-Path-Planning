#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <utility>
#include <limits>
#include <string>
#include <functional>
#include <memory>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "user_action_interfaces/msg/coast_msg.hpp"
#include "user_action_interfaces/action/start_goal_action.hpp"
#include "user_action_interfaces/msg/zones_dictionary_entry.hpp"

namespace user_action_interfaces
{
class PathPlanningServer : public rclcpp::Node
{
public:
    using StartGoalAction = user_action_interfaces::action::StartGoalAction;
    using GoalHandle = rclcpp_action::ServerGoalHandle<StartGoalAction>;

    explicit PathPlanningServer(const rclcpp::NodeOptions &options = rclcpp::NodeOptions())
        : Node("path_planning_server_cpp", options), first_run_(true)
    {
        using namespace std::placeholders;
        RCLCPP_INFO(this->get_logger(), "Path planning server started");

        // Declare parameters
        this->declare_parameter<std::vector<double>>("cost_values", {10.0, 2.0, 1.5, 1.2});
        this->declare_parameter<std::vector<double>>("step_sizes", {50.0, 50.0, 100.0, 100.0});
        this->declare_parameter<std::vector<double>>("speed_limits", {2.0, 5.0, 8.0, 25.0});
        this->declare_parameter<bool>("show_feedback", false);
        this->declare_parameter<bool>("show_results", false);
        this->declare_parameter<bool>("show_debug", false);
        this->declare_parameter<std::string>("optimization_method", "polynomial");
        this->declare_parameter<double>("sampling_rate", 5.0);
        this->declare_parameter<bool>("show_downsampling", false);
        this->declare_parameter<bool>("show_interpolation", false);

        // Get parameters
        this->get_parameter("cost_values", cost_values_);
        this->get_parameter("step_sizes", step_sizes_);
        this->get_parameter("speed_limits", speed_limits_);
        this->get_parameter("show_feedback", show_feedback_);
        this->get_parameter("show_results", show_results_);
        this->get_parameter("show_debug", show_debug_);
        this->get_parameter("optimization_method", optimization_method_);
        this->get_parameter("sampling_rate", sampling_rate_);
        this->get_parameter("show_downsampling", show_downsampling_);
        this->get_parameter("show_interpolation", show_interpolation_);

        // Print parameters to verify
        RCLCPP_INFO(this->get_logger(), "Optimization method: %s", optimization_method_.c_str());
        RCLCPP_INFO(this->get_logger(), "Sampling rate: %.2f", sampling_rate_);
        RCLCPP_INFO(this->get_logger(), "Show Feedback: %s", show_feedback_ ? "True" : "False");

        red_cost_ = cost_values_[0];   red_step_ = step_sizes_[0];
        yellow_cost_ = cost_values_[1]; yellow_step_ = step_sizes_[1];
        green_cost_ = cost_values_[2];  green_step_ = step_sizes_[2];
        safe_cost_ = cost_values_[3];   safe_step_ = step_sizes_[3];

        // Subscription
        coast_subscription_ = this->create_subscription<user_action_interfaces::msg::CoastMsg>(
            "gps_coordinates_coast", 10,
            std::bind(&PathPlanningServer::coast_points_callback, this, std::placeholders::_1));

        // Publisher
        zones_dictionary_publisher_ = this->create_publisher<user_action_interfaces::msg::ZonesDictionaryEntry>(
            "zones_dictionary_cpp", 10);
        

        this->action_server_ = rclcpp_action::create_server<StartGoalAction>(
            this,
            "start_goal_client",
            std::bind(&PathPlanningServer::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&PathPlanningServer::handle_cancel, this, std::placeholders::_1),
            std::bind(&PathPlanningServer::handle_accepted, this, std::placeholders::_1));

        RCLCPP_INFO(this->get_logger(), "Path Planning Action Server is up!");

    }

private:
    rclcpp_action::Server<StartGoalAction>::SharedPtr action_server_;

    bool first_run_;  // Fix: Declare first_run_ as a private member
    // Member variables for parameters
    std::vector<double> cost_values_;
    std::vector<double> step_sizes_;
    std::vector<double> speed_limits_;
    bool show_feedback_;
    bool show_results_;
    bool show_debug_;
    std::string optimization_method_;
    double sampling_rate_;
    bool show_downsampling_;
    bool show_interpolation_;

    double red_cost_;
    double yellow_cost_;
    double green_cost_;
    double safe_cost_;

    double red_step_;
    double yellow_step_;
    double green_step_;
    double safe_step_;

    bool coast_data_received_;

    rclcpp::Subscription<user_action_interfaces::msg::CoastMsg>::SharedPtr coast_subscription_;
    rclcpp::Publisher<user_action_interfaces::msg::ZonesDictionaryEntry>::SharedPtr zones_dictionary_publisher_;

    double grid_size_;
    double size_x_, size_y_;
    std::vector<double> coordinates_ = {0.0, 0.0, 0.0, 0.0}; // min_x, min_y, max_x, max_y

    std::map<std::pair<double, double>, std::string> zones_dictionary_gps_;
    std::map<std::pair<int, int>, std::string> zones_dictionary_;

    // Handle incoming goal request (Action Server)
    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID &uuid,
        std::shared_ptr<const StartGoalAction::Goal> goal)
    {
        (void)uuid;

        // If coast data is not received, reject the goal
        if (!coast_data_received_)
        {
            RCLCPP_WARN(this->get_logger(), "Goal rejected: Coast data not received yet.");
            return rclcpp_action::GoalResponse::REJECT;
        }

        RCLCPP_INFO(this->get_logger(), "Goal accepted: Start [%.2f, %.2f] -> Goal [%.2f, %.2f]",
                    goal->start[0], goal->start[1], goal->goal[0], goal->goal[1]);

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    // Handle goal cancellation (Action Server)
    rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandle> goal_handle)
    {
        (void)goal_handle;
        RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    // Handle accepted goal (Action Server)
    void handle_accepted(const std::shared_ptr<GoalHandle> goal_handle)
    {
        std::thread{[this, goal_handle]() { execute(goal_handle); }}.detach();
    }

    // Execute goal (Action Server)
    void execute(const std::shared_ptr<GoalHandle> goal_handle)
    {
        RCLCPP_INFO(this->get_logger(), "Executing path planning...");

        // Wait for coast data if not received
        while (!coast_data_received_ && rclcpp::ok())
        {
            RCLCPP_WARN(this->get_logger(), "Waiting for coast data before planning path...");
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        auto feedback = std::make_shared<StartGoalAction::Feedback>();
        auto result = std::make_shared<StartGoalAction::Result>();

        //start point : start_gps, recive from goal_handle
        //goal point : goal_gps, recive from goal_handle
        auto start_gps = goal_handle->get_goal()->start;
        auto goal_gps = goal_handle->get_goal()->goal;

        RCLCPP_INFO(this->get_logger(), "Start point: [%.7f, %.7f]", start_gps[0], start_gps[1]);
        RCLCPP_INFO(this->get_logger(), "Goal point: [%.7f, %.7f]", goal_gps[0], goal_gps[1]);

        
        RCLCPP_INFO(this->get_logger(), "Coast data received. Starting path planning...");  
        //print coast dictionary

        for (int i = 0; i < 5; i++)
        {
            if (goal_handle->is_canceling())
            {
                RCLCPP_INFO(this->get_logger(), "Goal was canceled");
                goal_handle->canceled(result);
                return;
            }

            feedback->partial_path_x.push_back(i * 1.0);
            feedback->partial_path_y.push_back(i * 2.0);
            goal_handle->publish_feedback(feedback);
            rclcpp::sleep_for(std::chrono::milliseconds(500));
        }

        result->path_x = {0.0, 1.0, 2.0, 3.0, 4.0};
        result->path_y = {0.0, 2.0, 4.0, 6.0, 8.0};
        result->path_distance = 10.0;
        result->estimated_path_time = 5.0;

        RCLCPP_INFO(this->get_logger(), "Path computed successfully");
        goal_handle->succeed(result);
    }

    // Subscription callback (Receives data once)
    void coast_points_callback(const user_action_interfaces::msg::CoastMsg::SharedPtr msg)
    {
        if (!coast_data_received_)
        {
            RCLCPP_INFO(this->get_logger(), "Received coast points. Processing...");
            grid_size_ = msg->grid_size;

            std::vector<std::pair<double, double>> coast_points, red_zone, yellow_zone, green_zone, safe_zone;
            extract_zone_points(msg, coast_points, red_zone, yellow_zone, green_zone, safe_zone);

            make_zones_dictionary(coast_points, red_zone, yellow_zone, green_zone, safe_zone);

            // Mark data as received
            coast_data_received_ = true;

            // Unsubscribe (so it only runs once)
            coast_subscription_.reset();

            RCLCPP_INFO(this->get_logger(), "Coast data processed and subscription closed.");
        }
    }
    

    void extract_zone_points(
        const user_action_interfaces::msg::CoastMsg::SharedPtr &msg,
        std::vector<std::pair<double, double>> &coast_points,
        std::vector<std::pair<double, double>> &red_zone,
        std::vector<std::pair<double, double>> &yellow_zone,
        std::vector<std::pair<double, double>> &green_zone,
        std::vector<std::pair<double, double>> &safe_zone)
    {
        for (size_t i = 0; i < msg->coast_points_x.data.size(); ++i)
            coast_points.emplace_back(msg->coast_points_x.data[i], msg->coast_points_y.data[i]);

        for (size_t i = 0; i < msg->red_points_x.data.size(); ++i)
            red_zone.emplace_back(msg->red_points_x.data[i], msg->red_points_y.data[i]);

        for (size_t i = 0; i < msg->yellow_points_x.data.size(); ++i)
            yellow_zone.emplace_back(msg->yellow_points_x.data[i], msg->yellow_points_y.data[i]);

        for (size_t i = 0; i < msg->green_points_x.data.size(); ++i)
            green_zone.emplace_back(msg->green_points_x.data[i], msg->green_points_y.data[i]);

        for (size_t i = 0; i < msg->safe_points_x.data.size(); ++i)
            safe_zone.emplace_back(msg->safe_points_x.data[i], msg->safe_points_y.data[i]);
    }

    void make_zones_dictionary(
        const std::vector<std::pair<double, double>> &coast_points,
        const std::vector<std::pair<double, double>> &red_zone,
        const std::vector<std::pair<double, double>> &yellow_zone,
        const std::vector<std::pair<double, double>> &green_zone,
        const std::vector<std::pair<double, double>> &safe_zone)
    {
        for (const auto &point : safe_zone) zones_dictionary_gps_[point] = "s";
        for (const auto &point : green_zone) zones_dictionary_gps_[point] = "g";
        for (const auto &point : yellow_zone) zones_dictionary_gps_[point] = "y";
        for (const auto &point : red_zone) zones_dictionary_gps_[point] = "r";
        for (const auto &point : coast_points) zones_dictionary_gps_[point] = "c";

        //self coordinates from get_coordinates
        coordinates_ = get_coordinates(zones_dictionary_gps_);

        size_x_ = set_width();
        size_y_ = set_height();

        /*
        for (const auto &entry : zones_dictionary_gps_)
        //display the coordinates of the zones_dictionary_gps_
        {
            RCLCPP_INFO(this->get_logger(), "Key: (%f, %f), Value: %s", entry.first.first, entry.first.second, entry.second.c_str());
        }
        */

        for (const auto &entry : zones_dictionary_gps_)
        {
            auto new_key = adapt_coordinates(entry.first);
            zones_dictionary_[new_key] = entry.second;
        }
    }

    int set_width() {
        return static_cast<int>(std::round(gps_to_meters(coordinates_[1], coordinates_[0], coordinates_[1], coordinates_[2])));
    }

    int set_height() {
        return static_cast<int>(std::round(gps_to_meters(coordinates_[1], coordinates_[0], coordinates_[3], coordinates_[0])));
    }

    double gps_to_meters(double lat1, double lon1, double lat2, double lon2) {
        constexpr double R = 6378.137;
        double dLat = (lat2 - lat1) * M_PI / 180.0;
        double dLon = (lon2 - lon1) * M_PI / 180.0;

        double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
                   std::cos(lat1 * M_PI / 180.0) * std::cos(lat2 * M_PI / 180.0) *
                   std::sin(dLon / 2) * std::sin(dLon / 2);

        double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
        double d = R * c;
        return d * 1000.0;
    }

    std::pair<int, int> gps_to_pixel(double latitude, double longitude) {

        //show coordinates[0], coordinates[1], coordinates[2], coordinates[3]

        /* 
        RCLCPP_INFO(this->get_logger(), "Coordinates: [%f, %f, %f, %f]", coordinates_[0], coordinates_[1], coordinates_[2], coordinates_[3]);
        RCLCPP_INFO(this->get_logger(), "Latitude: %f, Longitude: %f", latitude, longitude);
        RCLCPP_INFO(this->get_logger(), "Size x: %f, Size y: %f", size_x_, size_y_);
        */

        int x_pixel = static_cast<int>(std::round((longitude - coordinates_[0]) * size_x_ / (coordinates_[2] - coordinates_[0])));
        int y_pixel = static_cast<int>(std::round((latitude - coordinates_[1]) * size_y_ / (coordinates_[3] - coordinates_[1])));

        //RCLCPP_INFO(this->get_logger(), "Pixel coordinates: (%d, %d)", x_pixel, y_pixel);

        x_pixel = std::round(x_pixel / grid_size_) * grid_size_;
        y_pixel = std::round(y_pixel / grid_size_) * grid_size_;


        //GRID_SIZE disp
        //RCLCPP_INFO(this->get_logger(), "Grid size: %f", grid_size_);

        // display the pixel coordinates
        //RCLCPP_INFO(this->get_logger(), "Pixel coordinates: (%d, %d)", x_pixel, y_pixel);

        return {x_pixel, y_pixel};
    }

    std::pair<int, int> adapt_coordinates(const std::pair<double, double> &coord) {
        auto new_coord = gps_to_pixel(coord.first, coord.second);
        return {std::round(new_coord.first / grid_size_), std::round(new_coord.second / grid_size_)};
    }

    std::vector<double> get_coordinates(const std::map<std::pair<double, double>, std::string>& zones_dictionary_gps)
    {
        std::vector<std::pair<double, double>> coordinates_list;
        
        // Extract keys (coordinates) from the map
        for (const auto& entry : zones_dictionary_gps)
        {
            coordinates_list.push_back(entry.first);
        }

        // Get the minimum and maximum values for x and y
        double min_x = std::min_element(coordinates_list.begin(), coordinates_list.end(),
                                        [](const std::pair<double, double>& a, const std::pair<double, double>& b) {
                                            return a.first < b.first;
                                        })->first;
                                        
        double min_y = std::min_element(coordinates_list.begin(), coordinates_list.end(),
                                        [](const std::pair<double, double>& a, const std::pair<double, double>& b) {
                                            return a.second < b.second;
                                        })->second;

        double max_x = std::max_element(coordinates_list.begin(), coordinates_list.end(),
                                        [](const std::pair<double, double>& a, const std::pair<double, double>& b) {
                                            return a.first < b.first;
                                        })->first;

        double max_y = std::max_element(coordinates_list.begin(), coordinates_list.end(),
                                        [](const std::pair<double, double>& a, const std::pair<double, double>& b) {
                                            return a.second < b.second;
                                        })->second;

        std::vector<double> result = {min_y, min_x, max_y, max_x};
        
        std::cout << "Coordinates: ["
                << result[0] << ", " << result[1] << ", "
                << result[2] << ", " << result[3] << "]" << std::endl;

        return result;
    }

    void publish_zones_dictionary() {
        // Create a message instance
        auto message = user_action_interfaces::msg::ZonesDictionaryEntry();
        
        // Clear any previous data in the arrays
        message.key_x.clear();
        message.key_y.clear();
        message.value.clear();
    
        // Loop through zones_dictionary_gps_ and populate the lists
        for (const auto &entry : zones_dictionary_) {
            // Assuming entry.first.first and entry.first.second represent coordinates
            message.key_x.push_back(entry.first.first);  // Add x-coordinate to the list
            message.key_y.push_back(entry.first.second); // Add y-coordinate to the list
    
            // Assuming entry.second is a string (or an iterable of strings)
            message.value.push_back(entry.second); // Add value to the list
        }
    
        // publish in inf loop
        // This will keep publishing the message every time it is called, so it will keep publishing the same data
        // until new data is received
        while (rclcpp::ok()) {
            zones_dictionary_publisher_->publish(message);
        }
        return;
    }
    
};    
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<user_action_interfaces::PathPlanningServer>());
    rclcpp::shutdown();
    return 0;
}