#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

# include <string>
# include <iostream>

class Cat  : public Animal {
	protected:
		std::string		type;
		Brain*			brain;
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		void	makeSound() const;
		Brain* getBrain() const;
		void addIdea(int index, const std::string& idea);
		void printIdea(int index) const;
		~Cat();
};

#endif