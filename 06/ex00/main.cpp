#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <limits>

void printNums(char c, int i, float f, double d, bool is_c_possible, bool is_i_possible
											   , bool is_f_possible, bool is_d_possible);
// Checking for input type
bool isChar(const std::string& str)
{
	return (str.length() == 1 && !std::isdigit(str[0]));
}

bool isInt(const std::string& str)
{
	std::string::size_type i = 0;

	if (str.length() == 0)
		return false;
	if (str[0] == '+' || str[0] == '-')
		++i;
	for (; i < str.length(); ++i)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

bool isFloat(const std::string& str)
{
	std::string::size_type i = 0;
	bool found_period = false;

	if (str.length() < 3)
		return false;
	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
		return true;
	if (str[0] == '+' || str[0] == '-')
		++i;
	for (; i < str.length() - 1; ++i)
	{
		if (found_period && str[i] == '.')
			return false;
		if (str[i] == '.')
			found_period = true;
		else if (!std::isdigit(str[i]))
			return false;
	}

	return (found_period && str[str.length() - 1] == 'f' && std::isdigit(str[str.length() - 2]));
}

bool isDouble(const std::string& str)
{
	std::string::size_type i = 0;
	bool found_period = false;

	if (str.length() < 2)
		return false;
	if (str[0] == '+' || str[0] == '-')
		++i;
	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
		return true;
	for (; i < str.length(); ++i)
	{
		if (found_period && str[i] == '.')
			return false;
		if (str[i] == '.')
			found_period = true;
		else if (!std::isdigit(str[i]))
			return false;
	}
	return (std::isdigit(str[str.length() - 1]) && found_period);
}

void printFromChar(const std::string& str)
{
	char c = str[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	printNums(c, i, f, d, true, true, true, true);
}

void printFromInt(const std::string& str)
{
	bool is_c_possible = true;
	char *end;

	// Need to use strtol here because otherwise I can't check for overflow. And there isn't a strtoi version for c++98
	int i = std::strtol(str.c_str(), &end, 10);
	if (end != str.c_str() + str.length() - 1)
	{
		printNums(0, 0, 0.0f, 0.0, false, false, false, false);
		return;
	}
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if (static_cast<int>(c) != i)
		is_c_possible = false;
	printNums(c, i, f, d, is_c_possible, true, true, true);
}

void printFromFloat(const std::string& str)
{
	bool is_c_possible = true;
	bool is_i_possible = true;
	char *end;


	float f = std::strtof(str.c_str(), &end);
	if (end != str.c_str() + str.length() - 1)
	{
		printNums(0, 0, 0.0f, 0.0, false, false, false, false);
		return;
	}

	char c = 0;
	int i = 0;
	if (std::isnan(f) || std::isinf(f))
	{
		is_c_possible = false;
		is_i_possible = false;
	}
	else
	{
		i = static_cast<int>(f);
		if (i != static_cast<long int>(f))
		{
			is_i_possible = false;
			is_c_possible = false;
		}
		if (is_i_possible)
		{
			c = static_cast<char>(f);
			if (c != i)
				is_c_possible = false;
		}
	}
	double d = static_cast<double>(f);

	printNums(c, i, f, d, is_c_possible, is_i_possible, true, true);
}

void printFromDouble(const std::string& str)
{
	bool is_c_possible = true;
	bool is_i_possible = true;
	char *end;


	double d = std::strtod(str.c_str(), &end);
	if (end != str.c_str() + str.length())
	{
		printNums(0, 0, 0.0f, 0.0, false, false, false, false);
		return;
	}

	char c = 0;
	int i = 0;
	if (std::isnan(d) || std::isinf(d))
	{
		is_c_possible = false;
		is_i_possible = false;
	}
	else
	{
		i = static_cast<int>(d);
		if (i != static_cast<long int>(d))
		{
			is_i_possible = false;
			is_c_possible = false;
		}
		if (is_c_possible)
		{
			c = static_cast<char>(d);
			if (c != i)
				is_c_possible = false;
		}
	}
	float f = static_cast<float>(d);

	printNums(c, i, f, d, is_c_possible, is_i_possible, true, true);
}

// Converting and printing
void printNums(char c, int i, float f, double d, bool is_c_possible, bool is_i_possible
			   								   , bool is_f_possible, bool is_d_possible)
{
	// Chars
	if (!is_c_possible)
		std::cout << "char: Impossible conversion" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Not printable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;

	// Ints
	if (!is_i_possible)
		std::cout << "int: Impossible conversion" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	// floats
	if (!is_f_possible)
		std::cout << "float: Impossible conversion" << std::endl;
	else if (std::isnan(f) || std::isinf(f) || f - static_cast<int>(f) == 0.0f)
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(4) << "float: " << f << "f" << std::endl;

	// Doubles
	if (!is_d_possible)
		std::cout << "double: Impossible conversion" << std::endl;
	else if (std::isnan(d) || std::isinf(d))
		std::cout << "float: " << d << std::endl;
	else if (d - static_cast<int>(d) == 0.0f)
		std::cout << std::fixed << std::setprecision(1) << "float: " << d << std::endl;
	else
		std::cout << std::fixed << std::setprecision(4) << "float: " << d << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "invalid amount of arguments\n";
		return 1;
	}

	if (isChar(argv[1])) { printFromChar(argv[1]); }
	else if (isInt(argv[1])) { printFromInt(argv[1]); }
	else if(isFloat(argv[1])) { printFromFloat(argv[1]); }
	else if(isDouble(argv[1])) { printFromDouble(argv[1]); }
	else
		std::cerr << "Could not figure out the type\n";
}