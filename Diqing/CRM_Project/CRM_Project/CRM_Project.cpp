// CRM_Project.cpp : Defines the entry point for the console application.
/* manager classes are created in vs 2012. It seems to cause linker error on vs 2013 on my machine.
* commented for now
#include "CaseManager.h"
#include "ClientManager.h"
#include "CompanyManager.h"
#include "CustomerServiceManager.h"
#include "DBManager.h"
#include "sqlite3.h"
#include "sqlite3ext.h"
* for now, directly use classes to demo
*/
#include "stdafx.h"
#include "Case.h"
#include "Client.h"
#include "Company.h"
#include "CustomerService.h"

#include <iomanip>
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Case c;
	Client cl;
	Company co;
	CustomerService cs;

	//case object --------------begin-----------------
	string caseid, cl_id, repid, details,type;
	cout << "please enter Case id: " ;
	cin >> caseid;
	cout << "please enter Client id: " ;
	cin >> cl_id;
	cout << "please enter Rep id: " ;
	cin >> repid;
	cout << "please enter Details: " ;
	cin >> details;
	getline(cin, details);
	cout << "please enter type: " ;
	cin >> type;

	c.set_caseId(caseid);
	c.set_clientId(cl_id);
	c.set_repId(repid);
	c.set_details(details);
	c.set_type(type);
	cout << "-----------------Case Information begun-----------"<< endl;
	cout << "Case ID: " << c.get_caseId() << endl;
	cout << "Client ID: " << c.get_clientId() << endl;
	cout << "Representative ID: " << c.get_repId() << endl;
	cout << "Details: " << c.get_details() << endl;
	cout << "Type: " << c.get_type() << endl;
	cout << "-----------------Case Information ends-----------"<< endl;
	//case object --------------end-----------------

	//client object --------------begin-----------------
	string companyId;
	string name;
	string title;
	string emailAddress;
	string phoneNumber;
	string physicalAddress;
	string notes;

	cout << "please enter company id: " ;
	cin >> companyId;
	cout << "please enter Client id: " ;
	cin >> cl_id;
	cout << "please enter name: " ;
	cin >> name;
	getline(cin, name);
	cout << "please enter title: " ;
	cin >> title;
	cout << "please enter email address: " ;
	cin >> emailAddress;
	cout << "please enter phoneNumber: " ;
	cin >> phoneNumber;
	cout << "please enter physical Address: " ;
	cin >> physicalAddress;
	getline(cin, physicalAddress);
	cout << "please enter notes: " ;
	cin >> notes;
	getline(cin, notes);


	cl.set_companyId(companyId);
	cl.set_clientId(cl_id);
	cl.set_name(name);
	cl.set_title(title);
	cl.set_emailAddress(emailAddress);
	cl.set_phoneNumber(phoneNumber);
	cl.set_physicalAddress(physicalAddress);
	cl.set_notes(notes);

	cout << "-----------------Client Information begun-----------"<< endl;
	cout << "Company ID: " << cl.get_companyId() << endl;
	cout << "Client ID: " << cl.get_clientId() << endl;
	cout << "Name: " << cl.get_name() << endl;
	cout << "Title: " << cl.get_title() << endl;
	cout << "Email Address: " << cl.get_emailAddress() << endl;
	cout << "Phone Number: " << cl.get_phoneNumber() << endl;
	cout << "Physical address: " << cl.get_physicalAddress() << endl;
	cout << "Notes: " << cl.get_notes() << endl;
	cout << "-----------------Client Information ends-----------"<< endl;
	//client object --------------end-----------------
	//Company object items -------------------begin----------------
	string company_name;
	string company_address;
	string sector;

	cout << "please enter company id: " ;
	cin >> companyId;
	cout << "please enter company name: " ;
	cin >> company_name;
	getline(cin, company_name);
	cout << "please enter company address: " ;
	cin >> company_address;
	getline(cin, company_address);
	cout << "please enter sector: " ;
	cin >> sector;

	co.set_companyId(companyId);
	co.set_name(company_name);
	co.set_address(company_address);
	co.set_sector(sector);

	cout << "-----------------Company Information begun-----------"<< endl;
	cout << "Company ID: " << co.get_companyId() << endl;
	cout << "Company Name: " << co.get_name() << endl;
	cout << "Company Address: " << co.get_address() << endl;
	cout << "Sector: " << co.get_sector() << endl;
	cout << "-----------------Company Information ends-----------"<< endl;
	//Company object items -------------------ends----------------

	//Customer service object items -------------------begin----------------
	cout << "please enter company id: " ;
	cin >> companyId;
	cout << "please enter representative id: " ;
	cin >> repid;
	cout << "please enter name: " ;
	cin >> name;
	getline(cin, name);

	cs.set_companyId(companyId);
	cs.set_repId(repid);
	cs.set_name(name);


	cout << "-----------------Customer Service Information begun-----------"<< endl;
	cout << "Company ID: " << cs.get_companyId() << endl;
	cout << "Representative ID: " << cs.get_repId() << endl;
	cout << "Name: " << cs.get_name() << endl;
	cout << "-----------------Customer Service Information ends-----------"<< endl;
	//Customer Service object items -------------------ends----------------


	system("pause");



	return 0;
}

