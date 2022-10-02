/*******************************************************

 * Program Name: Lab2 Project

 * Author: Lian Elsa Linton

 * Date: September 23, 2022

 * Description: Base class is the Menu Class and updates the user data information into Login objects in a vector array. 
 *******************************************************/
#pragma once
#include "menu.h"
#include "login.h"

using namespace std;

const string USERS = "users.csv";

class LoginMenu : public Menu {

public: 
	//Constructor
	LoginMenu();
	/**
	 * Validates the user login
	 * 
	 * @return true: if user credentials are correct
	 * @return false if user credentials are incorrect
	 */
	bool doLogin();
	/**
	 * Create a new login
	 * 
	 * @return true: if passwords match
	 * @return false: if passwords don't match or account creation was unsuccessful
	 */
	bool createLogin();
	/**
	 * Identified correct username and reset password
	 * 
	 * @return true: password was correctly reset 
	 * @return false: operation was unsuccesful
	 */
	bool resetPassword();
	/**
	 * returns user input in the form of a character
	 * 
	 * @return input 
	 */
	char getInput() const;

private:
	Login login;
	vector<Login> users;

	void initUserData();
	bool authenticate();

};