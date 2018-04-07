#ifndef COMPANY_H
#define COMPANY_H

class Company
{
protected:
	string companyId;
	string name;
	string address;
	string sector;
public:
	Company();
	~Company();
	void set_companyId(string s);
	void set_name(string s);
	void set_address(string s);
	void set_sector(string s);

	string get_companyId();
	string get_name();
	string get_address();
	string get_sector();
};

Company::Company()
{

}

Company::~Company()
{

}

//Setters

void Company::set_companyId(string s)
{
	companyId = s;
}

void Company::set_name(string s)
{
	name = s;
}

void Company::set_address(string s)
{
	address = s;
}

void Company::set_sector(string s)
{
	sector = s;
}

//Getters

string Company::get_companyId()
{
	return companyId;
}

string Company::get_name()
{
	return name;
}

string Company::get_address()
{
	return address;
}
string Company::get_sector()
{
	return sector;
}


#endif

