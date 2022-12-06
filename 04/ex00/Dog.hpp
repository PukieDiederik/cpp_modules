#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
private:

public:
	// Constructors/Destructors
	Dog(); // default constructor
	Dog(const Dog& copy); // copy constructor

	~Dog(); // destructor

	// Operators
	Dog& operator=(const Dog& copy); //copy-assignment

	// Getters/Setters
	// Functions
	virtual void makeSound() const;
};

#endif
