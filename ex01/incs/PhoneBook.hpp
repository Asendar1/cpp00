#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX_CONTACTS 8

#include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

class PhoneBook
{
	private:
	
	public:
		Contact contacts[MAX_CONTACTS];
		int AddContact(int id);
		int CheckPhoneNumber(std::string phoneNumber);
		void searchContact();
		void ShowContacts();
		void SetContact();

};

#endif
