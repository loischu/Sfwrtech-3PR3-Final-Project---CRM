
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

#include "Case.h"
#include "CaseManager.h"

#include "Representative.h"
#include "RepresentativeManager.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

void menu();
void showCaseDetail();
void searchInput();
void search();
void openExisting();
void createNew();
void caseDetail();
void editCase();
void editClient();
void editCompany();
void editCaseMenu();
void editClientMenu();
void editCompanyMenu();
void showCompanysDetail();
void showClientsDetail();
void showCasesDetail();
// menus
void editSaved();
void searchFail();
void mainMenu();
void searchMenu();
void openExistingMenu();
void createNewMenu();
void editClientMenu();
void editCompanyMenu();
void exitConfirm();
// main menu
int choice1 = 0;
// second menu
int choice2 = 3;
// third menu
int choice3 = 3;
// return vector size
int size;
string keyword;
char repId[20];
char company[20];

// vectors to hold results
vector<Case> cVec;
vector<Client> clVec;
vector<Company> coVec;

//class objects
Case c;
Company co;
Client cl;
Representative r;

//manager class objects
CaseManager cm;
CompanyManager com;
ClientManager clm;
RepresentativeManager rm;



int main(int argc, char** argv) {

	// menu
	menu();
	return 0;
}


void menu(){
	do {
		choice2 = 0;
		mainMenu();

		switch (choice1) {

		case 1:
			choice1 = 1;
			search();
			break;

		case 2:
			choice1 = 2;
			openExisting();
			break;

		case 3:
			choice1 = 3;
			createNew();
			break;

		case 4:
			choice1 = 4;
			exitConfirm();
			break;

		default:
			cout << "Invalid input!\n";
			exitConfirm();
			break;

		}

	} while (choice1 != 4);


}

void search(void) {

	do {
		searchMenu();
		// work on search with key word
		switch (choice2){

		case 3:
			searchInput();
			cVec = cm.GetCases(keyword);
			size = static_cast<int>(cVec.size());
			// search
			if (size>0){
				// if have res
				showCasesDetail();
			}
			else{
				// else
				searchFail();
			}
			break;

		case 2:
			searchInput();
			clVec = clm.GetClients(keyword);
			size = static_cast<int>(clVec.size());
			// search
			if (size>0){
				// if have res
				showClientsDetail();
			}
			else{
				// else
				searchFail();
			}
			break;

		case 1:
			searchInput();
			coVec = com.getCompanies(keyword);
			size = static_cast<int>(coVec.size());
			// search
			if (size>0){
				// if have res
				showCompanysDetail();
			}
			else{
				// else
				searchFail();
			}
			break;

		case 4:
			break;

		default:
			cout << "Invalid input!\n";
			break;

		}

	} while (choice2 != 4);


}

void openExisting(void) {
		openExistingMenu();
		// check keyword(caseID)
		//keyword;
		//if exist
		c = cm.GetCase(stoi(keyword));

		if (stoi(keyword) == c.get_caseID()){
			caseDetail();
		}
		else{
			//if not exist
			char res;
			cout << "There is no existing case with this caseId. Search again?(Y/N)";
			cin >> res;
			if (res == 'Y'){
				openExisting();
			}
			else{
				menu();
			}
		}
}

void createNew(void) {
	createNewMenu();
}

void exitConfirm(void) {
	char res;
	cout << "Are you sure you want to exit?(Y/N)";
	cin >> res;
	if (res == 'Y'){
		exit(1);
	}
	else{
		menu();
	}
}




