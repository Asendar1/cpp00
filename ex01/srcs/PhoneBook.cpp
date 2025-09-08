#include "PhoneBook.hpp"

void PhoneBook::searchContact()
{
	ShowContacts();

	std::string index;
	std::cout << "enter a number of contact to display it: ";
	std::getline(std::cin, index);
	int i = std::atoi(index.c_str());
	i -= 1;
	if (i < 0 || i > 7)
	{
		std::cout << "Wrong number" << std::endl;
		return;
	}
	std::cout 	<< contacts[i].GetFirstName() << '\n'
				<< contacts[i].GetLastName() << '\n'
				<< contacts[i].GetNickName() << '\n'
				<< contacts[i].getPhoneNumber() << '\n'
				<< contacts[i].getDarkestSecret() << std::endl;
}

int PhoneBook::CheckPhoneNumber(std::string phone_number)
{
	for (size_t i = 0; i < phone_number.size(); i++)
	{
		if (!std::isdigit(phone_number[i]))
			return 0;
		if (i > 15)
		{
			std::cout << "isn't that too big for a phone number?" << std::endl;
			return 0;
		}
	}
	return 1;
}

int PhoneBook::AddContact(int id)
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	while (1)
	{
		std::cout << "Enter first name: ";
		if (!std::getline(std::cin, first_name))
		{
			std::cout << "EOF occured" << std::endl;
			return 0;
		}
		if (first_name.empty() || first_name.find_first_not_of(" \t\n\r") == std::string::npos)
		{
			std::cout << "please enter a valid input" << std::endl;
			continue;
		}
		std::cout << "Enter last name: ";
		if (!std::getline(std::cin, last_name))
		{
			std::cout << "EOF occured" << std::endl;
			return 0;
		}
		if (last_name.empty() || last_name.find_first_not_of(" \t\n\r") == std::string::npos)
		{
			std::cout << "please enter a valid input" << std::endl;
			continue;
		}
		std::cout << "Enter nick name: ";
		if (!std::getline(std::cin, nick_name))
		{
			std::cout << "EOF occured" << std::endl;
			return 0;
		}
		if (nick_name.empty() || nick_name.find_first_not_of(" \t\n\r") == std::string::npos)
		{
			std::cout << "please enter a valid input" << std::endl;
			continue;
		}
		std::cout << "Enter phone number: ";
		if (!std::getline(std::cin, phone_number))
		{
			std::cout << "EOF occured" << std::endl;
			return 0;
		}
		if (phone_number.empty() || phone_number.find_first_not_of(" \t\n\r") == std::string::npos)
		{
			std::cout << "please enter a valid input" << std::endl;
			continue;
		}
		if (!CheckPhoneNumber(phone_number))
		{
			std::cout << "please enter a valid number" << std::endl;
			continue;
		}
		std::cout << "Enter darkest secret: ";
		if (!std::getline(std::cin, darkest_secret))
		{
			std::cout << "EOF occured" << std::endl;
			return 0;
		}
		if (darkest_secret.empty() || darkest_secret.find_first_not_of(" \t\n\r") == std::string::npos)
		{
			std::cout << "please enter a valid input" << std::endl;
			continue;
		}
		break;
	}
	contacts[id].SetContact(first_name, last_name, nick_name, phone_number, darkest_secret);
	std::cout << "Contact added!" << std::endl;
	return 1;
}

std::string showTruncated(std::string str)
{
	if (str.length() > 10)
	{
		return str.substr(0, 9) + ".";
	}
	return str;
}

void PhoneBook::ShowContacts()
{
	for (int i = 0; i <= 7; i++)
	{
		std::cout 	<< std::setw(10) << i + 1
					<< " | "
					<< std::setw(10) << showTruncated(contacts[i].GetFirstName())
					<< " | "
					<< std::setw(10) << showTruncated(contacts[i].GetLastName())
					<< " | "
					<< std::setw(10) << showTruncated(contacts[i].GetNickName()) << std::endl;
	}
}
