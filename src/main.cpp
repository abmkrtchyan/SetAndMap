#include <iostream>
#include <set>
#include "Node.h"
#include "Compaire.h"

int main() {
    Node apple_1(3, 250);
    Node apple_2(1, 350);
    Node apple_3(2, 100);
    std::set<Node, LessDisplay> set_apple;
    set_apple.insert(apple_1);
    set_apple.insert(apple_2);
    set_apple.insert(apple_3);
    for (auto it: set_apple) {
        it.print();
    }
}
/* 1.
	std::set<int> set;
	set.insert(5);
	set.insert(9);
	set.insert(7);
	set.insert(4);
	set.insert(15);
	set.insert(15);
	for (auto it : set)
	{
		std::cout << it << " ";
	}
	std::cout << "\n";
	set.erase(4);
	set.erase(15);
	set.erase(10);

	for (auto it : set)
	{
		std::cout << it << " ";
	}
	std::cout << "\n";
	auto find1 = set.find(9);
	auto find2 = set.find(15);
	if(find2 != set.end())
	std::cout << *find2 << std::endl;
	//std::cout << *set.find(15) << std::endl;
	*/

/* 2.
    Node apple_1(3, 250);
    Node apple_2(1, 350);
    Node apple_3(2, 100);
    std::set<Node, std::greater<>> set_apple;
    set_apple.insert(apple_1);
    set_apple.insert(apple_2);
    set_apple.insert(apple_3);
    for (auto it: set_apple) {
        it.print();
    }

/* 3.
    Node apple_1(3, 250);
    Node apple_2(1, 350);
    Node apple_3(2, 100);
    std::set<Node, Less> set_apple;
    set_apple.insert(apple_1);
    set_apple.insert(apple_2);
    set_apple.insert(apple_3);
    for (auto it: set_apple) {
        it.print();
    }
    */