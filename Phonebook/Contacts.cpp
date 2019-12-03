#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <string>
#include <iostream>
#include "Contacts.h"

using namespace std;

void Contacts::ShowContacts(){
	try {

		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;

		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "");
		con->setSchema("phonebook");
		stmt = con->createStatement();
		res = stmt->executeQuery("SELECT * FROM contacts");


		while (res->next()) {
			cout << res->getString("name") <<" "<<res->getString("number")<<" "<<res->getString("email")<<" "<<res->getString("address")<<" " << res->getString("catagory") <<endl;

		}



		delete res;
		delete stmt;
		delete con;
	}
	catch (sql::SQLException &e) {
	}
}




void Contacts::AddContact() {
	try
	{
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "");
		con->setSchema("phonebook");
		stmt = con->createStatement();

		string fname, lname;
		string n;
		string number,email,address,group;

		cout << "Enter fname";
		cin >> fname;
		cout << "lname:";
		cin >> lname;
		n = fname + " " + lname;
		cout << "Number:";
		cin >> number;
		cout << "Email:";
		cin >> email;
		cout << "Address:";
		cin >> address;
		cout << "Group:";
		cin >> group;
		string query;
		query = "insert into contacts(name, number, email, address, catagory) values('" + n + "','" +number+ "','" + email + "','" + address + "','" + group + "')";
		

		//pstmt = con->prepareStatement("SELECT * FROM contacts WHERE name='?'");

		//pstmt->setString(1, n);

		res = stmt->executeQuery(query);

		while (res->next()) {
			cout << res->getString("name") << " " << res->getString("number") << " " << res->getString("email") << " " << res->getString("address") << " " << res->getString("catagory") << endl;

		}


		delete res;
		delete stmt;
		delete con;

	}
	catch (sql::SQLException &e)
	{
		/*
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		//system("cls");
		cout << "Error in SQL database";
		system("pause"); */
	}
	
}

void Contacts::SearchContact() {
	try
	{
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "");
		con->setSchema("phonebook");
		stmt = con->createStatement();

		string fname, lname;
		string n;

		cout << "Enter fname";
		cin >> fname;
		cout << "lname:";
		cin >> lname;
		n = fname + " " + lname;
		string query;
		query = "SELECT * FROM contacts WHERE name = '" + n + "'";

		//pstmt = con->prepareStatement("SELECT * FROM contacts WHERE name='?'");

		//pstmt->setString(1, n);

		res = stmt->executeQuery(query);

		while (res->next()) {
			cout << res->getString("name") << " " << res->getString("number") << " " << res->getString("email") << " " << res->getString("address") << " " << res->getString("catagory") << endl;

		}


		delete res;
		delete stmt;
		delete con;
		
	}
	catch (sql::SQLException &e)
	{
		/*
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		//system("cls");
		cout << "Error in SQL database";
		system("pause"); */
	}
}



void Contacts::EditContact() {
	try
	{
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "");
		con->setSchema("phonebook");
		stmt = con->createStatement();

		string fname, lname,efname,elname;
		string n,en;
		string number, email, address, group;
		cout << "Enter the first name of the contact you want to edit:";
		cin >> efname;
		cout << "now enter last name:";
		cin >> elname;
		en = efname + " " + elname;
		cout << "Enter new fname";
		cin >> fname;
		cout << "lname:";
		cin >> lname;
		n = fname + " " + lname;
		cout << "Number:";
		cin >> number;
		cout << "Email:";
		cin >> email;
		cout << "Address:";
		cin >> address;
		cout << "Group:";
		cin >> group;
		string query;
		query = "UPDATE contacts SET name = '"+ n +" ', number = '" + number +"', email = '" + email + "', address = '" + address +"', catagory = '" + group+ "' WHERE name='" + en +"'";


		//pstmt = con->prepareStatement("SELECT * FROM contacts WHERE name='?'");

		//pstmt->setString(1, n);

		res = stmt->executeQuery(query);

		while (res->next()) {
			cout << res->getString("name") << " " << res->getString("number") << " " << res->getString("email") << " " << res->getString("address") << " " << res->getString("catagory") << endl;

		}


		delete res;
		delete stmt;
		delete con;

	}
	catch (sql::SQLException &e)
	{
		/*
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		//system("cls");
		cout << "Error in SQL database";
		system("pause"); */
	}
	
}

void Contacts::DeleteContact() {
	try
	{
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;
		sql::PreparedStatement *pstmt;
		driver = get_driver_instance();
		con = driver->connect("tcp://127.0.0.1:3306", "root", "");
		con->setSchema("phonebook");
		stmt = con->createStatement();

		string fname, lname;
		string n;

		cout << "Enter first name you want to delete contact of:";
		cin >> fname;
		cout << "last name:";
		cin >> lname;
		n = fname + " " + lname;
		string query;
		query = "DELETE FROM contacts WHERE name = '" + n + "'";

		//pstmt = con->prepareStatement("SELECT * FROM contacts WHERE name='?'");

		//pstmt->setString(1, n);
		stmt->executeQuery(query);
		//res = stmt->executeQuery(query);

		//while (res->next()) {
			//cout << res->getString("name") << " " << res->getString("number") << " " << res->getString("email") << " " << res->getString("address") << " " << res->getString("catagory") << endl;

		//}

		cout << "Contact Deleted\n";
		//delete res;
		delete stmt;
		delete con;

		ShowContacts();

	}
	catch (sql::SQLException &e)
	{
		/*
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
		//system("cls");
		cout << "Error in SQL database";
		system("pause"); */
	}
	
}