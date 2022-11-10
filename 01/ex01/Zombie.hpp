#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string m_name;

public:
	// Constructors/Destructors
	Zombie();
	Zombie(std::string& name);
	~Zombie();

	// Getters/Setters
	void setName(std::string new_name);
	void announce() const;
};


#endif //ZOMBIE_HPP
