#ifndef CUSTOMERSERVICE_H
#define CUSTOMERSERVICE_H

#include <string>
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


#endif