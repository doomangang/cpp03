#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Default Constructor Called\n";
	_name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy Constructor Called\n";
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called, " + _name + " is to be destroyed\n";
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called\n" + other.getName() + "'s to be copied";
	this->_name = other.getName();
	this->_hitPoints = other.getHitPoints();
	this->_energyPoints = other.getEnergyPoints();
	this->_attackDamage = other.getAttackDamage();
	return (*this);
}

void        ClapTrap::attack(const std::string& target)
{

}

void        ClapTrap::takeDamage(unsigned int amount);
void        ClapTrap::beRepaired(unsigned int amount);

std::string ClapTrap::getName()
{
	return (_name);
}

std::string ClapTrap::getHitPoints()
{
	return (_hitPoints);
}

std::string ClapTrap::getEnergyPoints()
{
	return (_energyPoints);
}

std::string ClapTrap::getAttackDamage()
{
	return (_attackDamage);
}