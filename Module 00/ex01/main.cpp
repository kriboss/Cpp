#include "Phonebook.hpp"

int	main()
{
	PhoneBook phonebook;

	std::string command;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.ADD();
		else if (command == "SEARCH")
			phonebook.SEARCH();
		else if (command == "EXIT")
		{
			phonebook.EXIT();
			break;
		}	
	}
	return 0;
}
