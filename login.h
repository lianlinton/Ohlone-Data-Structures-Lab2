/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Login class stores the information of one user. 
 *******************************************************/
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "dateType.cpp"

using namespace std;

class Login {
    public:
        Login(){

        };
        //Accessor Methods
        void setUserName(string name) {
            username = name;
        };
        void setPassword(string pass) {
            password = pass;
        };
        //Mutator Methods
        string getUserName() {
            return username;
        };
        string getPassword() {
            return password;
        };
        //Creates a Login object
        void createLogin(string username, string password, DateTime loginDateTime, DateTime logoutDateTime){
            this->username = username;
            this->password = password;
            this->loginDateTime = loginDateTime;
            this->logoutDateTime = logoutDateTime;
        };
        void canvasLogin();

    private:
       string username;
       string password;
       DateTime loginDateTime;
       DateTime logoutDateTime;
};
