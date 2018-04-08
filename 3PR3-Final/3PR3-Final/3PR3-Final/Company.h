#ifndef COMPANY_H
#define COMPANY_H
#include <string>
class Company
{

	int companyID;	
	std::string name;
	std::string address;
	std::string sector;
public:
	Company(void){}
	~Company(void){}

	const int& get_companyId() const { return companyID; }
	const std::string& get_name() const { return name; }
	const std::string& get_address() const { return address; }
	const std::string& get_sector() const { return sector; }

	void set_companyId(int id) { companyID = id;}
	void set_name(std::string s) { name = s; }
	void set_address(std::string s) { address = s; }
	void set_sector(std::string s) { sector = s; }


};

#endif