#include "Dog.hpp"

Dog::Dog() : type("Dog") {
	std::cout << "Dog of type " << type << " constructed." << std::endl;
}

Dog::Dog(const std::string& type) : type(type) {
	std::cout << "Dog of type " << type << " constructed." << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Dog of type " << type << " makes a sound." << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog of type " << type << " destructed." << std::endl;
}