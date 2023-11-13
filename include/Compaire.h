#ifndef SET_MAP_COMPARE_H
#define SET_MAP_COMPARE_H

#include "Node.h"

struct Less {
    bool operator()(const Node &node1, const Node &node2) const {
        return node1.getValue() < node2.getValue();
    }
};

struct LessDisplay {
    bool operator()(const Node &node1, const Node &node2) const {
        std::cout << node1.getValue() << " < " << node2.getValue() << std::endl;
        return node1.getValue() < node2.getValue();
    }
};

#endif //SET_MAP_COMPARE_H
