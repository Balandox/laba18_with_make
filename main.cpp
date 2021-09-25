#include <iostream>
#include <string>
#include <map>
#include <list>
#include "Multimap.hpp"

int main() {
Multimap mul;
mul.insert("hello", 20);
mul.insert("hello", 30);
mul.insert("aaaa", 40);
mul.insert("avaa", 70);
mul.insert("aaja", 900);
std::cout << mul << std::endl;

try {
std::cout << "Testing erase function" << std::endl;
mul.show_keys();
std::string choose;
std::cout << "\nSelect a key: ";
std::cin >> choose;
mul.erase(choose);
std::cout << mul;
}
catch (std::exception& e) {
std::cerr << "Error: " << e.what() << std::endl;
}

try {
std::cout << "\nTesting find function: " << std::endl;
std::string choose;
std::list<int> l1;
std::list<int>::iterator itl = l1.begin();
std::cout << "\nInput a key to find: ";
std::cin >> choose;
l1 = mul.find(choose);
std::cout << choose << " values: ";
for (itl = l1.begin(); itl != l1.end(); ++itl)
std::cout << *itl << " ";
}
catch (std::exception& e) {
std::cerr << "Error: " << e.what() << std::endl;
}
return 0;
}