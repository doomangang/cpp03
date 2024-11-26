#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap clapOne = ClapTrap("one");
	ClapTrap clapDefault = ClapTrap();
	ClapTrap clapTwo = ClapTrap("two");
	ClapTrap clapCopy = clapTwo;

	// attack : default -> copy
	clapDefault.attack("clapCopy");
	clapCopy.takeDamage(8);
	// attack : two -> default
	clapTwo.attack("clapDefault");
	clapDefault.takeDamage( 2147500000);
	// repair : default
	clapDefault.beRepaired(10);
	// attack : one -> two - until one knocks out of ep
	std::cout << "\n-------------------------------------one -> two - until one knocks out of ep\n";
	for (int i = 0; i < 10; i++) {
		clapOne.attack("clapTwo");
		clapTwo.takeDamage(10);
	}
	std::cout << "-------------------------------------one -> two - until one knocks out of ep\n";
	clapOne.attack("clapTwo");
}