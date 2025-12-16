#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal of type " << type << " constructed." << std::endl;
}

Animal::Animal(const std::string& type) : type(type) {
	std::cout << "Animal of type " << type << " constructed." << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal of type " << type << " makes a sound." << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal of type " << type << " destructed." << std::endl;
}

std::string Animal::getType() const {
	return type;
}