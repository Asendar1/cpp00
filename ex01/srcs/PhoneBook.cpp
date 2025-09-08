#include "PhoneBook.hpp"

int PhoneBook::CheckPhoneNumber(std::string phone_number)
{
	
	return 1;
}

int PhoneBook::AddContact(int id)
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, first_name))
	{
		std::cout << "EOF occured" << std::endl;
		return 0;
	}
	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, last_name))
	{
		std::cout << "EOF occured" << std::endl;
		return 0;
	}
	std::cout << "Enter nick name: ";
	if (!std::getline(std::cin, nick_name))
	{
		std::cout << "EOF occured" << std::endl;
		return 0;
	}
	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, phone_number))
	{
		std::cout << "EOF occured" << std::endl;
		return 0;
	}
	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, darkest_secret))
	{
		std::cout << "EOF occured" << std::endl;
		return 0;
	}
	// TODO validate the phone's number
	// CheckPhoneNumber(phone_number);
	contacts[id].SetContact(first_name, last_name, nick_name, phone_number, darkest_secret);
	std::cout << "Contact added!" << std::endl;
	return 1;
}

void PhoneBook::ShowContacts()
{
	std::cout << "Contacts:" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << "Contact " << i + 1 << ": " << contacts[i].GetFirstName() << " " << contacts[i].GetLastName() << " " << contacts[i].GetNickName() << std::endl;
	}
}
