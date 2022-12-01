#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal {
protected:
	std::string m_type;

	// Constructors/Destructors
	AAnimal(); // default constructor
	AAnimal(const AAnimal& copy); // copy constructor

public:
	// Constructors/Destructors
	virtual ~AAnimal(); // destructor

	// Operators
	AAnimal& operator=(const AAnimal& copy); //copy-assignment

	// Getters/Setters
	const std::string& getType() const;

	// Functions
	virtual void makeSound() const = 0;
};

#endif
