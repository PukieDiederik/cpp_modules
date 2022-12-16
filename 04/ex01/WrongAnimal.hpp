#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
protected:
	std::string m_type;
public:
	// Constructors/Destructors
	WrongAnimal(); // default constructor
	WrongAnimal(const WrongAnimal& copy); // copy constructor

	virtual ~WrongAnimal(); // destructor

	// Operators
	WrongAnimal& operator=(const WrongAnimal& copy); //copy-assignment

	// Getters/Setters
	const std::string& getType() const;

	// Functions
	void makeSound() const;
};


#endif
