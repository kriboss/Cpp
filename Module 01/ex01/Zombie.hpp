#include <iostream>
#include <string>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		void announce();
		void setName(std::string name);
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );
