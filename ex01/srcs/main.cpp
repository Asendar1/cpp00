#include "main.hpp"

void fill_debug_contacts(PhoneBook &phonebook)
{
    std::string contacts[8][5] = {
        {"John", "Doe", "Johnny", "1234567890", "Afraid of clowns"},
        {"Jane", "Smith", "Janie", "0987654321", "Secret chocolate addiction"},
        {"Bob", "Johnson", "Bobby", "5551234567", "Can't whistle"},
        {"Alice", "Williams", "Al", "5559876543", "Talks to plants"},
        {"Charlie", "Brown", "Chuck", "5555555555", "Loves pineapple pizza"},
        {"Diana", "Davis", "Di", "1112223333", "Sleeps with teddy bear"},
        {"Eve", "Miller", "Evie", "4445556666", "Sings in shower"},
        {"Frank", "Wilson", "Frankie", "7778889999", "Collects rubber ducks"}
    };

    for (int i = 0; i < 8; i++)
    {
        phonebook.contacts[i].SetContact(
            contacts[i][0], // first_name
            contacts[i][1], // last_name
            contacts[i][2], // nick_name
            contacts[i][3], // phone_number
            contacts[i][4]  // darkest_secret
        );
    }
    std::cout << "Debug: 8 contacts added to phonebook!" << std::endl;
}

void handle_add(PhoneBook &phonebook, int *i)
{
	if (!phonebook.AddContact(*i))
		return;
	(*i)++;
	if (*i == 8)
		*i = 0;
	return;
}

void handle_search(PhoneBook phonebook)
{
	phonebook.searchContact();
	return;
}

int main()
{
	PhoneBook phonebook;
	std::string command;
	int i = 0;
	fill_debug_contacts(phonebook);

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
			handle_search(phonebook);
		else if (command == "EXIT")
			break;
		else
			std::cout << "Please enter valid command" << std::endl;
	}
	return 0;
}
