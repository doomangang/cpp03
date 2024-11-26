#include "ScavTrap.hpp"

int main (void)
{
	std::cout << "-------------------------------------------------------------------" << "one" << " creation\n";
	ScavTrap scavOne = ScavTrap("one");
	std::cout << "-------------------------------------------------------------------" << "Default" << " creation\n";
	ScavTrap scavDefault = ScavTrap();
	std::cout << "-------------------------------------------------------------------" << "Two" << " creation\n";
	ScavTrap scavTwo = ScavTrap("two");
	std::cout << "-------------------------------------------------------------------" << "Copy" << " creation\n";
	ScavTrap scavCopy = scavTwo;

	std::cout << "\n-------------------------------------------------------------------" << "attack session\n";
	//	attack : one -> default
	std::cout << "-------------------------------------------------------------------" << "attack : one -> default" << std::endl;
	scavOne.attack("scavDefault");
	scavDefault.takeDamage(scavOne.getAttackDamage());
	// attack : default -> copy
	std::cout << "-------------------------------------------------------------------" << "attack : default -> copy" << std::endl;
	scavDefault.attack("scavCopy");
	scavCopy.takeDamage(scavDefault.getAttackDamage());
	// repair : copy
	std::cout << "-------------------------------------------------------------------" << "repair : copy" << std::endl;
	scavCopy.beRepaired(INT32_MAX);
	// attack : two -> default
	std::cout << "-------------------------------------------------------------------" << "attack : two -> default" << std::endl;
	scavTwo.attack("scavDefault");
	scavDefault.takeDamage(scavTwo.getAttackDamage());
	// repair : one
	std::cout << "-------------------------------------------------------------------" << "repair : one" << std::endl;
	scavOne.beRepaired(UINT32_MAX);
	// attack : one -> default
	std::cout << "-------------------------------------------------------------------" << "attack : one -> default" << std::endl;
	scavOne.attack("scavDefault");
	scavDefault.takeDamage(scavOne.getAttackDamage());
	// repair : default
	std::cout << "-------------------------------------------------------------------" << "repair : default" << std::endl;
	scavDefault.beRepaired(10);
	//scavDefault in Gate Keeper mode
	std::cout << "-------------------------------------------------------------------" << "scavDefault in Gate Keeper mode" << std::endl;;;
	scavDefault.guardGate();

	std::cout << "-------------------------------------------------------------------" << "session ended, Destructor called" << std::endl;;;

}