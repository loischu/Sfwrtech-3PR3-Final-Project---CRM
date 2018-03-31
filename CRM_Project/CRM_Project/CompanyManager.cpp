#include "stdafx.h"
#include <sstream>
#include "CompanyManager.h"
#include "sqlite3.h"
#include "DBManager.h"

using namespace std;

CompanyManager::CompanyManager()
{
}

CompanyManager::~CompanyManager()
{

}

void CompanyManager::AddCompany(Company c)
{
	string sql = "INSERT INTO Company (company_id, name, address, sector)";

	ostringstream oss;

	oss << "VALUES ('"
		<< c.get_companyId() << "','"
		<< c.get_name() << "','"
		<< c.get_address() <<"','"
		<< c.get_sector() << "')";

	sql += oss.str();

	DBManager::executeSQL(sql.c_str());

}

void CompanyManager::UpdateCompany(Company c)
{
	string sql = "UPDATE Company ";

	ostringstream oss;

	oss << " SET name	 = '" << c.get_name() << "',"
		<< "	 address = '" << c.get_address() << "',"
		<< "	 sector = '" << c.get_sector() << "'"
		<< "WHERE Company_ID = '" << c.get_companyId() << "'";

	sql += oss.str();

	DBManager::executeSQL(sql.c_str());
}

Company CompanyManager::GetCompany(string CompanyId)
{
	Company c = DBManager::GetCompany(CompanyId);
	return c;
}

Company * CompanyManager::GetCompanies(string keyword)
{
	sqlite3* db;
	return nullptr;
}
