#include "stdafx.h"
#include <sstream>
#include "CaseManager.h"
#include "sqlite3.h"
#include "DBManager.h"

using namespace std;

CaseManager::CaseManager()
{
}

CaseManager::~CaseManager()
{
	
}

void CaseManager::AddCase(Case c)
{
	string sql = "INSERT INTO cases (case_ID, client_id, rep_id, details, type)";

	ostringstream oss;

	oss << "VALUES ('"
		<< c.get_caseId() << "','"
		<< c.get_clientId() << "','"
		<< c.get_repId()
		<< c.get_details() << "','"
		<< c.get_type() << ")";

	sql += oss.str();

	DBManager::executeSQL(sql.c_str());

}

void CaseManager::UpdateCase(Case c)
{
	string sql = "UPDATE cases ";

	ostringstream oss;

	oss << " SET details = '" << c.get_details() << "',"
		<< "		type	 = '" << c.get_type() << "'"
		<< " WHERE case_ID = '" << c.get_caseId() << "'";

	sql += oss.str();

	DBManager::executeSQL(sql.c_str());
}

Case CaseManager::GetCase(string CaseId)
{
	Case c = DBManager::GetCase(CaseId);
	return c;
}

Case * CaseManager::GetCases(string keyword)
{
	sqlite3* db;
	return nullptr;
}
