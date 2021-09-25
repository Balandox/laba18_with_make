#ifndef _MULTIMAP_HPP_
#define _MULTIMAP_HPP_
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <exception>
#include <stdexcept>

class Multimap {
private:
std::map<const std::string, std::list <int>> node;
public:

void insert(const std::string& key, int val) {
std::map<std::string, std::list <int>> ::iterator it = this->node.begin();
it = this->node.find(key);
if (it == this->node.end()) {
std::list <int> l1 = { val };
this->node.insert(make_pair(key, l1));
}
else
it->second.push_back(val);
}

friend std::ostream& operator << (std::ostream& out, const Multimap& mul) {
if (mul.node.empty())
std::cout << "Multimap is empty!";
else {
std::cout << "Multimap content: " << std::endl;
std::map<const std::string, std::list <int>> ::const_iterator it = mul.node.begin();
std::list<int>::const_iterator itl = it->second.begin();
for (; it != mul.node.end(); ++it) {
std::cout << it->first << ": ";
for (itl = it->second.begin(); itl != it->second.end(); ++itl)
std::cout << *itl << " ";
std::cout << '\n';
}
}
return out;
}

void erase(const std::string& key) {
std::map<const std::string, std::list <int>> ::iterator it = this->node.begin();
it = node.find(key);
if (it == node.end()) {
std::out_of_range e("This key not found!");
throw e;
}
if (it->second.size() > 1)
it->second.pop_back();
else
node.erase(it);
}

void show_keys() {
std::map<const std::string, std::list <int>> ::iterator it = this->node.begin();
std::cout << "List of Multimap keys: " << std::endl;
if (it != this->node.end())
while (it != this->node.end()) {
std::cout << it->first << std::endl;
++it;
}
else
std::cout << "Multimap is empty!";
}

const std::list<int>& find(const std::string& key) {
std::map<const std::string, std::list <int>> ::iterator it = this->node.begin();
it = this->node.find(key);
if (it == this->node.end()) {
std::out_of_range e("This key not found!");
throw e;
}
else
return it->second;
}

}; 
#endif