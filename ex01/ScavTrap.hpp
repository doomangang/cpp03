#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap();
	ScavTrap&   operator=(const ScavTrap& other);
	void        attack(const std::string& target);
	void        guardGate();
};

#endif

/*
 * inherit the constructors and destructor from Clap- Trap
 * constructors, destructor and attack() will print different messages.
 * ClapTraps are aware of their individuality.
 * */