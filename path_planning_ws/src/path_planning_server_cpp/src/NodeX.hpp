#ifndef NODEX_HPP
#define NODEX_HPP

#include <utility>

class NodeX{
public:
    NodeX(std::pair<double, double> coordinate = {0.0, 0.0}, double cost = 0.0)
        : coordinate(coordinate), x(coordinate.first), y(coordinate.second), cost(cost), goal(false) {}

    bool operator==(const NodeX& other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const NodeX& other) const {
        return std::tie(x, y) < std::tie(other.x, other.y);
    }

    std::pair<double, double> coordinate;
    double x;
    double y;
    double cost;
    bool goal;
};

NodeX add_coordinates(const NodeX& node1, const NodeX& node2) {
    return NodeX({node1.x + node2.x, node1.y + node2.y}, node1.cost + node2.cost);
}

bool compare_coordinates(const NodeX& node1, const NodeX& node2) {
    return node1.x == node2.x && node1.y == node2.y;
}

#endif // NODEX_HPP
