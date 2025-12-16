#include "Cat.hpp"

Cat::Cat() : type("Cat") {
	std::cout << "Cat of type " << type << " constructed." << std::endl;
}

Cat::Cat(const std::string& type) : type(type) {
	std::cout << "Cat of type " << type << " constructed." << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Cat of type " << type << " makes a sound." << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat of type " << type << " destructed." << std::endl;
}