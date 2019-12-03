#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "Database.h"
using namespace std;


Database::ShowContact() {
	try {

		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;

		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "");
		con->setSchema("library");
		stmt = con->createStatement();
		res = stmt->executeQuery("SELECT * FROM books");


		while (res->next()) {
			cout << res->getString("bookName") << endl;

		}


		delete res;
		delete stmt;
		delete con;

		//_getch();


	}


	catch (sql::SQLException &e) {
	}
}