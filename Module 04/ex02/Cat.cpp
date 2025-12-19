#include "Cat.hpp"

Cat::Cat() : type("Cat") {
	brain = new Brain();
	std::cout << type << " constructed." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain() const {
	return brain;
}

void Cat::addIdea(int index, const std::string& idea) {
	brain->addIdea(index, idea);
}

void Cat::printIdea(int index) const {
	brain->printIdea(index);
}

Cat::~Cat() {
	delete brain;
	std::cout << type << " destructed." << std::endl;
}