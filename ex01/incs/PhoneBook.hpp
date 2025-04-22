#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX_CONTACTS 8

#include "main.hpp"
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[MAX_CONTACTS];

	public:
		void add_contact(int id);
		void show_contacts();

};

#endif
