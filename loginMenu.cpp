/*******************************************************

 * Program Name: Lab 4 Project

 * Author: Lian Elsa Linton

 * Date: October 14, 2022

 * Description: Login class loads the users.csv file and updates a vector with Login information
 *******************************************************/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "loginMenu.h"
#include "menu.cpp"
#include <ctime>   
//#include "users.csv"

using namespace std;

LoginMenu::LoginMenu() 
    : Menu("Login Menu") {
    addOption("1) Login");
    addOption("2) Create New Account");
    addOption("3) Reset Password");
    addOption("x) Exit Login");

	// populate all users.csv
	initUserData();
};

void LoginMenu::initUserData() {
	ifstream inFile;
	inFile.open(USERS);

	string  username;
	string  password;
	string  loginDateTime;
	string  logoutDateTime;

	string line = "";
	while (getline(inFile, line)) {
		stringstream ss(line);
		getline(ss, username, ',');
		getline(ss, password, ',');
		getline(ss, loginDateTime, ',');
		getline(ss, logoutDateTime, ',');
		Login _login;
		//Login* login = new Login();
		_login.setUserName(username);
		_login.setPassword(password);

		users.push_back(_login);
	}

	inFile.close();
}

bool LoginMenu::authenticate() {
	bool valid = false;
	for (int i = 0; i < (int) users.size(); i++) {
		if (login.getUserName() == users.at(i).getUserName() &&
			login.getPassword() == users.at(i).getPassword()) {
			valid = true;
			break;
		}
	}
	return valid;
}

bool LoginMenu::doLogin() {
	int attempt = 0;
	do {
		string username, password;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		login.setUserName(username);
		login.setPassword(password);
		cout << endl;
		if (authenticate()) {
			return true;
		}
	} while (++attempt < 3);
	return false;
}

void LoginMenu::doCreate() {

}


void LoginMenu::doReset() {

}

