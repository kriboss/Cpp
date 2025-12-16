#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Animal") {
	std::cout << "Animal of type " << type << " constructed." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
	std::cout << "Animal of type " << type << " constructed." << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Animal of type " << type << " makes a sound." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Animal of type " << type << " destructed." << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}