void editCase(void) {
	char res = 'N';
	do {
		editCaseMenu();

		switch (choice3){

		case 1:
			char details[20];
			// edit the detials here
			do {
				cout << "Please enter new details\n";
				cin >> details;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			c.set_details(details);
			cm.UpdateCase(c);
			editSaved();
			break;

		case 2:
			char type[20];
			// edit the type here
			do {
				cout << "Please enter new type\n";
				cin >> type;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			c.set_type(type);
			cm.UpdateCase(c);
			editSaved();
			break;

		case 3:
			menu();
			break;

		default:
			break;

		}

	} while (choice3 != 3);
}

void editCompany(void) {
	char res = 'N';
	do {
		editCompanyMenu();

		switch (choice3){

		case 1:
			char name[20];
			// edit the detials here
			do {
				cout << "Please enter new name\n";
				cin >> name;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			co.set_name(name);
			com.updateCompany(co);
			editSaved();
			break;

		case 2:
			char address[20];
			// edit the detials here
			do {
				cout << "Please enter new address\n";
				cin >> address;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			co.set_address(address);
			com.updateCompany(co);
			editSaved();
			break;

		case 3:
			char sector[20];
			// edit the detials here
			do {
				cout << "Please enter new sector\n";
				cin >> sector;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			co.set_sector(sector);
			com.updateCompany(co);
			editSaved();
			break; 

		case 4:
			menu();
			break;

		default:
			break;

		}

	} while (choice3 != 4);
}

void editClient(void) {
	char res = 'N';
	do {
		editClientMenu();

		switch (choice3){

		case 1:
			char name[20];
			// edit the name here
			do {
				cout << "Please enter new name\n";
				cin >> name;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			cl.set_clientName(name);
			clm.UpdateClient(cl);
			editSaved();
			break;

		case 2:
			char title[20];
			// edit the title here
			do {
				cout << "Please enter new title\n";
				cin >> title;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			cl.set_title(title);
			clm.UpdateClient(cl);
			editSaved();
			break;

		case 3:
			char emailAddress[20];
			// edit the email address here
			do {
				cout << "Please enter new email address\n";
				cin >> emailAddress;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			cl.set_emailAddress(emailAddress);
			clm.UpdateClient(cl);
			editSaved();
			break;

		case 4:
			char phoneNumber[20];
			// edit the phone number here
			do {
				cout << "Please enter new phone number\n";
				cin >> phoneNumber;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			cl.set_phoneNumber(phoneNumber);
			clm.UpdateClient(cl);
			editSaved();
			break;

		case 5:
			char physicalAddress[20];
			// edit the physical address here
			do {
				cout << "Please enter new physical address\n";
				cin >> physicalAddress;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			cl.set_physicalAddress(physicalAddress);
			clm.UpdateClient(cl);
			editSaved();
			break;

		case 6:
			char notes[20];
			// edit the notes here
			do {
				cout << "Please enter new email notes\n";
				cin >> notes;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			cl.set_Notes(notes);
			clm.UpdateClient(cl);
			editSaved();
			break;

		case 7:
			menu();
			break;

		default:
			break;

		}

	} while (choice3 != 7);
}

// show detail of 1 case
void showCaseDetail(void) {
	// Case ID, Client Name, Representative Name and Representative Name
	cout << "-----------------Case Information begun-----------" << endl;
	cout << "Case ID: " << c.get_caseID() << endl;
	cout << "Client ID: " << c.get_clientID() << endl;
	cout << "Representative ID: " << c.get_repID()<< endl;
	cout << "Details: " << c.get_details() << endl;
	cout << "Type: " << c.get_type() << endl;
	cout << "-----------------Case Information ends-----------" << endl;
}

// show detail of 1 Client
void showClientDetail(void) {
	cout << "-----------------Client Information begun-----------" << endl;
	cout << "Company ID: " << cl.get_companyId() << endl;
	cout << "Client ID: " << cl.get_clientID() << endl;
	cout << "Name: " << cl.get_clientName() << endl;
	cout << "Title: " << cl.get_title() << endl;
	cout << "Email Address: " << cl.get_emailAddress() << endl;
	cout << "Phone Number: " << cl.get_phoneNumber() << endl;
	cout << "Physical address: " << cl.get_physicalAddress() << endl;
	cout << "Notes: " << cl.get_Notes()<< endl;
	cout << "-----------------Client Information ends-----------" << endl;
}

// show detail of 1 Company
void showCompanyDetail(void) {
	cout << "-----------------Company Information begun-----------" << endl;
	cout << "Company ID: " << co.get_companyId() << endl;
	cout << "Company Name: " << co.get_name() << endl;
	cout << "Company Address: " << co.get_address() << endl;
	cout << "Sector: " << co.get_sector() << endl;
	cout << "-----------------Company Information ends-----------" << endl;
}

// show list of objs after search and selection for one of them to edit
void showCasesDetail(void) {
	int res = 0;
	Case p;
	// Case ID, Client Name, Representative Name and Representative Name
	cout << "Case ID - Client Name - Representative Name - Detail\n";
	for (std::vector<Case>::iterator it = cVec.begin(); it != cVec.end(); ++it) {
		// get the client
		cl = clm.GetClient(it->get_clientID());
		// get the rep
		r = rm.GetRepresentative(it->get_repID());
		cout << it->get_caseID() + " - " + cl.get_clientName() + " - " + r.get_Name() + " - " + it->get_type() + "\n";
	}
	// selection part
	cout << "please select one to edit or 0 to go back to menu\n";
	cin >> res;
	if (res == 0){
		menu();
	}
	else{
		//this is for asking for user input and set the data of case

		c = cm.GetCase(res);
		// set the case to edit
		showCaseDetail();
		editCase();
	}
}
void showClientsDetail(void) {
	int res = 0;
	// Client Name, Title and associated Company Name
	cout << "Client ID - Title - Name - Company ID\n";
	for (std::vector<Client>::iterator it = clVec.begin(); it != clVec.end(); ++it) {
		// get the company
		co = com.getCompany(it->get_companyId());
		cout << it->get_clientID() + " - " + it->get_title() + " - " + it->get_clientName() + " - " + co.get_name() + "\n";
	}
	// selection part
	cout << "please select one to edit or 0 to go back to menu\n";
	cin >> res;
	if (res==0){
		menu();
	}
	else{
		cl = clm.GetClient(res);
		showClientDetail();
		editClient();
	}
}
void showCompanysDetail(void) {
	int res = 0;
	// company name and sector
	cout << "Company ID - Company Name - Sector\n";
	for (std::vector<Company>::iterator it = coVec.begin(); it != coVec.end(); ++it) {
		cout << it->get_companyId() + " - " + it->get_name() + " - " + it->get_sector() + "\n";
	}
	// selection part
	cout << "please select one to edit or 0 to go back to menu\n";
	cin >> res;
	if (res == 0){
		menu();
	}
	else{
		co = com.getCompany(res);

		showCompanyDetail();
		editCompany();
	}
}

void searchInput(void) {

	cout << "Please enter keywords: ";
	cin >> keyword;

}

void searchFail(void) {
	char res;
	cout << "The search produces no results. Search again?(Y/N)";
	cin >> res;
	if (res=='Y'){
		search();
	}
	else{
		menu();
	}
}

void editSaved(void) {
	int opt = 0;
	cout << "1 - View other records\n";
	cout << "2 - Return to the main menu\n";
	cout << "Please select\n";
	cin >> opt;
	if (opt == 1){
		if (choice1==1){
			search();
		}
		else if (choice1 == 2){
			openExisting();
		}
	}
	else{
		menu();
	}
}


// menus
void mainMenu(void) {
	cout << "Main Menu\n";
	cout << "1 - Search database\n";
	cout << "2 - Open an existing case\n";
	cout << "3 - Start a New Case\n";
	cout << "4 - Quit\n";
	cout << "Please choose: ";
	cin >> choice1;
}


void searchMenu(void) {

	cout << "Search Menu\n";
	cout << "1 - Company\n";
	cout << "2 - Client\n";
	cout << "3 - Case\n";
	cout << "4 - Back\n";
	cout << "Please choose: ";
	cin >> choice2;

}

void editCaseMenu(void) {

	cout << "Case Edit Menu\n";
	cout << "1 - Details\n";
	cout << "2 - Type\n";
	cout << "3 - Back\n";
	cout << "Please choose: ";
	cin >> choice3;

}
void editCompanyMenu(void) {

	cout << "Case Edit Menu\n";
	cout << "1 - Name\n";
	cout << "2 - Address\n";
	cout << "3 - Sector\n";
	cout << "4 - Back\n";
	cout << "Please choose: ";
	cin >> choice3;

}
void editClientMenu(void) {

	cout << "Case Edit Menu\n";
	cout << "1 - Name\n";
	cout << "2 - Title\n";
	cout << "3 - Email Address\n";
	cout << "4 - Phone Number\n";
	cout << "5 - Physical Address\n";
	cout << "6 - Notes\n";
	cout << "7 - Back\n";
	cout << "Please choose: ";
	cin >> choice3;

}

void openExistingMenu(void) {
	cout << "Please enter caseID: ";
	cin >> keyword;
}

void createNewMenu(void) {
	bool existingCl = false;
	bool existingCo = false;
	int company;
	int client;
	char res = 'N';
	char res2 = 'N';

	// get commpany info
	do {
		cout << "Does the associated company exist(Y/N)";
		cin >> res;
		if (res == 'Y'){
			cout << "Please enter the company ID:" << endl;
			cin >> company;
			co = com.getCompany(company);
			//check client and company
			if (company == co.get_companyId()){
				cout << "The company exists.\n";
				existingCo = true;
			}
			else{
				// else back to menu
				cout << "The copany doesn't exist. Do you want to continue?(Y/N)\n";
				cin >> res2;
				if (res2 != 'Y'){
					menu();
				}
			}
		}
		else{
			// company
			char Cname[20];
			char address[20];
			char sector[20];
			cout << "Please provide information of the company:\n";
			cout << "Please enter the name:" << endl;
			cin >> Cname;
			cout << "Please enter the address:" << endl;
			cin >> address;
			cout << "Please enter the sector:" << endl;
			cin >> sector;

			co.set_name(Cname);
			co.set_address(address);
			co.set_sector(sector);
			// add to database
			com.createCompany(co);
			existingCo = true;
		}
	} while (existingCo == false);

	// get client info
	do {
		cout << "Is it for an existing client(Y/N)";
		cin >> res;
		if (res == 'Y'){
			cout << "Please enter the client ID:" << endl;
			cin >> client;
			cl = clm.GetClient(client);
			//check client and company
			if (client == cl.get_clientID()){
				cout << "The client exists.\n";
				existingCl = true;
			}
			else{
				// else back to menu
				cout << "The client doesn't exist. Do you want to continue?(Y/N)\n";
				cin >> res2;
				if (res2 != 'Y'){
					menu();
				}
			}
		}
		else{
			// client
			char name[20];
			char title[20];
			char emailAddress[20];
			char phoneNumber[20];
			char physicalAddress[20];
			char notes[20];
			cout << "Please provide information of the client:\n";
			cout << "Please enter the name:" << endl;
			cin >> name;
			cout << "Please enter the title:" << endl;
			cin >> title;
			cout << "Please enter the email address:" << endl;
			cin >> emailAddress;
			cout << "Please enter the phone number:" << endl;
			cin >> phoneNumber;
			cout << "Please enter the physical address:" << endl;
			cin >> physicalAddress;
			cout << "Please enter the notes:" << endl;
			cin >> notes;

			cl.set_clientName(name);
			cl.set_title(title);
			cl.set_emailAddress(emailAddress);
			cl.set_phoneNumber(phoneNumber);
			cl.set_physicalAddress(physicalAddress);
			cl.set_Notes(notes);
			// set the company id with last data
			cl.set_companyId(co.get_companyId());
			// add to database
			clm.AddClient(cl);
			existingCl = true;
		}
	} while (existingCl == false);
	

	// create case
	char type[20];
	char detail[20];
	cout << "Please enter the type:" << endl;
	cin >> type;
	cout << "Please enter the detail:" << endl;
	cin >> detail;
	c.set_type(type);
	c.set_details(detail);
	c.set_clientID(cl.get_clientID());
	// add to database
	cm.AddCase(c);

	// success
	cout << "Case created successfully and the case ID is"  << c.get_caseID()  <<  " .\nDo you want to create new record?(Y/N)";
	cin >> res;
	if (res == 'Y'){
		createNew();
	}
	else{
		menu();
	}
}

void caseDetail(void) {
	showCaseDetail();
	char res = 'N';
	cout << "\nDo you wishes to edit the details(Y/N)";
	cin >> res;
	if (res == 'Y'){
		editCase();
	}
	else{
		menu();
	}
}
