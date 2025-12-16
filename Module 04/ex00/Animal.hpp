#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {
	protected:
		std::string		type;
	public:
		Animal();
		Animal(const std::string& type);
		void	makeSound() const;
		~Animal();
		std::string getType() const;
};

#endif