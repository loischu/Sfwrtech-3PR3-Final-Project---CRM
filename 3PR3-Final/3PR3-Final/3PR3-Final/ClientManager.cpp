#include "stdafx.h"
#include "ClientManager.h"

#include "mysql_connection.h"
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include <sstream>

using namespace std;

ClientManager::ClientManager(void)
{
}


ClientManager::~ClientManager(void)
{
}

int ClientManager::AddClient(Client c){
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

	prep_stmt = con->prepareStatement("INSERT INTO Client (Title,Client_Name,Email_Address,Phone_Number,Physical_Address,Notes) VALUES (?, ?, ?, ?, ?, ?)");



	prep_stmt->setString(1, c.get_title());
	prep_stmt->setString(2, c.get_clientName());
	prep_stmt->setString(3, c.get_emailAddress());
	prep_stmt->setString(4, c.get_phoneNumber());
	prep_stmt->setString(5, c.get_physicalAddress());
	prep_stmt->setString(6, c.get_Notes());
	prep_stmt->execute();

	delete prep_stmt ;

	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT MAX(Client_ID) id FROM Client;"); 
	while (res->next()) {
		id=res->getInt("id");

	}

	delete res;
	delete stmt;
	delete con;



	return id;
}
Client ClientManager::GetClient(int ClientId){

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

	oss << "SELECT * FROM Client WHERE Client_ID = " << ClientId;

	res = stmt->executeQuery(oss.str()); 

	Client c;

	while (res->next()) {
		c.set_clientId(res->getInt("Client_ID"));
		c.set_title(res->getString("Title"));
		c.set_clientName(res->getString("Client_Name"));
		c.set_emailAddress(res->getString("Email_Address"));
		c.set_phoneNumber(res->getString("Phone_Number"));
		c.set_physicalAddress(res->getString("Physical_Address"));
		c.set_Notes(res->getString("Notes"));
	}

	delete res;
	delete stmt;
	delete con;

	return c;
}
void ClientManager::UpdateClient(Client c){
	sql::Driver *driver;
	sql::Connection *con;
	sql::PreparedStatement *prep_stmt;

	/* Create a connection */
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
	/* Connect to the database */
	con->setSchema("dbo");

	prep_stmt = con->prepareStatement("UPDATE Client SET Title = ?, Client_Name = ?, Email_Address = ?, Phone_Number = ?, Physical_Address = ?, Notes = ? WHERE Client_ID = ?");

	prep_stmt->setString(1, c.get_title());
	prep_stmt->setString(2, c.get_clientName());
	prep_stmt->setString(3, c.get_emailAddress());
	prep_stmt->setString(4, c.get_phoneNumber());
	prep_stmt->setString(5, c.get_physicalAddress());
	prep_stmt->setString(6, c.get_Notes());
	prep_stmt->setInt(7, c.get_clientID());
	prep_stmt->execute();

	delete prep_stmt;
	delete con;

}
vector<Client> ClientManager::GetClients(string keyword)
{
	vector<Client> clients;
	Client curr;

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

	string sql = "SELECT * FROM Client WHERE ";

	oss << "Client_Name LIKE '%" << keyword << "%' OR "
		<< "Address LIKE '%" << keyword << "%' OR "
		<< "Sector LIKE '%" << keyword << "%';";

	sql += oss.str();

	res = stmt->executeQuery(sql);

	while (res->next()){
		curr.set_clientId(res->getInt("Client_ID"));
		curr.set_title(res->getString("Title"));
		curr.set_clientName(res->getString("Client_Name"));
		curr.set_emailAddress(res->getString("Email_Address"));
		curr.set_phoneNumber(res->getString("Phone_Number"));
		curr.set_physicalAddress(res->getString("Physical_Address"));
		curr.set_Notes(res->getString("Notes"));

		clients.push_back(curr);
	}

	delete res;
	delete stmt;

	return clients;
}