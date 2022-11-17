#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
private:
	Brain* m_brain;
public:
	// Constructors/Destructors
	Cat(); // default constructor
	Cat(const Cat& copy); // copy constructor

	~Cat(); // destructor

	// Operators
	Cat& operator=(const Cat& copy); //copy-assignment

	// Getters/Setters
	Brain* getBrain();
	// Functions
	virtual void makeSound() const;
};

#endif
