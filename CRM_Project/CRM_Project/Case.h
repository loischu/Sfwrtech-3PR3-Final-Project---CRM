#ifndef CASE_H
#define CASE_H

#include <string>

using namespace std;
class Case
{
protected:
	string caseId;
	string clientId;
	string repId;
	string details;
	string type;
public:
	Case();
	~Case();
	void set_caseId(string id);
	void set_clientId(string s);
	void set_repId(string id);
	void set_details(string s);
	void set_type(string s);

	string get_caseId();
	string get_clientId();
	string get_repId();
	string get_details();
	string get_type();
};

Case::Case()
{

}

Case::~Case()
{

}

//Setters

void Case::set_caseId(string s)
{
	caseId = s;
}

void Case::set_clientId(string s)
{
	clientId = s;
}

void Case::set_repId(string s)
{
	repId = s;
}

void Case::set_details(string s)
{
	details = s;
}
void Case::set_type(string s)
{
	type = s;
}

//Getters

string Case::get_caseId()
{
	return caseId;
}

string Case::get_clientId()
{
	return clientId;
}

string Case::get_repId()
{
	return repId;
}
string Case::get_details()
{
	return details;
}
string Case::get_type()
{
	return type;
}

#endif