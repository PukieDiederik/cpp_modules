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
	data d1 = {42, "Hello World!"};

	uintptr_t iptr = serialize(&d1);
	std::cout << d1.str << ", " << d1.i << std::endl;
	std::cout << std::hex << iptr << ", " << &d1 << ", " << std::dec << iptr << std::endl;
	data *d2 = deserialize(iptr);
	std::cout << d2 << ", " << d2->str << ", " << d2->i << std::endl;
	std::cout << &d2->str << ", " << &d1.str << std::endl;

}