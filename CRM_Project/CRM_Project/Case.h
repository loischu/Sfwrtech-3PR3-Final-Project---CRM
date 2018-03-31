#ifndef CASE_H
#define CASE_H

#include <string>

class Case
{
protected:
	std::string caseId;
	std::string clientId;
	std::string repId;
	std::string details;
	std::string type;
public:
	Case();
	~Case();
	void set_caseId(std::string id);
	void set_clientId(std::string s);
	void set_repId(std::string id);
	void set_details(std::string s);
	void set_type(std::string s);

	std::string get_caseId();
	std::string get_clientId();
	std::string get_repId();
	std::string get_details();
	std::string get_type();
};

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

#endif