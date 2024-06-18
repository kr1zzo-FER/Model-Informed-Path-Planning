class Node:
    def __init__(self, coordinate=(0.0, 0.0), cost=0.0):
        self.coordinate = coordinate
        self.x = coordinate[0]
        self.y = coordinate[1]
        self.cost = cost
        self.goal = False

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __lt__(self, other):
        return (self.x, self.y) < (other.x, other.y)


def add_coordinates(node1: Node, node2: Node):
    return Node((node1.x + node2.x, node1.y + node2.y), node1.cost + node2.cost)


def compare_coordinates(node1: Node, node2: Node):
    return node1.x == node2.x and node1.y == node2.y
