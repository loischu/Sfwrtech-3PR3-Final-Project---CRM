#ifndef CUSTOMERSERVICE_H
#define CUSTOMERSERVICE_H

class CustomerService
{
protected:
	std::string repId;
	std::string companyId;
	std::string name;
public:
	CustomerService();
	~CustomerService();
	void set_repId(std::string s);
	void set_companyId(std::string s);
	void set_name(std::string s);

	std::string get_repId();
	std::string get_companyId();
	std::string get_name();
};

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


#endif