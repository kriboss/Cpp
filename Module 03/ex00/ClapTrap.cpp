#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " constructed with default values." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints > 0 && hitPoints > 0) {
		--energyPoints;
		std::cout << "ClapTrap " << name << " attacks " << target
				  << ", causing " << attackDamage << " points of damage!"
				  << " (Energy left: " << energyPoints << ")" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " has insufficient energy or hit points to attack." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints <= amount) {
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes " << amount
				  << " points of damage and is now destroyed!" << std::endl;
	} else {
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount
				  << " points of damage! (Hit Points left: " << hitPoints << ")" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints > 0 && hitPoints > 0) {
		--energyPoints;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " is repaired by " << amount
				  << " points! (Hit Points: " << hitPoints
				  << ", Energy left: " << energyPoints << ")" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " has insufficient energy or hit points to repair." << std::endl;
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destructed." << std::endl;
}