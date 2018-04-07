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



int getChoice(){


}

bool createCase(){

	Case c;

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
	return false;
}

bool createClient(){

	Client cl;
	//client object --------------begin-----------------
	string companyId, clientid, name, title, emailAddress, phoneNumber, physicalAddress, notes;

	cout << "please enter company id: " ;
	cin >> companyId;
	cout << "please enter Client id: " ;
	cin >> clientid;
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
	cl.set_clientId(clientid);
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
	return false;
}

bool createCompany(){
	Company co;
	//Company object items -------------------begin----------------
	string companyId, company_name, company_address, sector;

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
	return false;
}

bool createCustomerServices(){
	CustomerService cs;

	string companyId, repid, name;

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
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{

	cout << "Welcome to CRM 2018" << endl;

	int choice = 0;

	while(choice < 1 && choice > 4){

		cout << "Please select from the following options: " << endl;

		cout << "1) Create a new Case\n" 
			<< "2) Create a new Client\n"
			<< "3) Create a new Company\n" 
			<< "4) Quit" << endl;

		cin >> choice;
		cin.get();


		switch (choice)
		{
		case 1:
			createCase();
			break;
		case 2:
			createClient();
			break;
		case 3:
			createCompany();
			break;
		case 4:
			return 0;
			break;
		default:
			break;
		}


	}

	system("pause");



	return 0;
}

