#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

# include <string>
# include <iostream>

class Dog  : public Animal {
	protected:
		std::string		type;
	public:
		Dog();
		Dog(const std::string& type);
		void	makeSound() const;
		~Dog();
};

#endif