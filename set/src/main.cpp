#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include "Node.h"
#include "Compaire.h"

void test1() {
    std::cout << "________________Test1_________________" << std::endl;
    std::set<int> intSet;

    auto insertResult = intSet.insert(42);
    std::cout << "Insert " << *insertResult.first << ": " << (insertResult.second ? "True" : "False") << std::endl;
    insertResult = intSet.insert(15);
    std::cout << "Insert " << *insertResult.first << ": " << (insertResult.second ? "True" : "False") << std::endl;
    insertResult = intSet.insert(15);
    std::cout << "Insert " << *insertResult.first << ": " << (insertResult.second ? "True" : "False") << std::endl;
    insertResult = intSet.insert(30);
    std::cout << "Insert " << *insertResult.first << ": " << (insertResult.second ? "True" : "False") << std::endl;
    insertResult = intSet.insert(10);
    std::cout << "Insert " << *insertResult.first << ": " << (insertResult.second ? "True" : "False") << std::endl;

    std::cout << "Elements in the set:";
    for (const auto &element: intSet) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    auto eraseResult = intSet.erase(15);
    std::cout << "Erase 15: " << (eraseResult ? "True" : "False") << std::endl;
    eraseResult = intSet.erase(15);
    std::cout << "Erase 15: " << (eraseResult ? "True" : "False") << std::endl;

    if (intSet.empty()) {
        std::cout << "The set is empty." << std::endl;
    } else {
        std::cout << "The set is not empty." << std::endl;

        auto findIt = intSet.find(30);
        if (findIt != intSet.end()) {
            std::cout << "Element 30 found in the set." << std::endl;
        } else {
            std::cout << "Element 30 not found in the set." << std::endl;
        }
    }

    std::cout << "Size of the set: " << intSet.size() << std::endl;

    intSet.clear();

    std::set<int> anotherSet = {5, 8, 12};
    intSet.swap(anotherSet);

    std::cout << "Elements in the set after swapping:";
    for (const auto &element: intSet) {
        std::cout << " " << element;
    }
    std::cout << std::endl;
    std::cout << "______________________________________" << std::endl;
}

void test2() {
    std::cout << "________________Test2_________________" << std::endl;
    Node apple_1(3, 250);
    Node apple_2(1, 350);
    Node apple_3(2, 100);
    std::set<Node, std::greater<>> set_apple;
    set_apple.insert(apple_1);
    set_apple.insert(apple_2);
    set_apple.insert(apple_3);
    for (const auto &it: set_apple) {
        it.print();
    }
    std::cout << "______________________________________" << std::endl;
}

void test3() {
    std::cout << "________________Test3_________________" << std::endl;
    Node apple_1(3, 250);
    Node apple_2(1, 350);
    Node apple_3(2, 100);
    std::set<Node, Less> set_apple;
    set_apple.insert(apple_1);
    set_apple.insert(apple_2);
    set_apple.insert(apple_3);
    for (const auto &it: set_apple) {
        it.print();
    }
    std::cout << "______________________________________" << std::endl;
}

void test4() {
    std::cout << "________________Test4_________________" << std::endl;
    Node apple_1(3, 250);
    Node apple_2(1, 350);
    Node apple_3(2, 100);
    std::set<Node, LessDisplay> set_apple;
    set_apple.insert(apple_1);
    set_apple.insert(apple_2);
    set_apple.insert(apple_3);
    for (const auto &it: set_apple) {
        it.print();
    }
    auto foundApple = set_apple.upper_bound(apple_2);
    if (foundApple != set_apple.end()) {
        std::cout << (*foundApple).getValue() << std::endl;
    } else {
        std::cout << "Not found!!" << std::endl;
    }

    std::cout << "______________________________________" << std::endl;
}

void test5() {
    std::cout << "________________Test5_________________" << std::endl;
    std::set<int, std::greater<>> intSet = {50, 40, 30, 30, 20, 10};

    // Print elements in the set
    std::cout << "Elements in the set:";
    for (const auto &element: intSet) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    // Lower Bound with Lambda
    auto lower = intSet.lower_bound(30);
    if (lower != intSet.end()) {
        std::cout << "Lower Bound of 30: " << *lower << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    // Upper Bound with Lambda
    auto upper = intSet.upper_bound(30);
    if (upper != intSet.end()) {
        std::cout << "Upper Bound of 30: " << *upper << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }
    std::cout << "______________________________________" << std::endl;

    auto equalRange = intSet.equal_range(30);
    std::count(equalRange.first, equalRange.second, 30);
    std::cout << "______________________________________" << std::endl;
}

void test6() {
    std::cout << "________________Test6_________________" << std::endl;
    auto lambdaCompare = [](int a, int b) { return a > b; };
    std::set<int, std::function<bool(int, int)>> set1(lambdaCompare);
    set1 = {50, 40, 30, 30, 20, 10};
    auto key_comp = set1.key_comp(); // key_comp(key1, key2)
    auto value_comp = set1.value_comp();
    std::set<int, std::function<bool(int, int)>> set2(lambdaCompare);
    set2 = {40, 50, 30, 30, 10, 20, 10};
    std::cout << "set1 ==  set2: " << (set1 == set2 ? "True" : "False") << std::endl;

    set1 = {10, 20, 30, 50, 60};
    set2 = {10, 20, 40, 50};
    std::cout << "set1 <  set2: " << (set1 < set2 ? "True" : "False") << std::endl;

    auto greaterLambda = [](int a, int b) { return a > b; };
    // Counting Occurrences with Lambda
    auto occurrences = std::count_if(set1.begin(), set1.end(), [value = 30, greaterLambda](int element) {
        return !greaterLambda(value, element) && !greaterLambda(element, value);
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