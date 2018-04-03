

#include "stdafx.h"
#include <iostream>
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

int main(int argc, char** argv) {
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
			// if have res
			showCasesDetail();
			editClient();
			// else
			searchFail();
			break;

		case 2:
			searchInput();
			// search
			// if have res
			showClientsDetail();
			// else
			searchFail();
			break;

		case 3:
			searchInput();
			// search
			// if have res
			showCompanysDetail();
			// else
			searchFail();
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
		if (!true){
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


void editClient(void) {
	char res = 'N';
	do {
		editClientMenu();

		switch (choice3){

		case 1:
			// edit the detials here
			do {
				char name[20];
				cout << "Please enter new name\n";
				cin >> name;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			editSaved();
			break;

		case 2:
			// edit the detials here
			do {
				char address[20];
				cout << "Please enter new address\n";
				cin >> address;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			editSaved();
			break;

		case 3:
			// edit the detials here
			do {
				char sector[20];
				cout << "Please enter new sector\n";
				cin >> sector;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
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

void editCompany(void) {
	char res = 'N';
	do {
		editCompanyMenu();

		switch (choice3){

		case 1:
			// edit the name here
			do {
				char name[20];
				cout << "Please enter new name\n";
				cin >> name;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			editSaved();
			break;

		case 2:
			// edit the title here
			do {
				char title[20];
				cout << "Please enter new title\n";
				cin >> title;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			editSaved();
			break;

		case 3:
			// edit the email address here
			do {
				char emailAddress[20];
				cout << "Please enter new email address\n";
				cin >> emailAddress;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			editSaved();
			break;

		case 4:
			// edit the phone number here
			do {
				char phoneNumber[20];
				cout << "Please enter new phone number\n";
				cin >> phoneNumber;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			editSaved();
			break;

		case 5:
			// edit the physical address here
			do {
				char physicalAddress[20];
				cout << "Please enter new physical address\n";
				cin >> physicalAddress;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			editSaved();
			break;

		case 6:
			// edit the notes here
			do {
				char notes[20];
				cout << "Please enter new email notes\n";
				cin >> notes;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
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
	cout << "details\n";
}

// show list of objs after search and selection for one of them to edit
void showCasesDetail(void) {
	int res = 0;
	// Case ID, Client Name, Representative Name and Representative Name
	cout << "details\n";
	// selection part
	cout << "please select one to edit or 0 to go back to menu\n";
	cin >> res;
	if (res == 0){
		menu();
	}
	else{
		editCase();
	}
}
void showClientsDetail(void) {
	int res = 0;
	// Client Name, Title and associated Company Name
	cout << "details\n";
	// selection part
	cout << "please select one to edit or 0 to go back to menu\n";
	cin >> res;
	if (res==0){
		menu();
	}
	else{
		editClient();
	}
}
void showCompanysDetail(void) {
	int res = 0;
	// company name and sector
	cout << "details";
	// selection part
	cout << "please select one to edit or 0 to go back to menu\n";
	cin >> res;
	if (res == 0){
		menu();
	}
	else{
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
		char client[20];
		cout << "Please enter the client ID:";
		cin >> client;
		//check client and company
		if (true){
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
			if (true){
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
		}
	}

	// create case
	char type[20];
	char detail[20];
	cout << "Please enter the type:";
	cin >> type;
	cout << "Please enter the detail:";
	cin >> detail;

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


void editCase(void) {
	char res = 'N';
	do {
		editCaseMenu();

		switch (choice3){

		case 1:
			// edit the detials here
			do {
				char details[20];
				cout << "Please enter new details\n";
				cin >> details;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
			editSaved();
			break;

		case 2:
			// edit the type here
			do {
				char type[20];
				cout << "Please enter new type\n";
				cin >> type;
				cout << "Confirm change?(Y/N)";
				cin >> res;
			} while (res != 'Y');
			//update
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



