#pragma once
#include <string>
#include <vector>
#include "sqlite3.h"
#include "Case.h"
#include "Client.h"
#include "Company.h"
#include "CustomerService.h"

class DBManager
{
	const char* DBManager::DB_PATH;
	static sqlite3* db;

	static int GetCaseCallback(void* data, int count, char** rows, char**);
	static int GetClientCallback(void* data, int count, char** rows, char**);
	static int GetCompanyCallback(void* data, int count, char** rows, char**);
	static int GetCustomerServiceCallback(void* data, int count, char** rows, char**);

	static int GetCaseByKeywordCallback(void* data, int count, char** rows, char**);
	static int GetClientByKeywordCallback(void* data, int count, char** rows, char**);
	static int GetCompanyByKeywordCallback(void* data, int count, char** rows, char**);
	static int GetCustomerServiceByKeywordCallback(void* data, int count, char** rows, char**);
public:
	DBManager();
	~DBManager();

	static void executeSQL(const char* sql);

	static Case GetCase(std::string id);
	static Client GetClient(std::string id);
	static Company GetCompany(std::string id);
	static CustomerService GetRepresentative(std::string id);

	static std::vector<Case> GetCasesByKeyword(std::string keyword);
	static std::vector<Client> GetClientsByKeyword(std::string keyword);
	static std::vector<Company> GetCompaniesByKeyword(std::string keyword);
	static std::vector<CustomerService> GetRepresentativesByKeyword(std::string keyword);


};

