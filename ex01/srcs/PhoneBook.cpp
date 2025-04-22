#include "PhoneBook.hpp"

void PhoneBook::add_contact(int id)
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "Enter first name: ";
	std::cin >> first_name;
	std::cout << "Enter last name: ";
	std::cin >> last_name;
	std::cout << "Enter nick name: ";
	std::cin >> nick_name;
	std::cout << "Enter phone number: ";
	std::cin >> phone_number;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkest_secret;
	contacts[id].set_contact(first_name, last_name, nick_name, phone_number, darkest_secret);
	std::cout << "Contact added!" << std::endl;
}

void PhoneBook::show_contacts()
{
	std::cout << "Contacts:" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << "Contact " << i + 1 << ": " << contacts[i].get_first_name() << " " << contacts[i].get_last_name() << " " << contacts[i].get_nick_name() << std::endl;
	}
}
