#include <iostream>
#include <string>

class Zombie {
	private:
		std::string name;
	public:
		Zombie( std::string name );
		void announce( void );
		~Zombie( void );
};

Zombie* zombieHorde( int N, std::string name );