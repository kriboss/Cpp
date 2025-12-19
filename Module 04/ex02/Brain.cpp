#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructed." <<  std::endl;
}

Brain::Brain(const Brain& other) {
	*this = other;
	std::cout << "Brain copy constructed." <<  std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain assigned." <<  std::endl;
	return *this;
}

void Brain::addIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	}
}

void Brain::printIdea(int index) const {
	if (index >= 0 && index < 100) {
		std::cout << ideas[index] << std::endl;
	}
}

Brain::~Brain() {
	std::cout << "Brain destructed." <<  std::endl;
}