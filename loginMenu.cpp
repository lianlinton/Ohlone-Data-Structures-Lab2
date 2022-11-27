#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "loginMenu.h"
#include "login.cpp"
#include "menu.cpp"
#include "utils.cpp"
#include "loginException.h"

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

LoginMenu::~LoginMenu() {
	inFile.close();
}

void LoginMenu::initUserData() {
	//string filename = "WRONG FILE";
    string filename = USERS_DATA;
    int count = 0;
    FileException except;
    while (true){
        try{
            openFile(inFile, filename);
            if (inFile.fail()){
                throw except;
            }
            break;
        } catch (exception &e){
            count++;
            if (count > 3){
                break;
            }
            cout << except.what() << endl;
            cout << "Enter filename: " << endl;
            cin >> filename;
        }
    }

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
		_login.setUsername(username);
		_login.setPassword(password);
		users.push_back(_login);
	}

	inFile.clear();
}

bool LoginMenu::authenticate() {
	bool valid = false;
	for (int i = 0; i < (int) users.size(); i++) {
		if (login.getUsername() == users.at(i).getUsername() &&
			login.getPassword() == users.at(i).getPassword()) {			
			valid = true;
			break;
		}
	}
	return valid;
}

bool LoginMenu::doLogin() {
	int attempt = 0;
	LoginException except;
	while (true){
		try {
			string username, password;
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
			login.setUsername(username);
			login.setPassword(password);
			cout << endl;
			if (authenticate()) {
				return true;
			} else {
				throw except;
			}
		} catch (exception &e){
			cout << except.what() << endl;
			attempt++;
			if (attempt > 3){
				return false;
			}
		}
	}
	return false;
}

void LoginMenu::doCreate() {
	// TODO: Lab 5 - create new user
}


void LoginMenu::doReset() {
	// TODO: Lab 5 - change password
}

void LoginMenu::doLogout() {
	// TODO: Lab 5 - save loginDateTime/logoutDateTime to USERS_DATA
};

/**
* Save to file
*/
void LoginMenu::doSave() {
	// TODO
}