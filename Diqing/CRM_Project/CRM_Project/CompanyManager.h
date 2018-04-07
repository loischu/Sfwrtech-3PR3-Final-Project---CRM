#pragma once
#include "Company.h"
#include <vector>
#include <string>

class CompanyManager
{
public:
	CompanyManager();
	~CompanyManager();

	void AddCompany(Company c);
	void UpdateCompany(Company c);
	Company GetCompany(std::string CompanyId);
	std::vector<Company> GetCompanies(std::string keyword);


};

