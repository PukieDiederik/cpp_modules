#include <iostream>

int main(int argc, char** argv)
{
	// If this program has no arguments, it prints the following
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	// Loop over each argument
	for(int i = 1; i < argc; i++)
	{
		int	j = 0;
		// Loop over each letter
		while (argv[i][j] != '\0')
			std::cout << (char)std::toupper(argv[i][j++]);
	}
	// Finish with a newline
	std::cout << std::endl;
	return (0);
}
