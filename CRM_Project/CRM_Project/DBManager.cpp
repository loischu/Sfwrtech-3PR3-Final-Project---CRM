#include "stdafx.h"
#include "DBManager.h"
#include <iostream>
#include <cstdio>
#include <cstring>

int DBManager::GetCaseCallback(void* data, int count, char ** rows, char ** cols)
{
	Case* c = (Case*)data;

	if (count > 0) {

		for (int i = 0; i < count; i++) {
			if (strcmp(cols[i], "case_id") == 0) {
				std::string id(rows[i]);
				c->set_caseId(id);
			}
			else if (strcmp(cols[i], "client_id") == 0) {
				std::string clientid(rows[i]);
				c->set_clientId(clientid);
			}
			else if (strcmp(cols[i], "rep_id") == 0) {
				std::string repid(rows[i]);
				c->set_repId(repid);
			}
			else if (strcmp(cols[i], "details") == 0) {
				std::string details(rows[i]);
				c->set_details(details);
			}
			else if (strcmp(cols[i], "type") == 0) {
				std::string type(rows[i]);
				c->set_type(type);
			}
		}
	}

	return 0;
}

int DBManager::GetClientCallback(void* data, int count, char ** rows, char ** cols)
{
	Client* c = (Client*)data;

	for (int i = 0; i < count; i++) {
		if (strcmp(cols[i], "client_id") == 0) {
			std::string clientid(rows[i]);
			c->set_clientId(clientid);
		}
		else if (strcmp(cols[i], "email_address") == 0) {
			std::string address(rows[i]);
			c->set_emailAddress(address);
		}
		else if (strcmp(cols[i], "title") == 0) {
			std::string title(rows[i]);
			c->set_title(title);
		}
		else if (strcmp(cols[i], "name") == 0) {
			std::string name(rows[i]);
			c->set_name(name);
		}
		else if (strcmp(cols[i], "phone_number") == 0) {
			std::string phone(rows[i]);
			c->set_phoneNumber(phone);
		}
		else if (strcmp(cols[i], "physical_address") == 0) {
			std::string address(rows[i]);
			c->set_physicalAddress(address);
		}
		else if (strcmp(cols[i], "notes") == 0) {
			std::string notes(rows[i]);
			c->set_notes(notes);
		}
	}

	return 0;
}

int DBManager::GetCustomerServiceCallback(void* data, int count, char ** rows, char ** cols)
{
	CustomerService* c = (CustomerService*)data;

	for (int i = 0; i < count; i++) {
		if (strcmp(cols[i], "rep_ID") == 0) {
			std::string repID(rows[i]);
			c->set_repId(rows[i]);
		}
		else if (strcmp(cols[i], "company_ID") == 0) {
			std::string repID(rows[i]);
			c->set_repId(rows[i]);
		}
		else if (strcmp(cols[i], "name") == 0) {
			std::string repID(rows[i]);
			c->set_repId(rows[i]);
		}
	}

	return 0;
}

int DBManager::GetCompanyCallback(void* data, int count, char ** rows, char ** cols)
{
	Company* c = (Company*)data;

	for (int i = 0; i < count; i++) {
		if (strcmp(cols[i], "company_ID") == 0) {
			std::string companyid(rows[i]);
			c->set_companyId(companyid);
		}
		else if (strcmp(cols[i], "name") == 0) {
			std::string companyid(rows[i]);
			c->set_name(companyid);
		}
		else if (strcmp(cols[i], "sector") == 0) {
			std::string companyid(rows[i]);
			c->set_sector(companyid);
		}
	}

	return 0;
}

DBManager::DBManager()
{
	int rc;

	rc = sqlite3_open(DB_PATH, &db);

	if (rc != SQLITE_OK) {
		std::cout << "Cannot open SQLite database at path " << DB_PATH;
	}
	else {
		std::cout << "Opened database successfully";
	}
}

DBManager::~DBManager()
{
	sqlite3_close(db);
}

void DBManager::executeSQL(const char* sql)
{
	sqlite3_stmt* stmt; 
	sqlite3_prepare_v2(db, "", 0, &stmt, 0);
	
}

Case DBManager::GetCase(std::string id)
{
	Case c;

	const char* sql = strcat("SELECT * FROM Cases WHERE case_id = ", id.c_str());

	sqlite3_stmt* stmt;
	sqlite3_exec(db, sql, GetCaseCallback, &c, NULL);	
	
	return c;
}

Client DBManager::GetClient(std::string id)
{
	Client c;

	const char* sql = strcat("SELECT * FROM Clients WHERE client_id = ", id.c_str());

	sqlite3_stmt* stmt;
	sqlite3_exec(db, sql, GetClientCallback, &c, NULL);

	return c;
}

Company DBManager::GetCompany(std::string id)
{
	Company c;

	const char* sql = strcat("SELECT * FROM Companies WHERE company_id = ", id.c_str());

	sqlite3_stmt* stmt;
	sqlite3_exec(db, sql, GetCompanyCallback, &c, NULL);

	return c;
}

CustomerService DBManager::GetCustomerService(std::string id)
{
	CustomerService c;

	const char* sql = strcat("SELECT * FROM customer_service_representative WHERE rep_ID = ", id.c_str());

	sqlite3_stmt* stmt;
	sqlite3_exec(db, sql, GetCustomerServiceCallback, &c, NULL);

	return c;
}