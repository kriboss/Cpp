#include "Zombie.hpp"

int main() {
	std::cout << "Heap allocation (newZombie)" << std::endl;
	Zombie *z = newZombie("HeapZombie");
	z->announce();
	delete z;

	std::cout << std::endl << "Stack allocation (randomChump)" << std::endl;
	randomChump("StackZombie");

	return 0;
}