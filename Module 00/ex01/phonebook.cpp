#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class Contact {
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

class PhoneBook {
	public:
		Contact contacts[8];
		int index;
		PhoneBook() : index(0) {}
		void ADD()
		{
			if (index == 2)
				index = 0;
			std::cout << "Adding contact at index " << index << "\n";
			std::cout << "Enter contact first name: ";
			std::getline(std::cin, contacts[index].first_name);
			std::cout << "Enter contact last name: ";
			std::getline(std::cin, contacts[index].last_name);
			std::cout << "Enter contact nickname: ";
			std::getline(std::cin, contacts[index].nickname);
			std::cout << "Enter contact phone number: ";
			std::getline(std::cin, contacts[index].phone_number);
			std::cout << "Enter contact darkest secret: ";
			std::getline(std::cin, contacts[index].darkest_secret);
			index++;
		}
		void SEARCH()
		{
			if (index == 0)
			{
				std::cout << "No contacts available\n";
				return;
			}
			std::cout << "Contacts:\n";
			int i = 0;
			while (contacts[i].first_name != "")
			{
				std::cout << i + 1 << "|";
				if (contacts[i].first_name.length() > 10)
					std::cout << contacts[i].first_name.substr(0, 9) + ".|";
				else
					std::cout << std::setw(10) << contacts[i].first_name << "|";
				if (contacts[i].last_name.length() > 10)
					std::cout << contacts[i].last_name.substr(0, 9) + ".|";
				else
					std::cout << std::setw(10) << contacts[i].last_name << "|";
				if (contacts[i].nickname.length() > 10)
					std::cout << contacts[i].nickname.substr(0, 9) + ".|\n";
				else
					std::cout << std::setw(10) << contacts[i].nickname << "|\n";
				i++;
			}
			std::cout << "Enter index to view details: ";
			std::string input;
			std::getline(std::cin, input);
			int idx = atoi(input.c_str());
			if (idx < 1 || idx > index)
			{
				std::cout << "Invalid index\n";
				return;
			}
			idx--;
			std::cout << "First Name: " << contacts[idx].first_name << "\n";
			std::cout << "Last Name: " << contacts[idx].last_name << "\n";
			std::cout << "Nickname: " << contacts[idx].nickname << "\n";
			std::cout << "Phone Number: " << contacts[idx].phone_number << "\n";
			std::cout << "Darkest Secret: " << contacts[idx].darkest_secret << "\n";
		}
		void EXIT()
		{
			std::cout << "bye!\n";
		}
};

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