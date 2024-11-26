#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default", 100, 100, 30)
{
	std::cout << "FragTrap Default Constructor Called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap " + name + " Constructor Called\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other._name, other._hitPoints, other._energyPoints, other._attackDamage)
{
	std::cout << "FragTrap Copy Constructor Called, " + other._name + "'s to be copied\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor Called, " + _name + " is to be destroyed\n";
}

FragTrap&   FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap Copy assignment operator called, " + other._name + "'s to be copied\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void    FragTrap::highFivesGuys()
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
		std::cout << "FragTrap " + _name + " is out of hit point or energy point, cannot do anything\n";
	else
		std::cout << "FragTrap " + _name + " requesting a positive high fives\n";
	printStatus();
}