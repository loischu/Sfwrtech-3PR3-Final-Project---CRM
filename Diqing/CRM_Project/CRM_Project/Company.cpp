#include "stdafx.h"
#include "Company.h"

Company::Company()
{

}

Company::~Company()
{

}

//Setters

void Company::set_companyId(std::string s)
{
	companyId = s;
}

void Company::set_name(std::string s)
{
	name = s;
}

void Company::set_address(std::string s)
{
	address = s;
}

void Company::set_sector(std::string s)
{
	sector = s;
}

//Getters

std::string Company::get_companyId()
{
	return companyId;
}

std::string Company::get_name()
{
	return name;
}

std::string Company::get_address()
{
	return address;
}
std::string Company::get_sector()
{
	return sector;
}

