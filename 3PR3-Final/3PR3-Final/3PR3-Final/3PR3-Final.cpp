// 3PR3-Final.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
cout << endl;
cout << "Running SELECT * FROM dbo.`case`;" << endl;
 

try {
    sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;
  sql::PreparedStatement *prep_stmt;

  /* Create a connection */
  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
  /* Connect to the MySQL test database */
  con->setSchema("dbo");

  stmt = con->createStatement();
  res = stmt->executeQuery("SELECT * FROM dbo.`case`;"); // replace with your statement
  while (res->next()) {
  cout << ", details = '" << res->getString("details") << "'" << endl;
    
  }
   delete res;
  delete stmt;
//just for details in case table 
  prep_stmt  = con->prepareStatement("INSERT INTO dbo.`case`(details) VALUES (?)");

	prep_stmt->setString(1, "testing details info");
	prep_stmt->execute();
	cout << "insert executed";
  delete prep_stmt ;


  delete con;

} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line " << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}
int h;
cout << endl;
cin >> h ;
return EXIT_SUCCESS;
}

