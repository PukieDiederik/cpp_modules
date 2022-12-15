#include <iostream>
#include <stdint.h>
#include <string>
#include "Data.hpp"

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
int main()
{
	int i = 42;
	Data d(&i);
	uintptr_t serialized;

	std::cout << "d original v    : " << *reinterpret_cast<int*>(d.getData()) << std::endl;
	std::cout << "d pointer       : " << &d << std::endl;
	serialized = serialize(&d);
	std::cout << "d serialized    : " << std::showbase << std::hex << serialized
									  << std::dec << ", " << serialized << std::endl;
	std::cout << "d deserialized v: " << *reinterpret_cast<int*>(deserialize(serialized)->getData()) << std::endl;

	std::string s = "Hello World!";
	d = Data(&s);

	std::cout << "\n---\n" << std::endl;

	std::cout << "d original v    : " << *reinterpret_cast<std::string*>(d.getData()) << std::endl;
	std::cout << "d pointer       : " << &d << std::endl;
	serialized = serialize(&d);
	std::cout << "d serialized    : " << std::showbase << std::hex << serialized
			 						  << std::dec << ", " << serialized << std::endl;
	std::cout << "d deserialized v: " << *reinterpret_cast<std::string*>(deserialize(serialized)->getData())
			  << std::endl;


}