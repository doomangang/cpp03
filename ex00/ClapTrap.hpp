#include <iostream>

class ClapTrap{
private:
	std::string _name;
	int         _hitPoints;
	int         _energyPoints;
	int         _attackDamage;
public:
	ClapTrap(std::string);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();
	ClapTrap&   operator=(const ClapTrap& other);
	void        attack(const std::string& target);
	void        takeDamage(unsigned int amount);
	void        beRepaired(unsigned int amount);

	//getter
	std::string getName();
	std::string getHitPoints();
	std::string getEnergyPoints();
	std::string getAttackDamage();
};

/*
 * Attack : target loses <attack damage> hit points
 * Repair : <amount> hit points back
 * Energy point : costs 1 by each attacking and repairing
 * Can't do anything if no Hit Point or energy points left
 */