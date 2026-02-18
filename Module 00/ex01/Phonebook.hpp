#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

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
	private:
		Contact contacts[8];
		int index;
		int contactCount;
	public:
		PhoneBook();
		void ADD();
		void SEARCH();
		void EXIT();
		~PhoneBook();
		
};

#endif