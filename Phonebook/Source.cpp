#include <iostream>
#include<string>
#include <conio.h>
#include "Contacts.h"

using namespace std;

void LoginScreen();
void Body();

int main() {
	
	system("color 70");
	
	
	LoginScreen();
	_getch();

	return 0;
}

void LoginScreen() {
	char username[20], pwd[20];
	cout << "Login" << endl;
	cout << "Admin:";
	cin >> username;
	cout << "Password:";
	cin >> pwd;
	if (strcmp(username, "kist") == 0 & strcmp(pwd, "1234") == 0) {

		//system("cls");
		cout << "Access Granted" << endl;

		Body();

	}
	else {
		cout << "Something's wrong, try again" << endl;
	}
}


void Body() {
	Contacts c;
	int dec;
	while (9) {
		cout << "Options\n1:Show Contacts\n2:Add Contact\n3:Search Contact\n4:Edit Contact\n5:Delete Contact\n0:Exit\nYour Choice:";
		cin >> dec;
		switch (dec) {
		case 1:
			c.ShowContacts();
			break;
		case 2:
			c.AddContact();
			break;
		case 3:
			c.SearchContact();
			break;
		case 4:
			c.EditContact();
			break;
		case 5:
			c.DeleteContact();
			break;
		case 0:
			exit(0);
			break;
		}
	}
}