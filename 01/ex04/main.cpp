#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "invalid args, expected: ./minised filename string_to_find string_to_replace\n";
		return (1);
	}
	//setup files
	std::ifstream in;
	in.open(argv[1]);
	if (!in.is_open())
	{
		std::cerr << "could not open input file\n";
		return (1);
	}
	std::ofstream out;
	out.open((static_cast<std::string>(argv[1]) + ".replace").c_str());
	if (!out.is_open())
	{
		in.close();
		std::cerr << "could not open output file\n";
		return (1);
	}

	std::string s;
	std::string needle = argv[2];
	std::string replace = argv[3];
	while (std::getline(in, s))
	{
		std::string::size_type n;
		n = s.find(needle, 0);
		while (n != std::string::npos)
		{
			s = s.substr(0, n) + replace + s.substr(n + needle.length());
			n = s.find(needle, n + replace.length());
		}
		out << s << '\n';
	}
	in.close();
	out.close();
}
