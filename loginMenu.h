#pragma once
#include <fstream>
#include "menu.h"
#include "login.h"

using namespace std;

const string USERS_DATA = "users.csv";

enum LOGIN_MENU_OPTION {
	LOGIN='1',
	CREATE='2',
	RESET='3',
	EXIT='x'
};

class LoginMenu : public Menu {

public: 
	LoginMenu();
	~LoginMenu();

	bool doLogin();
	void doLogout();
	void doCreate();
	void doReset();
	void doSave();			// TODO

	

private:
	fstream inFile;
	Login login;
	vector<Login> users;

	void initUserData();
	bool authenticate();
};