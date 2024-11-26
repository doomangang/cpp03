#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap clapOne = ClapTrap("one");
	ClapTrap clapDefault = ClapTrap();
	ClapTrap clapTwo = ClapTrap("two");
	ClapTrap clapCopy = clapTwo;

	// attack : one -> default
	clapOne.attack("clapDefault");
	clapDefault.takeDamage(2);
	// attack : default -> copy
	clapDefault.attack("clapCopy");
	clapCopy.takeDamage(8);
	// repair : copy
	clapCopy.beRepaired(INT32_MAX);
	// attack : two -> default
	clapTwo.attack("clapDefault");
	clapDefault.takeDamage(INT32_MAX);
	// repair : one
	clapOne.beRepaired(UINT32_MAX);
	// attack : one -> default
	clapOne.attack("clapDefault");
	clapDefault.takeDamage(20);
	// repair : default
	clapDefault.beRepaired(10);
	// attack : one -> two - until one knocks out of ep
	for (int i = 0; i < 7; i++) {
		clapOne.attack("clapTwo");
		clapTwo.takeDamage(10);
	}
	clapOne.attack("clapTwo");
}