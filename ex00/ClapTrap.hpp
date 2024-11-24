#include <iostream>

class ClapTrap{
private:
	std::string _name;
	int         _hitPoints = 10;
	int         _energyPoints = 10;
	int         _attackDamage = 0;
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