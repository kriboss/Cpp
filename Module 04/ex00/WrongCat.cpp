#include "WrongCat.hpp"

WrongCat::WrongCat() : type("Cat") {
	std::cout << "Cat of type " << type << " constructed." << std::endl;
}

WrongCat::WrongCat(const std::string& type) : type(type) {
	std::cout << "Cat of type " << type << " constructed." << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Cat of type " << type << " makes a sound." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "Cat of type " << type << " destructed." << std::endl;
}