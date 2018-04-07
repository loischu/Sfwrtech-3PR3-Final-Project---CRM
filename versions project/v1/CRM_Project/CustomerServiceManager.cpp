#include "stdafx.h"
#include <sstream>
#include <vector>
#include "CustomerServiceManager.h"
#include "sqlite3.h"
#include "DBManager.h"

using namespace std;

CustomerServiceManager::CustomerServiceManager()
{
}

CustomerServiceManager::~CustomerServiceManager()
{

}

void CustomerServiceManager::AddCustomerService(CustomerService c)
{
	string sql = "INSERT INTO CustomerService (rep_id, company_id, name)";

	ostringstream oss;

	oss << "VALUES ('"
		<< c.get_repId() << "','"
		<< c.get_companyId() << "','"
		<< c.get_name() << "')";

	sql += oss.str();

	DBManager::executeSQL(sql.c_str());

}

void CustomerServiceManager::UpdateCustomerService(CustomerService c)
{
	string sql = "UPDATE CustomerService ";

	ostringstream oss;

	oss << " SET name	 = '" << c.get_name() << "',"
		<< "WHERE rep_id = '" << c.get_repId() << "'";

	sql += oss.str();

	DBManager::executeSQL(sql.c_str());
}

CustomerService CustomerServiceManager::GetCustomerService(string CustomerServiceId)
{
	CustomerService c = DBManager::GetRepresentative(CustomerServiceId);
	return c;
}

vector<CustomerService> CustomerServiceManager::GetRepresentatives(string keyword)
{
	vector<CustomerService> reps = DBManager::GetRepresentativesByKeyword(keyword);
	return reps;
}
