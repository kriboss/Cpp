#include "Phonebook.hpp"

PhoneBook::PhoneBook() : index(0), contactCount(0) {}

void PhoneBook::ADD()
{
	if (index == 8)
		index = 0;
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
	if (contacts[index].first_name == "" || contacts[index].last_name == "" || contacts[index].nickname == ""
		|| contacts[index].phone_number == "" || contacts[index].darkest_secret == "")
	{
		std::cout << "All fields are required. Contact not added.\n";
		ADD();
		return;
	}
	index++;
	if (contactCount < 8)
		contactCount++;
}

void PhoneBook::SEARCH()
{
	if (contactCount == 0)
	{
		std::cout << "No contacts available\n";
		return;
	}
	std::cout << "Contacts:\n";
	std::cout << std::setw(10) << "Index" << "|"
	          << std::setw(10) << "First Name" << "|"
	          << std::setw(10) << "Last Name" << "|"
	          << std::setw(10) << "Nickname" << "|\n";
	std::cout << "--------------------------------------------\n";
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
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
	}
	std::cout << "Enter index to view details: ";
	std::string input;
	std::getline(std::cin, input);
	int idx = atoi(input.c_str());
	if (idx < 1 || idx > contactCount)
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

void PhoneBook::EXIT()
{
	std::cout << "bye!\n";
}

PhoneBook::~PhoneBook() {}