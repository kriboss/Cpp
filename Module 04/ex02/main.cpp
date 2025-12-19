#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	Dog dog;
	dog.getBrain()->addIdea(0, "buoni i croccantini");
	dog.printIdea(0);

	Cat cat;
	cat.getBrain()->addIdea(0, "meglio l'umido");
	cat.printIdea(0);
	delete j;
	delete i;
	return 0;
}