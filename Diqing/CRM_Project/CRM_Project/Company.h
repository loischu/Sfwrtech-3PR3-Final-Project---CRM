#ifndef COMPANY_H
#define COMPANY_H
#include <string>
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
#endif

