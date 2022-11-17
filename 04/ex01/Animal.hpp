#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
	std::string m_type;

public:
	// Constructors/Destructors
	Animal(); // default constructor
	Animal(const Animal& copy); // copy constructor

	virtual ~Animal(); // destructor

	// Operators
	Animal& operator=(const Animal& copy); //copy-assignment

	// Getters/Setters
	const std::string& getType() const;

	// Functions
	virtual void makeSound() const;
};

#endif
