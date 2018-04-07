#pragma once
#include "Company.h"
#include <vector>

class CompanyManager
{
public:
	CompanyManager();
	~CompanyManager();

	void AddCompany(Company c);
	void UpdateCompany(Company c);
	Company GetCompany(string CompanyId);
	vector<Company> GetCompanies(string keyword);


};

