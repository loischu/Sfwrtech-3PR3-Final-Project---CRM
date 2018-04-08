#ifndef COMPANY_MANAGER_H
#define COMPANY_MANAGER_H
#include <vector>
#include <string>
#include "Company.h"

class CompanyManager
{
public:
	CompanyManager(void);
	~CompanyManager(void);

	int createCompany(Company c);
	Company getCompany(int id);
	void updateCompany(Company c);
	std::vector<Company> getCompanies(std::string keyword);


};


#endif