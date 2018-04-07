#include "stdafx.h"
#include "Case.h"
#include "Client.h"
#include "Company.h"
#include "CustomerService.h"
#include <iostream>
#include <vector>
#include <cstdlib>


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
char keyword[20];
char repId[20];
char company[20];
Case c;
Client cl;
Company co;
CustomerService cs;
vector<Case> cVec;
vector<Client> clVec;
vector<Company> coVec;

int main(int argc, char** argv) {
	// make 10 of room
	cVec.reserve(10);
	clVec.reserve(10);
	coVec.reserve(10);
	// populate test data
	// c
	c.set_caseId("1");
	c.set_clientId("1");
	c.set_repId("1");
	c.set_details("case 1 details");
	c.set_type("report");
	cVec.push_back(c);
	c.set_caseId("2");
	c.set_clientId("2");
	c.set_repId("2");
	c.set_details("case 1 details");
	c.set_type("news");
	cVec.push_back(c);
	// cl
	cl.set_companyId("1");
	cl.set_clientId("1");
	cl.set_name("Chris");
	cl.set_title("Manager");
	cl.set_emailAddress("chris@gmail.com");
	cl.set_phoneNumber("2899924367");
	cl.set_physicalAddress("180 Duke St");
	cl.set_notes("None");
	clVec.push_back(cl);
	cl.set_companyId("1");
	cl.set_clientId("2");
	cl.set_name("Joe");
	cl.set_title("Manager");
	cl.set_emailAddress("joe@gmail.com");
	cl.set_phoneNumber("2899924397");
	cl.set_physicalAddress("180 Bay St");
	cl.set_notes("None");
	clVec.push_back(cl);
	// co
	co.set_companyId("1");
	co.set_name("Google");
	co.set_address("1 google drive");
	co.set_sector("sector 1");
	coVec.push_back(co);
	co.set_companyId("2");
	co.set_name("Apple");
	co.set_address("1 apple drive");
	co.set_sector("sector 2");
	coVec.push_back(co);
	// login
	cout << "Welcome to CRM, Please register\n";
	cout << "Please enter your ID: ";
	cin >> repId;
	cout << "Please enter your Company: ";
	cin >> company;
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
			break;

		}

	} while (choice1 != 4);


}

