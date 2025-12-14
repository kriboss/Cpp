#include "Harl.hpp"

int main(int argc, char** argv) {
	Harl harl;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	if (argc != 2)
		return (std::cout << "[ Probably complaining about insignificant problems ]" << std::endl, 1);

	for (int i = 0; argv[1][i]; i++)
		argv[1][i] = toupper(argv[1][i]);
	int i = 0;
	while (i < 4 && argv[1] != levels[i])
		i++;
	switch (i)
	{
		case 0:  harl.complain("DEBUG");
		// fallthrough
		case 1:  harl.complain("INFO");
		// fallthrough
		case 2:  harl.complain("WARNING");
		// fallthrough
		case 3:  harl.complain("ERROR");break;
		default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;return 0;
	}
	
	return 0;
}