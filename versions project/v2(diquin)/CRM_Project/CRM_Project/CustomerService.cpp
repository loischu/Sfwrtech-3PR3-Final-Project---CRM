#include "stdafx.h"
#include "CustomerService.h"

CustomerService::CustomerService()
{

}

CustomerService::~CustomerService()
{

}

//Setters

void CustomerService::set_repId(std::string s)
{
	repId = s;
}

void CustomerService::set_companyId(std::string s)
{
	companyId = s;
}

void CustomerService::set_name(std::string s)
{
	name = s;
}


//Getters

std::string CustomerService::get_repId()
{
	return repId;
}

std::string CustomerService::get_companyId()
{
	return companyId;
}

std::string CustomerService::get_name()
{
	return name;
}
