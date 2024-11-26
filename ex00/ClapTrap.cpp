#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default Constructor Called\n";
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " + name + " Constructor Called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy Constructor called, " + other._name + "'s to be copied\n";
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called, " + _name + " is to be destroyed\n";
}

ClapTrap&   ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy assignment operator called, " + other._name + "'s to be copied\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void        ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0){
		std::cout << "ClapTrap " + _name + " is out of hit point or energy point, couldn't attack\n";
		return ;
	}
	std::cout << "ClapTrap " + _name + " attacks " + target + ", causing " << _attackDamage << " points of damage!\n";
	_energyPoints--;
	printStatus();
}

void        ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " + _name + " took damage, losing " << amount << " amount of hit points\n";
	if (_hitPoints < static_cast<int>(-2147483648 + amount))
		_hitPoints = -2147483648;
	else
		_hitPoints -= amount;
	printStatus();
}

void        ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints <= 0){
		std::cout << "ClapTrap " + _name + " is out of hit point or energy point, couldn't be repaired\n";
		return ;
	}
	std::cout << "ClapTrap " + _name + " has been repaired " << amount << " amount of hit points\n";
	_energyPoints--;
	if (_hitPoints > static_cast<int>(2147483647 - amount))
		_hitPoints = 2147483647;
	else
		_hitPoints += amount;
	printStatus();
}

void    ClapTrap::printStatus(void) {
	std::cout << "--------------\n" \
				<< _name + "'s status:\n" \
				<< "hp:\t" << _hitPoints << std::endl \
				<< "ep:\t" << _energyPoints << std::endl \
				<< "--------------\n";
}