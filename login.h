#pragma once
#include <string>
#include "dateTime.h"

using namespace std;

class Login {
    public:
        Login();
        ~Login() {};

		//Mutator member functions
		void setUsername(string name) {
			username = name;
		};
		void setPassword(string pass) {
			password = pass;
		};

		void setLoginTime(string s);
		void setLoginTime(DateTime& d) {
			loginDateTime = d;
		};
		void setLogoutTime(string s);
		void setLogoutTime(DateTime& d) {
			logoutDateTime = d;
		};
		//
		
		//Accessor member functions
		string getUsername() const { return username; };
		string getPassword() const { return password; };
		DateTime getLoginDate() { return loginDateTime;};
		DateTime getLogoutDate() { return logoutDateTime;};
		

		//Overloaded operators
		Login& operator=(const  Login& other);
		bool operator>=(const Login&) const;
		bool operator==(const Login&) const;

		string toCSV(){
			return username+","+password+","+loginDateTime.toString()+","+logoutDateTime.toString();
		}

    private:
       string username;
       string password;
	   DateTime loginDateTime;
	   DateTime logoutDateTime;
};
