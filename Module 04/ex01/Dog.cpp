#include "Dog.hpp"

Dog::Dog() : type("Dog") {
	brain = new Brain();
	std::cout << type << " constructed." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}

Brain* Dog::getBrain() const {
	return brain;
}

void Dog::addIdea(int index, const std::string& idea) {
	brain->addIdea(index, idea);
}

void Dog::printIdea(int index) const {
	brain->printIdea(index);
}

Dog::~Dog() {
	delete brain;
	std::cout << type << " destructed." << std::endl;
}