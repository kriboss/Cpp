#include "Cat.hpp"

Cat::Cat() {
       type = "Cat";
       std::cout << type << " constructed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
	       Animal::operator=(other);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

Cat::~Cat() {
	std::cout << type << " destructed." << std::endl;
}