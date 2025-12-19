#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Animal") {
	std::cout << type << " constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
	std::cout << type << " constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->type = other.type;
	}
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong Animal makes a sound." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << type << " destructed." << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}