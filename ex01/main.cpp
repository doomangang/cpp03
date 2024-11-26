#include "ScavTrap.hpp"

int main (void)
{
	ScavTrap scavOne = ScavTrap("one");
	ScavTrap scavDefault = ScavTrap();
	ScavTrap scavTwo = ScavTrap("two");
	ScavTrap scavCopy = scavTwo;

	// attack : one -> default
	scavOne.attack("scavDefault");
	scavDefault.takeDamage(scavOne.getAttackDamage());
	// attack : default -> copy
	scavDefault.attack("scavCopy");
	scavCopy.takeDamage(scavDefault.getAttackDamage());
	// repair : copy
	scavCopy.beRepaired(INT32_MAX);
	// attack : two -> default
	scavTwo.attack("scavDefault");
	scavDefault.takeDamage(scavTwo.getAttackDamage());
	// repair : one
	scavOne.beRepaired(UINT32_MAX);
	// attack : one -> default
	scavOne.attack("scavDefault");
	scavDefault.takeDamage(scavOne.getAttackDamage());
	// repair : default
	scavDefault.beRepaired(10);
	// attack : one -> two - until one knocks out of ep
	while (scavOne.getEnergyPoint() > 0)
	{
		scavOne.attack("scavTwo");
		scavTwo.takeDamage(scavOne.getAttackDamage());
	}
	scavOne.attack("scavTwo");
}