#include "stdafx.h"
#include "CompanyManager.h"

#include "mysql_connection.h"
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <sstream>

using namespace std;

CompanyManager::CompanyManager(void)
{
}

CompanyManager::~CompanyManager(void)
{
}

int CompanyManager::createCompany(Company c){

	int id = 0;

	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
	sql::PreparedStatement *prep_stmt;

	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
	/* Connect to the database */
	con->setSchema("dbo");

	prep_stmt = con->prepareStatement("INSERT INTO Company (Company_Name, Address, Sector) VALUES (?, ?, ?)");

	prep_stmt->setString(1, c.get_name());
	prep_stmt->setString(2, c.get_address());
	prep_stmt->setString(3, c.get_sector());
	prep_stmt->execute();

	delete prep_stmt ;

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT MAX(Company_ID) id FROM Company;"); 
	while (res->next()) {
		id=res->getInt("id");

	}

	delete res;
	delete stmt;
	delete con;



	return id;
}

void CompanyManager::updateCompany(Company c){
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep_stmt;

	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
	/* Connect to the database */
	con->setSchema("dbo");

	prep_stmt = con->prepareStatement("UPDATE Company SET Company_Name = ?, Address = ?, Sector = ? WHERE Company_ID = ?");

	prep_stmt->setString(1, c.get_name());
	prep_stmt->setString(2, c.get_address());
	prep_stmt->setString(3, c.get_sector());
	prep_stmt->setInt(4, c.get_companyId());
	prep_stmt->execute();

	delete prep_stmt;
	delete con;

}

Company CompanyManager::getCompany(int id){

	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
//	sql::PreparedStatement *prep_stmt;

	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
	/* Connect to the database */
	con->setSchema("dbo");

	stmt = con->createStatement();

	ostringstream oss;

	oss << "SELECT * FROM Company WHERE Company_ID = " << id;

	res = stmt->executeQuery(oss.str()); 

	Company c;

	while (res->next()) {
		c.set_companyId(res->getInt("Company_ID"));
		c.set_name(res->getString("Company_Name"));
		c.set_address(res->getString("Address"));
		c.set_sector(res->getString("Sector"));
	}

	delete res;
	delete stmt;
	delete con;

	return c;
}

vector<Company> CompanyManager::getCompanies(string keyword)
{
	vector<Company> companies;
	Company curr;

	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
//	sql::PreparedStatement *prep_stmt;

	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
	/* Connect to the database */
	con->setSchema("dbo");

	stmt = con->createStatement();

	ostringstream oss;

	string sql = "SELECT * FROM Company WHERE ";

	oss << "Company_Name LIKE '%" << keyword << "%' OR "
		<< "Address LIKE '%" << keyword << "%' OR "
		<< "Sector LIKE '%" << keyword << "%';";

	sql += oss.str();

	res = stmt->executeQuery(sql);

	while (res->next()){
		curr.set_companyId(res->getInt("Company_ID"));
		curr.set_name(res->getString("Company_Name"));
		curr.set_address(res->getString("Address"));
		curr.set_sector(res->getString("Sector"));

		companies.push_back(curr);
	}

	delete res;
	delete stmt;

	return companies;
}