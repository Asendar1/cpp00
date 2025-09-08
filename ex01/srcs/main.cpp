#include "main.hpp"

void handle_add(PhoneBook &phonebook, int *i)
{
	if (!phonebook.AddContact(*i))
		return;
	(*i)++;
	if (*i == 8)
		*i = 0;
	return;
}

void handle_search(PhoneBook phonebook, int *i)
{
	(void)phonebook;
	(void) *(i);
	return;
}

int main()
{
	PhoneBook phonebook;
	std::string command;
	int i = 0;

	while (1)
	{
		std::cout << "Please enter either ADD/SEARCH or EXIT to exit the program" << std::endl;

		if (!std::getline(std::cin, command))
		{
			std::cout << "EOF detected" << std::endl;
			return 0;
		}

		if (command == "ADD")
			handle_add(phonebook, &i);
		else if (command == "SEARCH")
			handle_search(phonebook, &i);
		else if (command == "EXIT")
			break;
		else
			std::cout << "Please enter valid command" << std::endl;
	}
	return 0;
}
