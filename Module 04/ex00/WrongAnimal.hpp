#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {
	protected:
		std::string		type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string& type);
		void	makeSound() const;
		~WrongAnimal();
		std::string getType() const;
};

#endif