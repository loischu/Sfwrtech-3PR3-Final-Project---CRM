#include "stdafx.h"
#include "DBManager.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;

DBManager::DBManager()
{
	int rc;

	rc = sqlite3_open(DB_PATH, &db);

	if (rc != SQLITE_OK) {
		cout << "Cannot open SQLite database at path " << DB_PATH;
	}
	else {
		cout << "Opened database successfully";
	}
}
DBManager::~DBManager()
{
	sqlite3_close(db);
}

#pragma region Callbacks
int DBManager::GetCaseCallback(void* data, int count, char ** rows, char ** cols)
{
	Case* c = (Case*)data;

	if (count > 0) {

		for (int i = 0; i < count; i++) {
			if (strcmp(cols[i], "case_id") == 0) {
				string id(rows[i]);
				c->set_caseId(id);
			}
			else if (strcmp(cols[i], "client_id") == 0) {
				string clientid(rows[i]);
				c->set_clientId(clientid);
			}
			else if (strcmp(cols[i], "rep_id") == 0) {
				string repid(rows[i]);
				c->set_repId(repid);
			}
			else if (strcmp(cols[i], "details") == 0) {
				string details(rows[i]);
				c->set_details(details);
			}
			else if (strcmp(cols[i], "type") == 0) {
				string type(rows[i]);
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
			string clientid(rows[i]);
			c->set_clientId(clientid);
		}
		else if (strcmp(cols[i], "email_address") == 0) {
			string address(rows[i]);
			c->set_emailAddress(address);
		}
		else if (strcmp(cols[i], "title") == 0) {
			string title(rows[i]);
			c->set_title(title);
		}
		else if (strcmp(cols[i], "name") == 0) {
			string name(rows[i]);
			c->set_name(name);
		}
		else if (strcmp(cols[i], "phone_number") == 0) {
			string phone(rows[i]);
			c->set_phoneNumber(phone);
		}
		else if (strcmp(cols[i], "physical_address") == 0) {
			string address(rows[i]);
			c->set_physicalAddress(address);
		}
		else if (strcmp(cols[i], "notes") == 0) {
			string notes(rows[i]);
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
			string repID(rows[i]);
			c->set_repId(rows[i]);
		}
		else if (strcmp(cols[i], "company_ID") == 0) {
			string repID(rows[i]);
			c->set_repId(rows[i]);
		}
		else if (strcmp(cols[i], "name") == 0) {
			string repID(rows[i]);
			c->set_repId(rows[i]);
		}
	}

	return 0;
}

int DBManager::GetCaseByKeywordCallback(void * data, int count, char ** rows, char **)
{
	//int rc = 
	return 0;
}

int DBManager::GetClientByKeywordCallback(void * data, int count, char ** rows, char **)
{
	return 0;
}

int DBManager::GetCompanyByKeywordCallback(void * data, int count, char ** rows, char **)
{
	return 0;
}

int DBManager::GetCustomerServiceByKeywordCallback(void * data, int count, char ** rows, char **)
{
	return 0;
}

int DBManager::GetCompanyCallback(void* data, int count, char ** rows, char ** cols)
{
	Company* c = (Company*)data;

	for (int i = 0; i < count; i++) {
		if (strcmp(cols[i], "company_ID") == 0) {
			string companyid(rows[i]);
			c->set_companyId(companyid);
		}
		else if (strcmp(cols[i], "name") == 0) {
			string companyid(rows[i]);
			c->set_name(companyid);
		}
		else if (strcmp(cols[i], "sector") == 0) {
			string companyid(rows[i]);
			c->set_sector(companyid);
		}
	}

	return 0;
}
#pragma endregion

#pragma region Get By Id
Case DBManager::GetCase(string id)
{
	Case c;

	const char* sql = strcat("SELECT * FROM Cases WHERE case_id = ", id.c_str());

	sqlite3_stmt* stmt;
	sqlite3_exec(db, sql, GetCaseCallback, &c, NULL);	
	
	return c;
}

Client DBManager::GetClient(string id)
{
	Client c;

	const char* sql = strcat("SELECT * FROM Clients WHERE client_id = ", id.c_str());

	sqlite3_stmt* stmt;
	sqlite3_exec(db, sql, GetClientCallback, &c, NULL);

	return c;
}

Company DBManager::GetCompany(string id)
{
	Company c;

	const char* sql = strcat("SELECT * FROM Companies WHERE company_id = ", id.c_str());

	sqlite3_stmt* stmt;
	sqlite3_exec(db, sql, GetCompanyCallback, &c, NULL);

	return c;
}

CustomerService DBManager::GetRepresentative(string id)
{
	CustomerService c;

	const char* sql = strcat("SELECT * FROM customer_service_representative WHERE rep_ID = ", id.c_str());

	sqlite3_stmt* stmt;
	sqlite3_exec(db, sql, GetCustomerServiceCallback, &c, NULL);

	return c;
}
#pragma endregion

#pragma region Get By Keyword
vector<Case> DBManager::GetCasesByKeyword(string keyword)
{
	vector<Case> cases;
	sqlite3_stmt *stmt;

	string sql = "select * from cases ";

	ostringstream oss;

	oss << "WHERE details LIKE '%" << keyword << "' "
		<< "OR type LIKE '%" << keyword << "'";

	sql += oss.str();

	int rc = sqlite3_prepare_v2(db, sql.c_str(),-1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
	}
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		string caseid(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		string clientid(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		string repid(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		string details(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		string type(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));

		Case c;
		c.set_caseId(caseid);
		c.set_clientId(clientid);
		c.set_repId(repid);
		c.set_details(details);
		c.set_type(type);
		cases.push_back(c);
	}
	if (rc != SQLITE_DONE) {
		cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;		
	}
	sqlite3_finalize(stmt);
	return cases;
}

vector<Client> DBManager::GetClientsByKeyword(string keyword)
{
	vector<Client> clients;
	sqlite3_stmt *stmt;

	string sql = "select * from client ";

	ostringstream oss;

	oss << "WHERE title LIKE '%" << keyword << "%' "
		<< "OR name LIKE '%" << keyword << "%' "
		<< "OR email_address LIKE '%" << keyword << "%' "
		<< "OR phone_address LIKE '%" << keyword << "%' "
		<< "OR physical_address LIKE '%'" << keyword << "%' "
		<< "OR notes LIKE '%" << keyword << "'";

	sql += oss.str();

	int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
	}
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		string clientid(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		string companyid(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		string title(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
		string email(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
		string phone(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
		string address(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
		string notes(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7)));

		Client c;
		c.set_clientId(clientid);
		c.set_companyId(companyid);
		c.set_title(title);
		c.set_name(name);
		c.set_emailAddress(email);
		c.set_phoneNumber(phone);
		c.set_physicalAddress(address);
		c.set_notes(notes);
		clients.push_back(c);
	}
	if (rc != SQLITE_DONE) {
		cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
	}
	sqlite3_finalize(stmt);
}

vector<Company> DBManager::GetCompaniesByKeyword(string keyword)
{
	vector<Company> companies;
	sqlite3_stmt *stmt;

	string sql = "select * from company ";

	ostringstream oss;

	oss << "WHERE name LIKE '%" << keyword << "%' "
		<< "OR address LIKE '%" << keyword << "%' "
		<< "OR sector LIKE '%" << keyword << "%' ";

	sql += oss.str();

	int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
	}
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		string companyid(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		string address(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		string sector(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));

		Company c;
		c.set_companyId(companyid);
		c.set_name(name);
		c.set_address(address);
		c.set_sector(sector);
		companies.push_back(c);
	}
	if (rc != SQLITE_DONE) {
		cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
	}
	sqlite3_finalize(stmt);
	return companies;
}

vector<CustomerService> DBManager::GetRepresentativesByKeyword(string keyword)
{
	vector<CustomerService> representatives;
	sqlite3_stmt *stmt;

	string sql = "select * from customer_service_representative ";

	ostringstream oss;

	oss << "WHERE name LIKE '%" << keyword << "%' "
		<< "OR address LIKE '%" << keyword << "%' "
		<< "OR sector LIKE '%" << keyword << "%' ";

	sql += oss.str();

	int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
	}
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		string repid(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
		string companyid(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		string name(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));

		CustomerService c;
		c.set_repId(repid);
		c.set_companyId(companyid);
		c.set_name(name);
		representatives.push_back(c);
	}
	if (rc != SQLITE_DONE) {
		cerr << "SELECT failed: " << sqlite3_errmsg(db) << endl;
	}
	sqlite3_finalize(stmt);
	return representatives;
}
#pragma endregion

void DBManager::executeSQL(const char* sql)
{
	char* errmsg = 0;

	int rc = sqlite3_exec(db, sql, 0, 0, &errmsg);

	if (rc != SQLITE_OK) {
		cout << "SQLITE Operation failed: " << errmsg << endl; 
	}
		
}