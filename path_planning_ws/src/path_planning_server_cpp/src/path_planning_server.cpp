#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <utility>
#include <limits>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "user_action_interfaces/msg/coast_msg.hpp"
#include "user_action_interfaces/action/start_goal_action.hpp"
#include "user_action_interfaces/msg/zones_dictionary_entry.hpp"

class PathPlanningServer : public rclcpp::Node
{
public:
    using StartGoalAction = user_action_interfaces::action::StartGoalAction;
    using GoalHandle = rclcpp_action::ServerGoalHandle<StartGoalAction>;

    explicit PathPlanningServer(const rclcpp::NodeOptions &options = rclcpp::NodeOptions())
        : Node("path_planning_server", options), first_run_(true)
    {
        RCLCPP_INFO(this->get_logger(), "Path planning server started");

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
    }

private:
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

    rclcpp::Subscription<user_action_interfaces::msg::CoastMsg>::SharedPtr coast_subscription_;
    rclcpp::Publisher<user_action_interfaces::msg::ZonesDictionaryEntry>::SharedPtr zones_dictionary_publisher_;

    double grid_size_;
    double size_x_, size_y_;
    std::vector<double> coordinates_ = {0.0, 0.0, 0.0, 0.0}; // min_x, min_y, max_x, max_y

    std::map<std::pair<double, double>, std::string> zones_dictionary_gps_;
    std::map<std::pair<int, int>, std::string> zones_dictionary_;

    void coast_points_callback(const user_action_interfaces::msg::CoastMsg::SharedPtr msg)
    {
        if (first_run_)
        {
            RCLCPP_INFO(this->get_logger(), "Processing coast points...");
            first_run_ = false;
            grid_size_ = msg->grid_size;

            std::vector<std::pair<double, double>> coast_points, red_zone, yellow_zone, green_zone, safe_zone;
            extract_zone_points(msg, coast_points, red_zone, yellow_zone, green_zone, safe_zone);
            
            //print coast_points
            RCLCPP_INFO(this->get_logger(), "Coast points:");
            for (const auto &point : coast_points)
                RCLCPP_INFO(this->get_logger(), "(%f, %f)", point.first, point.second);

            make_zones_dictionary(coast_points, red_zone, yellow_zone, green_zone, safe_zone);

            size_x_ = set_width();
            size_y_ = set_height();

            //pubslih log
            RCLCPP_INFO(this->get_logger(), "Zones dictionary published");
            publish_zones_dictionary();

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

        for (const auto &entry : zones_dictionary_gps_)
        //display the coordinates of the zones_dictionary_gps_
        {
            RCLCPP_INFO(this->get_logger(), "Key: (%f, %f), Value: %s", entry.first.first, entry.first.second, entry.second.c_str());
        }

        //for (const auto &entry : zones_dictionary_gps_)
        //{
        //    auto new_key = adapt_coordinates(entry.first);
        //    zones_dictionary_[new_key] = entry.second;
        //}
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
        int x_pixel = static_cast<int>(std::round((longitude - coordinates_[0]) * size_x_ / (coordinates_[2] - coordinates_[0])));
        int y_pixel = static_cast<int>(std::round((latitude - coordinates_[1]) * size_y_ / (coordinates_[3] - coordinates_[1])));

        x_pixel = std::round(x_pixel / grid_size_) * grid_size_;
        y_pixel = std::round(y_pixel / grid_size_) * grid_size_;

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
        for (const auto &entry : zones_dictionary_gps_) {
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

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PathPlanningServer>());
    rclcpp::shutdown();
    return 0;
}