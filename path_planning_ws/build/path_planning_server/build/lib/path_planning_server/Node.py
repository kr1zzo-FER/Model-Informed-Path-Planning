class Node:
    def __init__(self, coordinate : tuple = (0.0,0.0), cost: float = 0.0):
        self.coordinate = coordinate
        self.x = coordinate[0]
        self.y = coordinate[1]
        self.cost = cost


def add_coordinates(node1: Node, node2: Node):
    new_node = Node()
    new_node.x = node1.x + node2.x
    new_node.y = node1.y + node2.y
    new_node.cost = node1.cost + node2.cost
    return new_node


def compare_coordinates(node1: Node, node2: Node):
    return node1.x == node2.x and node1.y == node2.y