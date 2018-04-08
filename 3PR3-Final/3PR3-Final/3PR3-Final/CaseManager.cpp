#include "stdafx.h"
#include "CaseManager.h"

#include "mysql_connection.h"
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <sstream>

using namespace std;

CaseManager::CaseManager(void)
{
}


CaseManager::~CaseManager(void)
{
}


int AddCase(Case c){
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

	prep_stmt = con->prepareStatement("INSERT INTO Client (Details, Type) VALUES (?, ?)");



	prep_stmt->setString(1, c.get_details());
	prep_stmt->setString(2, c.get_type());
	prep_stmt->execute();

	delete prep_stmt ;

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT MAX(Case_ID) id FROM Case;"); 
	while (res->next()) {
		id=res->getInt("id");

	}

	delete res;
	delete stmt;
	delete con;



	return id;


}

void UpdateCase(Case c){
			sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep_stmt;

	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
	/* Connect to the database */
	con->setSchema("dbo");

	prep_stmt = con->prepareStatement("UPDATE Case SET Details = ?, Type = ? WHERE Case_ID = ?");

	prep_stmt->setString(1, c.get_details());
	prep_stmt->setString(2, c.get_type());
	prep_stmt->setInt(3, c.get_caseID());
	prep_stmt->execute();

	delete prep_stmt;
	delete con;

}

Case GetCase(int CaseId){
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

	stmt = con->createStatement();

	ostringstream oss;

	oss << "SELECT * FROM Case WHERE Case_ID = " << CaseId;

	res = stmt->executeQuery(oss.str()); 

	Case c;

	while (res->next()) {
		c.set_caseID(res->getInt("Case_ID"));
		c.set_details(res->getString("Details"));
		c.set_type(res->getString("Type"));
	}

	delete res;
	delete stmt;
	delete con;

	return c;
}
