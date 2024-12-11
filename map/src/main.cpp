#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include "Node.h"
#include "Compaire.h"

void test1() {
    std::cout << "________________Test1_________________" << std::endl;
    std::map<int, int> intMap;

    intMap[42] = 1;
    intMap[15] = 2;
    intMap[15] = 3;
    intMap[30] = 4;
    intMap[10] = 5;

    std::cout << "Elements in the map:";
    for (const auto &element: intMap) {
        std::cout << " " << element.first;
    }
    std::cout << std::endl;

    intMap.erase(15);

    if (intMap.empty()) {
        std::cout << "The map is empty." << std::endl;
    } else {
        std::cout << "The map is not empty." << std::endl;

        auto findIt = intMap.find(30);
        if (findIt != intMap.end()) {
            std::cout << "Element 30 found in the map." << std::endl;
        } else {
            std::cout << "Element 30 not found in the map." << std::endl;
        }
    }

    std::cout << "Size of the map: " << intMap.size() << std::endl;

    intMap.clear();

    std::map<int, int> anotherMap = {{5,  1},
                                     {8,  1},
                                     {12, 1}};
    intMap.swap(anotherMap);

    std::cout << "Elements in the map after swapping:";
    for (const auto &element: intMap) {
        std::cout << " " << element.first;
    }
    std::cout << std::endl;
    std::cout << "______________________________________" << std::endl;
}

void test2() {
    std::cout << "________________Test2_________________" << std::endl;
    std::map<int, Node, std::greater<>> map_apple;

    map_apple.insert(std::make_pair(3, Node(3, 250)));
    map_apple[8] = Node(3, 250);
    map_apple[1] = Node(1, 350);
    map_apple[2] = Node(2, 100);

    for (const auto &it: map_apple) {
        it.second.print();
    }
    std::cout << "______________________________________" << std::endl;
}

void test3() {
    std::cout << "________________Test3_________________" << std::endl;
    std::map<int, Node, Less> map_apple;

    map_apple[3] = Node(3, 250);
    map_apple[1] = Node(1, 350);
    map_apple[2] = Node(2, 100);

    for (const auto &it: map_apple) {
        it.second.print();
    }
    std::cout << "______________________________________" << std::endl;
}

void test4() {
    std::cout << "________________Test4_________________" << std::endl;
    std::map<int, Node, LessDisplay> map_apple;

    map_apple[3] = Node(3, 250);
    map_apple[1] = Node(1, 350);
    map_apple[2] = Node(2, 100);

    for (const auto &it: map_apple) {
        it.second.print();
    }
    std::cout << "______________________________________" << std::endl;
}

void test5() {
    std::cout << "________________Test5_________________" << std::endl;
    std::map<int, int, std::greater<>> intMap = {{50, 1},
                                                 {40, 1},
                                                 {30, 1},
                                                 {30, 1},
                                                 {20, 1},
                                                 {10, 1}};

    std::cout << "Elements in the map:";
    for (const auto &element: intMap) {
        std::cout << " " << element.first;
    }
    std::cout << std::endl;

    auto lower = intMap.lower_bound(30);
    if (lower != intMap.end()) {
        std::cout << "Lower Bound of 30: " << lower->first << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    auto upper = intMap.upper_bound(30);
    if (upper != intMap.end()) {
        std::cout << "Upper Bound of 30: " << upper->first << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    std::cout << "______________________________________" << std::endl;

    auto equalRange = intMap.equal_range(30);
    auto count = std::distance(equalRange.first, equalRange.second);
    std::cout << "Occurrences of 30: " << count << std::endl;
    std::cout << "______________________________________" << std::endl;
}

void test6() {
    std::cout << "________________Test6_________________" << std::endl;
    std::map<int, int, std::greater<>> intMap = {{50, 1},
                                                 {40, 1},
                                                 {30, 1},
                                                 {30, 1},
                                                 {20, 1},
                                                 {10, 1}};

    auto greaterLambda = [](int a, int b) { return a > b; };

    auto occurrences = std::count_if(intMap.begin(), intMap.end(), [value = 30, greaterLambda](const auto &element) {
        return !greaterLambda(value, element.first) && !greaterLambda(element.first, value);
    });

    std::cout << "Occurrences of 30: " << occurrences << std::endl;
    std::cout << "______________________________________" << std::endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();

    return 0;
}