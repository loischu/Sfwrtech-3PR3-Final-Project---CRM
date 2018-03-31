#ifndef COMPANY_H
#define COMPANY_H

class Company
{
protected:
	std::string companyId;
	std::string name;
	std::string address;
	std::string sector;
public:
	Company();
	~Company();
	void set_companyId(std::string s);
	void set_name(std::string s);
	void set_address(std::string s);
	void set_sector(std::string s);

	std::string get_companyId();
	std::string get_name();
	std::string get_address();
	std::string get_sector();
};

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


#endif

