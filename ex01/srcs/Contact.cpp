#include "Contact.hpp"

void Contact::SetContact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string Contact::GetFirstName()
{
	return this->first_name;
}
std::string Contact::GetLastName()
{
	return this->last_name;
}

std::string Contact::GetNickName()
{
	return this->nick_name;
}
