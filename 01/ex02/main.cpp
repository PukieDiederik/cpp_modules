#include <iostream>
#include <string>

int main()
{
	std::string s = "HI THIS IS BRAIN";
	std::string* stringPTR = &s;
	std::string& stringREF = s;

	std::cout << "S adress           : " << &s << std::endl;
	std::cout << "S pointer address  : " << stringPTR << std::endl;
	std::cout << "S reference address: " << &stringREF << std::endl;

	std::cout << "---\n";

	std::cout << "S value            : " << s << std::endl;
	std::cout << "S pointer value    : " << *stringPTR << std::endl;
	std::cout << "S pointer reference: " << stringREF << std::endl;
}