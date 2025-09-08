#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;

	public:
		void SetContact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret);
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetNickName();
};




#endif

