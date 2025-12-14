#include "Harl.hpp"

int main() {
	Harl harl;

	std::cout << "---- Harl is about to complain about everything ----" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("UNKNOWN");
	std::cout << "---- Harl has finished complaining ----" << std::endl;
	std::cout << "input: ";
	std::string input;
	getline(std::cin, input);
	if (std::cin.eof() == true)
	{
		std::cerr << "^D" << std::endl;
		return 1;
	}
	harl.complain(input);
	std::cout << std::endl;
	return 0;
}