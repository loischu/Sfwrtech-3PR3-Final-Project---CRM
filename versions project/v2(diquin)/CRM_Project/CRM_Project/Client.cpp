#include "stdafx.h"
#include "Client.h"

Client::Client()
{

}

Client::~Client()
{

}

//Setters

void Client::set_clientId(std::string s)
{
	clientId = s;
}

void Client::set_companyId(std::string s)
{
	companyId = s;
}

void Client::set_name(std::string s)
{
	name = s;
}

void Client::set_title(std::string s)
{
	title = s;
}
void Client::set_emailAddress(std::string s)
{
	emailAddress = s;
}

void Client::set_phoneNumber(std::string s)
{
	phoneNumber = s;
}

void Client::set_physicalAddress(std::string s)
{
	physicalAddress = s;
}

void Client::set_notes(std::string s)
{
	notes = s;
}


//Getters

std::string Client::get_clientId()
{
	return clientId;
}

std::string Client::get_companyId()
{
	return companyId;
}

std::string Client::get_name()
{
	return name;
}

std::string Client::get_title()
{
	return title;
}

std::string Client::get_emailAddress()
{
	return emailAddress;
}

std::string Client::get_phoneNumber()
{
	return phoneNumber;
}

std::string Client::get_physicalAddress()
{
	return physicalAddress;
}

std::string Client::get_notes()
{
	return notes;
}

