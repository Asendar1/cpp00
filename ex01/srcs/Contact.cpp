#include "Contact.hpp"

void Contact::set_contact(std::string first_name, std::string last_name, std::string nick_name, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string Contact::get_first_name()
{
	return this->first_name;
}
std::string Contact::get_last_name()
{
	return this->last_name;
}

std::string Contact::get_nick_name()
{
	return this->nick_name;
}
