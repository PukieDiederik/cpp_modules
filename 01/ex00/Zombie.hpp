#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
	std::string m_name;

public:
	// Constructors/Destructors
	Zombie(std::string& name);
	~Zombie();

	void announce() const;
};


#endif //ZOMBIE_HPP
