#ifndef SET_MAP_NODE_H
#define SET_MAP_NODE_H


#include <iostream>

class Node {
private:
    int val;
    int weight;

public:
    Node(int val = 0, int weight = 0);

    Node(const Node &);

    int getValue() const;

    void print() const;

    bool operator<(const Node &other) const;

    bool operator>(const Node &other) const;
};


#endif //SET_MAP_NODE_H
