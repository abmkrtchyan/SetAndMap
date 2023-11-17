#ifndef SET_MAP_COMPARE_H
#define SET_MAP_COMPARE_H

#include "Node.h"

struct Less {
    bool operator()(const Node &node1, const Node &node2) const {
        return node1.getValue() < node2.getValue();
    }
};

struct LessDisplay {
    int result = 0;

    bool operator()(const Node &node1, const Node &node2) {
        std::cout << node1.getValue() << " < " << node2.getValue() << std::endl;
        result += 1;
        return node1.getValue() < node2.getValue();
    }
};

class RuntimeCmp {
public:
    enum cmp_mode {
        normal, reverse
    };

private:
    cmp_mode mode;
public:
    RuntimeCmp(cmp_mode m = normal) : mode(m) {
    }

    template<typename T>
    bool operator()(const T &t1, const T &t2) const {
        return mode == normal ? t1 < t2
                              : t2 < t1;
    }

    bool operator==(const RuntimeCmp &rc) const {
        return mode == rc.mode;
    }
};

#endif //SET_MAP_COMPARE_H
