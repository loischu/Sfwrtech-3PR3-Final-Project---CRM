#include "stdafx.h"
#include "Case.h"

Case::Case()
{

}

Case::~Case()
{

}

//Setters

void Case::set_caseId(std::string s)
{
	caseId = s;
}

void Case::set_clientId(std::string s)
{
	clientId = s;
}

void Case::set_repId(std::string s)
{
	repId = s;
}

void Case::set_details(std::string s)
{
	details = s;
}
void Case::set_type(std::string s)
{
	type = s;
}

//Getters

std::string Case::get_caseId()
{
	return caseId;
}

std::string Case::get_clientId()
{
	return clientId;
}

std::string Case::get_repId()
{
	return repId;
}
std::string Case::get_details()
{
	return details;
}
std::string Case::get_type()
{
	return type;
}