/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Person base class for both Student and Faculty classes
 *******************************************************/
#pragma once
#include <string>

using namespace std;
class Person {
	public: 
		//Mutator Methods
		void setFirstName(string firstName){
			this->firstName = firstName;
		}
		void setLastName(string lastName){
			this->lastName = lastName;
		}
		void setAddress(string address){
			this-> address = address;
		}
		void setCity(string city){
			this-> city = city;
		}
		void setState(string state){
			this-> state = state;
		}
		void setEmail(string email){
			this-> email = email;
		}

		void setZip(int zip){
			this-> zip = zip;
		}

		void setPhoneNumber(string phone){
			this->phone = phone;
		};
		
		//Accessor Methods
		string getFirstName() const{
			return firstName;
		};
		string getLastName() const{
			return lastName;
		};
		string getAddress() const{
			return address;
		};
		string getCity() const{
			return city;
		};
		int getZip() const{
			return zip;
		};
		string getState() const{
			return state;
		};
		string getNumber() const{
			return phone;
		};
		string getEmail() const{
			return email;
		};

		//Operators
		//bool operator== (const Person& other) const;
	protected:
    	string firstName; // first name
    	string lastName; // last name
    	string address; // student address
    	string city; // student's city
    	string state; // student's state
    	int zip; // student zip code
    	string phone; // student's phone number
		string email;

};