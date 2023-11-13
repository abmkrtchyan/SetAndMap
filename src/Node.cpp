#include "Node.h"

Node::Node(int val, int weight) : val(val), weight(weight) {}

void Node::print() const {
    std::cout << "Value is: " << this->val << "Weight is: " << this->weight << std::endl;
}

bool Node::operator<(const Node &other) const {
    return this->val < other.val;
}

bool Node::operator>(const Node &other) const {
    return this->val > other.val;
}

