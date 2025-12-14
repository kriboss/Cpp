#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::~Zombie( void ) {
	std::cout << "Zombie " << this->name << " is destroyed." << std::endl;
}

void Zombie::announce( void ) {
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}