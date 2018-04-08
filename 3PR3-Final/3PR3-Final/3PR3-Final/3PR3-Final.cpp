// 3PR3-Final.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

#include "Company.h"
#include "CompanyManager.h"

#include "Client.h"
#include "ClientManager.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{



	cout << endl;
	Company c;
	c.set_address("123 Fake St");
	c.set_name("ROC, INC.");
	c.set_sector("Clothing");

	CompanyManager cm;

	int id = cm.createCompany(c);

	cout<<"Company created with ID " << id <<endl;

	c.set_companyId(id);

	cout<<"Updating Company..."<<endl;
	c.set_address("345 Fake St");
	c.set_sector("Private Security");

	cm.updateCompany(c);
	c = cm.getCompany(c.get_companyId());

	cout << "New Company values:\n" <<endl;

	cout << "Company Name: " << c.get_name() << endl;
	cout << "Company Address: " << c.get_address() << endl;
	cout << "Company Sector: " << c.get_sector() << endl;

	cout << "\nRetrieving all companies called ROC, Inc." << endl;

	vector<Company> companies = cm.getCompanies("ROC");

	vector<Company>::iterator it;

	for(it=companies.begin();it!=companies.end();it++){

		cout << "\nCompany Name: " << it->get_name() << endl;
		cout << "Company Address: " << it->get_address() << endl;
		cout << "Company Sector: " << it->get_sector() << endl;

	}


	cout << endl;
	cin.get();
	return EXIT_SUCCESS;
}

