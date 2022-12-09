#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
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
		_login.setLoginTime(loginDateTime);
		_login.setLogoutTime(logoutDateTime);
		users.push_back(_login);
	}

	inFile.clear();
	inFile.close();
}

bool LoginMenu::authenticate() {
	bool valid = false;
	for (int i = 0; i < (int) users.size(); i++) {
		if (login.getUsername() == users.at(i).getUsername() &&
			login.getPassword() == users.at(i).getPassword()) {			
			valid = true;
			users.at(i).setLoginTime(this->currentTime());
			cout << login.getLoginDate().toString();
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
	string user;
	string password;
	cout << "Enter username: ";
	cin >> user;
	cout << "Enter password: ";
	cin >> password;
	Login _login;
	_login.setUsername(user);
	_login.setPassword(password);
	users.push_back(_login);
	users.at(users.size()-1).setLoginTime(this->currentTime());	
	users.at(users.size()-1).setLogoutTime(this->currentTime());
	doSave();	
}


void LoginMenu::doReset() {
	string user;
	string newPwd;
	cout << "Enter username: ";
	cin >> user;
	cout << "Enter new password: ";
	cin >> newPwd;
	for (int i = 0; i < (int) users.size(); i++) {
		if (user == users.at(i).getUsername()){
			users.at(i).setPassword(newPwd);			
			//valid = true;
			//cout << users.at(i).getPassword() << endl;
			users.at(i).setLoginTime(this->currentTime());	
			users.at(i).setLogoutTime(this->currentTime());	
			cout << "Success! " << endl;
			break;
		}
	}
	doSave();
}

string LoginMenu::currentTime(){
	time_t now = time(0);

	tm *ltm = localtime(&now);

	// print various components of tm structure.
	int year = 1900 + ltm->tm_year;
	int month = 1 + ltm->tm_mon;
	int day = ltm->tm_mday;
	string date;
	//9/11/2022 18:30:15,09/12/2022 20:35:45
	if (month < 10){
		if (day < 10){
			date = "0"+to_string(month)+"/0"+to_string(day)+"/"+to_string(year);
		} else {
			date = "0"+to_string(month)+"/"+to_string(day)+"/"+to_string(year);
		}
	} else {
		date = ""+to_string(month)+"/"+to_string(day)+"/"+to_string(year);
	}
	string time;
	if (ltm->tm_hour < 10){
		if (ltm->tm_min < 10){
			if (ltm->tm_sec < 10){
				time = "0"+to_string(ltm->tm_hour)+":0"+to_string(ltm->tm_min)+":0"+to_string(ltm->tm_sec);
			} else {
				time = "0"+to_string(ltm->tm_hour)+":0"+to_string(ltm->tm_min)+":"+to_string(ltm->tm_sec);
			}
		} else {
			time = "0"+to_string(ltm->tm_hour)+":"+to_string(ltm->tm_min)+":"+to_string(ltm->tm_sec);
		}
	} else {
		time = to_string(ltm->tm_hour)+":"+to_string(ltm->tm_min)+":"+to_string(ltm->tm_sec);
	}
	string datetime = date+" "+time;
	return datetime;
}

void LoginMenu::doLogout() {
	for (int i = 0; i < (int) users.size(); i++) {
		if (login.getUsername() == users.at(i).getUsername()){
			users.at(i).setLogoutTime(this->currentTime());	
			break;
		}
	}
	cout << login.getLogoutDate().toString() << endl;
	doSave();
};

/**
* Save to file
*/
void LoginMenu::doSave() {
	cout << "Saving... " << USERS_DATA << endl;
    string filename = USERS_DATA;
    inFile.open(filename);
    inFile.clear();
    if (inFile.is_open()) {
        for (int i = 0; i < (int) users.size(); i++) {
			inFile << users.at(i).toCSV() << endl;
		}
	}
    else {
        cerr << "Failed to open file : " << USERS_DATA
            << " (errno " << errno << ")" << endl;
    }
    inFile.close();
    cout << "Save!!!" << endl << endl;   
}