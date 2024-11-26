#include "FragTrap.hpp"

int main (void)
{
	std::cout << "-------------------------------------------------------------------" << "one" << " creation\n";
	FragTrap fragOne = FragTrap("one");
	std::cout << "-------------------------------------------------------------------" << "Default" << " creation\n";
	FragTrap fragDefault = FragTrap();
	std::cout << "-------------------------------------------------------------------" << "Two" << " creation\n";
	FragTrap fragTwo = FragTrap("two");
	std::cout << "-------------------------------------------------------------------" << "Copy" << " creation\n";
	FragTrap fragCopy = fragDefault;

	std::cout << "\n-------------------------------------------------------------------" << "attack session\n";
	//	attack : one -> copy
	std::cout << "-------------------------------------------------------------------" << "attack : one -> copy" << std::endl;
	fragOne.attack("fragCopy");
	fragCopy.takeDamage(fragOne.getAttackDamage());
	// repair : copy
	std::cout << "-------------------------------------------------------------------" << "repair : copy" << std::endl;
	fragCopy.beRepaired(1);
	//	attack : copy -> one
	std::cout << "-------------------------------------------------------------------" << "attack : copy -> one" << std::endl;
	fragCopy.attack("fragOne");
	fragOne.takeDamage(fragCopy.getAttackDamage());
	// attack : two -> copy
	std::cout << "-------------------------------------------------------------------" << "attack : two -> copy" << std::endl;
	fragTwo.attack("fragCopy");
	fragCopy.takeDamage(fragTwo.getAttackDamage());
	// attack : one -> copy
	std::cout << "-------------------------------------------------------------------" << "attack : one -> copy" << std::endl;
	fragOne.attack("fragCopy");
	fragCopy.takeDamage(fragOne.getAttackDamage());
	// attack : two -> copy
	std::cout << "-------------------------------------------------------------------" << "attack : two -> copy" << std::endl;
	fragTwo.attack("fragCopy");
	fragCopy.takeDamage(fragTwo.getAttackDamage());
	// fragDefault highFive
	fragDefault.highFivesGuys();
	// copy highFive
	fragCopy.highFivesGuys();
	std::cout << "-------------------------------------------------------------------" << "session ended, Destructor called" << std::endl;;;

}