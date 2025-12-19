#include "WrongCat.hpp"

WrongCat::WrongCat() : type("Cat") {
	std::cout << type << " constructed." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	*this = other;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Meow" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << type << " destructed." << std::endl;
}