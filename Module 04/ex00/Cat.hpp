#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

# include <string>
# include <iostream>

class Cat  : public Animal {
	protected:
		std::string		type;
	public:
		Cat();
		Cat(const std::string& type);
		void	makeSound() const;
		~Cat();
};

#endif