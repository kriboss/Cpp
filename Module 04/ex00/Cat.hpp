#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

# include <string>
# include <iostream>

class Cat  : public Animal {
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		void	makeSound() const;
		~Cat();
};

#endif