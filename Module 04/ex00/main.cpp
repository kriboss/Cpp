#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete meta;
	delete j;
	std::cout << std::endl;
	const WrongAnimal* z = new WrongAnimal();
	const WrongAnimal* x = new WrongCat();
	std::cout << z->getType() << " " << std::endl;
	std::cout << x->getType() << " " << std::endl;
	z->makeSound();
	x->makeSound();
	delete z;
	delete x;

	return (0);
}