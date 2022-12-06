#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
private:
	std::string m_ideas[100];
public:
	// Constructors/Destructors
	Brain(); // default constructor
	Brain(const Brain& copy); // copy constructor

	~Brain(); // destructor

	// Operators
	Brain& operator=(const Brain& copy); //copy-assignment

	// Getters/Setters
	std::string* getIdea(unsigned int index);
	void setIdea(unsigned int index, const std::string& idea);

	// Functions
};

#endif
