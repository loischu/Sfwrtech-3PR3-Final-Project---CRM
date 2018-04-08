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

using namespace std;
//main menu component
void mainMenu(); //view list of options
void menu(); //selecting menu choices
void search(); //search menu
void openExisting(); //open existing case menu
void createNew(); //create new case menu
void exitConfirm(); //quit the application

//search menu component
void searchMenu();// view list of options 
void search(); //selecting search choices
void searchInput(); //enter keyword after selecting choice
void showDetailsChoice();   //show certain details if results are more then one
							//user can choose to see details of result(choice show detais 1(yes), 2(no))
							// also show error for no result in this method
							//search again or return to the main menu.(search again 1, return to main menu 0)
void showCompanysDetail(); //show results of company details
void showClientsDetail(); //show results of client details
void showCasesDetail(); //show results of case details




//editing menu after search result found
void editCaseMenu();//show list of attributes to edit
void editClientMenu();//show list of attributes to edit
void editCompanyMenu();//show list of attributes to edit
void editCase(); //edit case	
void editClient();//edit client
void editCompany(); //edit company
void confirmEdit(); //confirm edit or cancel
					//return to menu or show details


// create new case
void createNewCase();  //ask user to input data and save to database

int _tmain(int argc, _TCHAR* argv[])
{
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

	//showing 3 choice of menu search,open exististing, create new case
	mainMenu();


}


void mainMenu(void) {
	
	   cout <<"-------------------Welcome to Customer Relationship Manager Application(CRM)----------------" << endl;
	   cout << "Please choose one of the Menu Options below" << endl;
       cout << "1 - Search"     << endl; 
	   cout << "2 - Open Existing Case" << endl;
       cout << "3 - Create New Case" << endl;
	   cout << "4 - Quit" << endl ;
}