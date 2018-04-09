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


int CaseManager::AddCase(Case c){
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

	prep_stmt = con->prepareStatement("INSERT INTO `Case` (Client_ID, Rep_ID, Details, Type) VALUES (?,?,?, ?)");


	prep_stmt->setInt(1, c.get_clientID());
	prep_stmt->setInt(2, c.get_repID());
	prep_stmt->setString(3, c.get_details());
	prep_stmt->setString(4, c.get_type());
	prep_stmt->execute();

	delete prep_stmt ;

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT MAX(Case_ID) id FROM `Case`;"); 
	while (res->next()) {
		id=res->getInt("id");

	}

	delete res;
	delete stmt;
	delete con;



	return id;


}

void CaseManager::UpdateCase(Case c){
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep_stmt;

	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
	/* Connect to the database */
	con->setSchema("dbo");

	prep_stmt = con->prepareStatement("UPDATE `Case` SET Details = ?, Type = ? WHERE Case_ID = ?");

	prep_stmt->setString(1, c.get_details());
	prep_stmt->setString(2, c.get_type());
	prep_stmt->setInt(3, c.get_caseID());
	prep_stmt->execute();

	delete prep_stmt;
	delete con;

}

Case CaseManager::GetCase(int CaseId){
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

	oss << "SELECT * FROM `Case` WHERE Case_ID = " << CaseId;

	res = stmt->executeQuery(oss.str()); 

	Case c;

	while (res->next()) {
		c.set_caseID(res->getInt("Case_ID"));
		c.set_clientID(res->getInt("Client_ID"));
		c.set_repID(res->getInt("Rep_ID"));
		c.set_details(res->getString("Details"));
		c.set_type(res->getString("Type"));
	}

	delete res;
	delete stmt;
	delete con;

	return c;
}

vector<Case> CaseManager::GetCases(string keyword)
{
	vector<Case> cases;
	Case curr;

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

	string sql = "SELECT * FROM `Case` WHERE ";

	oss << "Details LIKE '%" << keyword << "%' OR "
		<< "Type LIKE '%" << keyword << "%';";

	sql += oss.str();

	res = stmt->executeQuery(sql);


	while (res->next()){
		curr.set_caseID(res->getInt("Case_ID"));
		curr.set_clientID(res->getInt("Client_ID"));
		curr.set_repID(res->getInt("Rep_ID"));
		curr.set_details(res->getString("Details"));
		curr.set_type(res->getString("Type"));

		cases.push_back(curr);
	}

	delete res;
	delete stmt;

	return cases;
}