#ifndef CUSTOMERSERVICE_H
#define CUSTOMERSERVICE_H

class CustomerService
{
protected:
	string repId;
	string companyId;
	string name;
public:
	CustomerService();
	~CustomerService();
	void set_repId(string s);
	void set_companyId(string s);
	void set_name(string s);

	string get_repId();
	string get_companyId();
	string get_name();
};

CustomerService::CustomerService()
{

}

CustomerService::~CustomerService()
{

}

//Setters

void CustomerService::set_repId(string s)
{
	repId = s;
}

void CustomerService::set_companyId(string s)
{
	companyId = s;
}

void CustomerService::set_name(string s)
{
	name = s;
}


//Getters

string CustomerService::get_repId()
{
	return repId;
}

string CustomerService::get_companyId()
{
	return companyId;
}

string CustomerService::get_name()
{
	return name;
}


#endif