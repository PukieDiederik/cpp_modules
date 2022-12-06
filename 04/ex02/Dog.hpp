#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
private:
	Brain* m_brain;
public:
	// Constructors/Destructors
	Dog(); // default constructor
	Dog(const Dog& copy); // copy constructor

	~Dog(); // destructor

	// Operators
	Dog& operator=(const Dog& copy); //copy-assignment

	// Getters/Setters
	Brain* getBrain();

	// Functions
	virtual void makeSound() const;
};

#endif
