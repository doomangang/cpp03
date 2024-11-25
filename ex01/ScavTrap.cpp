#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20)
{
	std::cout << "ScavTrap Default Constructor Called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap " + name + " Constructor Called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
	std::cout << "ScavTrap Copy Constructor Called, " + other._name + "'s to be copied\n";
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called, " + _name + " is to be destroyed\n";
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy assignment operator called, " + other._name + "'s to be copied\n";
	if (*this != other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void    ScavTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0){
		std::cout << "ScavTrap" + _name + "is out of hit point or energy point, couldn't attack\n";
		return ;
	}
	std::cout << "ScavTrap " + _name + " attacks " + target + ", causing " + _attackDamage + " points of damage!\n";
	_energyPoints--;
}
void ScavTrap::guardGate();