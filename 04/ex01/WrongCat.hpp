#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	// Constructors/Destructors
	WrongCat(); // default constructor
	WrongCat(const WrongCat& copy); // copy constructor

	~WrongCat(); // destructor

	// Operators
	WrongCat& operator=(const WrongCat& copy); //copy-assignment

	// Getters/Setters
	// Functions
	virtual void makeSound() const;
};


#endif
