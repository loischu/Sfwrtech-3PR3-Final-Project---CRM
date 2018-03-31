#pragma once
#include <string>
#include "sqlite3.h"
#include "Case.h"
#include "Client.h"
#include "Company.h"
#include "CustomerService.h"


static class DBManager
{
	const char* DB_PATH = ""; //sqlite file
	static sqlite3* db;

	static int GetCaseCallback(void* data, int count, char** rows, char**);
	static int GetClientCallback(void* data, int count, char** rows, char**);
	static int GetCompanyCallback(void* data, int count, char** rows, char**);
	static int GetCustomerServiceCallback(void* data, int count, char** rows, char**);
public:
	DBManager();
	~DBManager();

	static void executeSQL(const char* sql);

	static Case GetCase(std::string id);
	static Client GetClient(std::string id);
	static Company GetCompany(std::string id);
	static CustomerService GetCustomerService(std::string id);


};

