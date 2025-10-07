#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name) {}

Zombie::~Zombie( void ) {
	std::cout << "Zombie " << this->name << " is destroyed." << std::endl;
}

void Zombie::announce( void ) {
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}