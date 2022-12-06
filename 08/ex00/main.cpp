#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> v;
	std::list<int> l;
	for (int i = 1; i <= 100; ++i)
	{
		v.push_back(i);
		l.push_front(i);
	}
	std::cout << ">>> Testing Vectors <<<" << std::endl;
	std::cout << "finding 50: " << *easyfind(v, 50) << std::endl;
	std::cout << "finding 12: " << *easyfind(v, 12) << std::endl;
	std::cout << "finding 79: " << *easyfind(v, 79) << std::endl;

	std::cout << "finding 103: " << std::boolalpha << ((easyfind(v, 103) == v.end()) ? "Not found" : "Found") << std::endl;
	std::cout << "finding -3: " << std::boolalpha << ((easyfind(v, -3) == v.end()) ? "Not found" : "Found") << std::endl;
	std::cout << "finding 23: " << std::boolalpha << ((easyfind(v, 23) == v.end()) ? "Not found" : "Found") << std::endl;
	std::cout << "finding 10513: " << std::boolalpha << ((easyfind(v, 10513) == v.end()) ? "Not found" : "Found") << std::endl;
	std::cout << "finding 0: " << std::boolalpha << ((easyfind(v, 0) == v.end()) ? "Not found" : "Found") << std::endl;

	std::cout << ">>> Testing Lists <<<" << std::endl;
	std::cout << "finding 50: " << *easyfind(l, 50) << std::endl;
	std::cout << "finding 12: " << *easyfind(l, 12) << std::endl;
	std::cout << "finding 79: " << *easyfind(l, 79) << std::endl;

	std::cout << "finding 103: " << std::boolalpha << ((easyfind(l, 103) == l.end()) ? "Not found" : "Found") << std::endl;
	std::cout << "finding -3: " << std::boolalpha << ((easyfind(l, -3) == l.end()) ? "Not found" : "Found") << std::endl;
	std::cout << "finding 23: " << std::boolalpha << ((easyfind(l, 23) == l.end()) ? "Not found" : "Found") << std::endl;
	std::cout << "finding 10513: " << std::boolalpha << ((easyfind(l, 10513) == l.end()) ? "Not found" : "Found") << std::endl;
	std::cout << "finding 0: " << std::boolalpha << ((easyfind(l, 0) == l.end()) ? "Not found" : "Found") << std::endl;

}