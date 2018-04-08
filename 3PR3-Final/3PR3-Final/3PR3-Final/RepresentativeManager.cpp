#include "stdafx.h"
#include "RepresentativeManager.h"

#include "mysql_connection.h"
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <sstream>

using namespace std;

RepresentativeManager::RepresentativeManager(void)
{
}


RepresentativeManager::~RepresentativeManager(void)
{
}

int AddCustomerService(Representative c){
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

	prep_stmt = con->prepareStatement("INSERT INTO customer_service_representative (Name) VALUES (?)");

	prep_stmt->setString(1, c.get_Name());
	prep_stmt->execute();

	delete prep_stmt ;

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT MAX(Rep_ID) id FROM customer_service_representative;"); 
	while (res->next()) {
		id=res->getInt("id");

	}

	delete res;
	delete stmt;
	delete con;



	return id;


}

void UpdateCustomerService(Representative c){
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep_stmt;

	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
	/* Connect to the database */
	con->setSchema("dbo");

	prep_stmt = con->prepareStatement("UPDATE customer_service_representative SET Name = ? WHERE Rep_ID = ?");

	prep_stmt->setString(1, c.get_Name());
	prep_stmt->setInt(2, c.get_repId());
	prep_stmt->execute();

	delete prep_stmt;
	delete con;

}

Representative GetCustomerService(int CustomerServiceId){

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

	oss << "SELECT * FROM customer_service_representative WHERE Rep_ID = " << CustomerServiceId;

	res = stmt->executeQuery(oss.str()); 

	Representative c;

	while (res->next()) {
		c.set_repId(res->getInt("Rep_ID"));
		c.set_name(res->getString("Name"));
	}

	delete res;
	delete stmt;
	delete con;

	return c;
}