#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

# include <string>
# include <iostream>

class Dog  : public Animal {
	protected:
		std::string		type;
		Brain*			brain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog& operator=(const Dog &other);
		void	makeSound() const;
		Brain* getBrain() const;
		void addIdea(int index, const std::string& idea);
		void printIdea(int index) const;
		~Dog();
};

#endif