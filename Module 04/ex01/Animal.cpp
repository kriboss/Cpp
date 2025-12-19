#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << type << " constructed." << std::endl;
}

Animal::Animal(const std::string& type) : type(type) {
	std::cout << type << " constructed." << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "Animal copy assignment operator called" << std::endl;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal Sound" << std::endl;
}

Animal::~Animal() {
	std::cout << type << " destructed." << std::endl;
}

std::string Animal::getType() const {
	return type;
}