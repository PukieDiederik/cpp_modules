#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
private:

public:
	// Constructors/Destructors
	Cat(); // default constructor
	Cat(const Cat& copy); // copy constructor

	~Cat(); // destructor

	// Operators
	Cat& operator=(const Cat& copy); //copy-assignment

	// Getters/Setters
	// Functions
	virtual void makeSound() const;
};

#endif
