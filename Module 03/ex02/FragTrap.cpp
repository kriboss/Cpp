#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructed with default values." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->name << " is requesting a high five! ✋" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destructed." << std::endl;
}

