/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Base class is the Menu Class and updates the user data information into Login objects in a vector array. 
 *******************************************************/
#pragma once
#include "menu.h"
#include "login.h"

using namespace std;

const string USERS = "users.csv";

enum LOGIN_MENU_OPTION { LOGIN='1', CREATE='2', RESET='3', EXIT='x' };

class LoginMenu : public Menu {

public: 
	LoginMenu();
	bool doLogin();
	void doCreate();
	void doReset();

private:
	Login login;
	vector<Login> users;

	void initUserData();
	bool authenticate();
};