#include "stdafx.h"
#include <sstream>
#include <vector>
#include "ClientManager.h"
#include "sqlite3.h"
#include "DBManager.h"

using namespace std;

ClientManager::ClientManager()
{
}

ClientManager::~ClientManager()
{

}

void ClientManager::AddClient(Client c)
{
	string sql = "INSERT INTO Client (client_id, company_id, title, name, email_address, phone_number, physical_address, notes)";

	ostringstream oss;

	oss << "VALUES ('"
		<< c.get_clientId() << "','"
		<< c.get_companyId() << ","
		<< c.get_title()
		<< c.get_name() << "','"
		<< c.get_emailAddress() << "','"
		<< c.get_phoneNumber << "',"
		<< c.get_physicalAddress() << "','"
		<< c.get_notes() << "')";

	sql += oss.str();

	DBManager::executeSQL(sql.c_str());

}

void ClientManager::UpdateClient(Client c)
{
	string sql = "UPDATE Client ";

	ostringstream oss;

	oss << " SET title = '" << c.get_title() << "',"
		<< "	 name	 = '" << c.get_name() << "',"
		<< "	 email_address = '" << c.get_emailAddress() << "',"
		<< "	phone_number = '" << c.get_phoneNumber() << ","
		<< "	physical_address = '" << c.get_physicalAddress() << "',"
		<< "	notes = '" << c.get_notes() << "'"
		<< "WHERE client_ID = '" << c.get_clientId() << "'";

	sql += oss.str();

	DBManager::executeSQL(sql.c_str());
}

Client ClientManager::GetClient(string ClientId)
{
	Client c = DBManager::GetClient(ClientId);
	return c;
}

vector<Client> ClientManager::GetClients(string keyword)
{
	vector<Client> clients = DBManager::GetClientsByKeyword(keyword);
	return clients;
}
