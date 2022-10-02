/*******************************************************

 * Program Name: Lab2 Project

 * Author: Lian Elsa Linton

 * Date: September 23, 2022

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
	inFile.open("users.csv");

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
		_login.setUserName(username);
		_login.setPassword(password);

		users.push_back(_login);
	}

	inFile.close();
}

bool LoginMenu::createLogin(){
	//ofstream outFile;
	//outFile.open("users.csv");
	Login _account;
	string username, password, rePassword;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	cout << "Enter Password Again: ";
	cin >> rePassword;
	if (rePassword == password){
		_account.setUserName(username);
		_account.setPassword(password);
		users.push_back(_account);
		time_t t = std::time(0);
		tm* now = std::localtime(&t);
		return true;
	} else {
		cout << "Password entries do not match." << endl;
		return false;
	}
}

bool LoginMenu::resetPassword(){
	string username;
	cout << "Username: ";
	cin >> username;
	for (int i = 0; i < users.size(); i++){
		if (users.at(i).getUserName() == username){
			string password;
			cout << "User: "+users.at(i).getUserName() << endl;
			cout << "New Password: ";
			cin >> password;
			users.at(i).setPassword(password);
			return true;
		}
	}
	cout << "User not found." << endl;
	return false;
}

bool LoginMenu::authenticate() {
	bool valid = false;
	for (int i = 0; i < users.size(); i++) {
		if (login.getUserName() == users.at(i).getUserName() &&
			login.getPassword() == users.at(i).getPassword()) {
			valid = true;
			break;
		}
	}
	return valid;
}

char LoginMenu::getInput() const{
	/*char option = Menu::getInput();
	return option;*/

	char input;
    Menu::display();
    cin >> input;
    return input;
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