void search(void) {

	do {
		searchMenu();
		// work on search with key word
		switch (choice2){

		case 1:
			searchInput();
			// search
			if (true){
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
			// search
			if (true){
				// if have res
				showClientsDetail();
			}
			else{
				// else
				searchFail();
			}
			break;

		case 3:
			searchInput();
			// search
			if (true){
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
		if (keyword==c.get_caseId()){
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
			cl.set_name(name);
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
			cl.set_notes(notes);
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
	cout << "Case ID: " << c.get_caseId() << endl;
	cout << "Client ID: " << c.get_clientId() << endl;
	cout << "Representative ID: " << c.get_repId() << endl;
	cout << "Details: " << c.get_details() << endl;
	cout << "Type: " << c.get_type() << endl;
	cout << "-----------------Case Information ends-----------" << endl;
}

// show detail of 1 Client
void showClientDetail(void) {
	cout << "-----------------Client Information begun-----------" << endl;
	cout << "Company ID: " << cl.get_companyId() << endl;
	cout << "Client ID: " << cl.get_clientId() << endl;
	cout << "Name: " << cl.get_name() << endl;
	cout << "Title: " << cl.get_title() << endl;
	cout << "Email Address: " << cl.get_emailAddress() << endl;
	cout << "Phone Number: " << cl.get_phoneNumber() << endl;
	cout << "Physical address: " << cl.get_physicalAddress() << endl;
	cout << "Notes: " << cl.get_notes() << endl;
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
	for (std::vector<Case>::iterator it = cVec.begin(); it != cVec.end(); ++it) {
		cout << it->get_caseId() + " - " + it->get_clientId() + " - " + it->get_repId() + " - " + it->get_type() + "\n";
	}
	// selection part
	cout << "please select one to edit or 0 to go back to menu\n";
	cin >> res;
	if (res == 0){
		menu();
	}
	else{
		// set the case to edit
		c.set_caseId("1");
		c.set_clientId("1");
		c.set_repId("1");
		c.set_details("case 1 details");
		c.set_type("report");
		showCaseDetail();
		editCase();
	}
}
void showClientsDetail(void) {
	int res = 0;
	// Client Name, Title and associated Company Name
	for (std::vector<Client>::iterator it = clVec.begin(); it != clVec.end(); ++it) {
		cout << it->get_clientId() + " - " + it->get_name() + " - " + it->get_companyId() + "\n";
	}
	// selection part
	cout << "please select one to edit or 0 to go back to menu\n";
	cin >> res;
	if (res==0){
		menu();
	}
	else{
		cl.set_companyId("1");
		cl.set_clientId("1");
		cl.set_name("Chris");
		cl.set_title("Manager");
		cl.set_emailAddress("chris@gmail.com");
		cl.set_phoneNumber("2899924367");
		cl.set_physicalAddress("180 Duke St");
		cl.set_notes("None");
		clVec.push_back(cl);
		showClientDetail();
		editClient();
	}
}
void showCompanysDetail(void) {
	int res = 0;
	// company name and sector
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
		co.set_companyId("1");
		co.set_name("Google");
		co.set_address("1 google drive");
		co.set_sector("sector 1");
		coVec.push_back(co);
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
	char res = 'N';
	cout << "Is it for an existing client(Y/N)";
	cin >> res;
	if (res == 'Y'){
		string client;
		cout << "Please enter the client ID:";
		cin >> client;
		//check client and company
		if (client == cl.get_clientId()){
			cout << "The client and your company exists.\n";
		}
		else{
			// else back to menu
			cout << "The client and company doesn't exist.\n";
			menu();
		}
	}
	else{
		cout << "Is the associated company is within its records(Y/N)";
		cin >> res;
		if (res == 'Y'){
			//check company
			if (co.get_name() == company){
				char name[20];
				char title[20];
				char emailAddress[20];
				char phoneNumber[20];
				char physicalAddress[20];
				char notes[20];
				cout << "Your company exists.Please provide information of the client:\n";
				cout << "Please enter the name:";
				cin >> name;
				cout << "Please enter the title:";
				cin >> title;
				cout << "Please enter the email address:";
				cin >> emailAddress;
				cout << "Please enter the phone number:";
				cin >> phoneNumber;
				cout << "Please enter the physical address:";
				cin >> physicalAddress;
				cout << "Please enter the notes:";
				cin >> notes;
				cl.set_name(name);
				cl.set_title(title);
				cl.set_emailAddress(emailAddress);
				cl.set_phoneNumber(phoneNumber);
				cl.set_physicalAddress(physicalAddress);
				cl.set_notes(notes);
				// add to vector
				clVec.push_back(cl);
			}
			else{
				// else back to menu
				cout << "The client and company doesn't exist.\n";
				menu();
			}
		}
		else{
			// company
			char Cname[20];
			char address[20];
			char sector[20];
			cout << "Please provide information of the company:\n";
			cout << "Please enter the name:";
			cin >> Cname;
			cout << "Please enter the address:";
			cin >> address;
			cout << "Please enter the sector:";
			cin >> sector;

			co.set_name(Cname);
			co.set_address(address);
			// add to vector
			coVec.push_back(co);

			// client
			char name[20];
			char title[20];
			char emailAddress[20];
			char phoneNumber[20];
			char physicalAddress[20];
			char notes[20];
			cout << "Your company exists.Please provide information of the client:\n";
			cout << "Please enter the name:";
			cin >> name;
			cout << "Please enter the title:";
			cin >> title;
			cout << "Please enter the email address:";
			cin >> emailAddress;
			cout << "Please enter the phone number:";
			cin >> phoneNumber;
			cout << "Please enter the physical address:";
			cin >> physicalAddress;
			cout << "Please enter the notes:";
			cin >> notes;

			cl.set_name(name);
			cl.set_title(title);
			cl.set_emailAddress(emailAddress);
			cl.set_phoneNumber(phoneNumber);
			cl.set_physicalAddress(physicalAddress);
			cl.set_notes(notes);
			// add to vector
			clVec.push_back(cl);
		}
	}

	// create case
	char type[20];
	char detail[20];
	cout << "Please enter the type:";
	cin >> type;
	cout << "Please enter the detail:";
	cin >> detail;
	c.set_type(type);
	c.set_details(detail);
	c.set_clientId(cl.get_clientId());
	c.set_repId(repId);
	// add to vector
	cVec.push_back(c);

	// success
	cout << "Case created successfully and the case ID is 12.\nDo you want to create new record?(Y/N)";
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






