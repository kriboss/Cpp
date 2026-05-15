#include "Dog.hpp"

Dog::Dog() {
       type = "Dog";
       std::cout << type << " constructed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
	       Animal::operator=(other);
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

Dog::~Dog() {
	std::cout << type << " destructed." << std::endl;
}