#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0)
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
	std::cout << "Copy assignment operator called\n" + other.getName() + "'s to be copied\n";
	if (*this != other)
	{
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

void        ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0){
		std::cout << "ClapTrap" + _name + "is out of hit point or energy point, couldn't attack\n";
		return ;
	}
	std::cout << "ClapTrap " + _name + " attacks " + target + ", causing " + _attackDamage + " points of damage!\n";
	_energyPoints--;
}

void        ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " + _name + "took damage, losing " + amount + " amount of hit points\n";
	if (_hitPoints < INT32_MIN + amount)
		_hitPoints = INT32_MIN;
	else
		_hitPoints -= amount;
}
void        ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints <= 0){
		std::cout << "ClapTrap " + _name + "is out of hit point or energy point, couldn't be repaired\n";
		return ;
	}
	std::cout << "ClapTrap " + _name + "has been repaired " + amount + " amount of hit points\n";
	_energyPoints--;
	if (_hitPoints > INT32_MAX - amount)
		_hitPoints = INT32_MAX;
	else
		_hitPoints += amount;
}

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
