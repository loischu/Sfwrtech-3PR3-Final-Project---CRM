#pragma once
#include "Company.h"

static class CompanyManager
{
public:
	CompanyManager();
	~CompanyManager();

	void AddCompany(Company c);
	void UpdateCompany(Company c);
	Company GetCompany(std::string CompanyId);
	Company* GetCompanies(std::string keyword);


};

