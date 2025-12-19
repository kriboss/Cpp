#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"

# include <string>
# include <iostream>

class Animal {
	protected:
		std::string		type;
	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		virtual void	makeSound() const = 0;
		virtual ~Animal();
		std::string getType() const;
};

#endif