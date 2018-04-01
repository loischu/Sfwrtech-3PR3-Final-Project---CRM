// CRM_Project.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "Case.h"
#include "CaseManager.h"
#include "Client.h"
#include "ClientManager.h"
#include "Company.h"
#include "CompanyManager.h"
#include "CustomerService.h"
#include "CustomerServiceManager.h"
#include "DBManager.h"
#include "sqlite3.h"
#include "sqlite3ext.h"
#include <iomanip>
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Case c;
	Client cl;
	Company Co;
	CustomerService cs;


 string caseid;

	cout << "please enter Case id: " ;
	cin >> caseid;

	c.set_caseId(caseid);
	cout << "Case ID: " << c.get_caseId() << endl;


	
	


	system("pause");



	return 0;
}

