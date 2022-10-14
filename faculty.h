/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Base class is Person class with specific data attached for faculty members.
 *******************************************************/

#pragma once
#include "person.h"

class Faculty : public Person {
	public: 
		//Accessor Functions
		string getID() const{
			return this->id;
		};
		string getDepartment() const{
			return this->department;
		};

		//Mutator Functions
		void setID(string id){
			this->id = id;
		};
		void setDepartment(string department){
			this->department = department;
		};

		/*friend ostream& operator<<(ostream& out, Faculty a){
			out << a.getFirstName() << " " << a.getLastName() << "("
				<< a.getDepartment() << " ";
			return out;
		};*/

		void printFacultyInfo(){
			cout << "Faculty: " << firstName << " " << lastName << endl;
			cout << "ID: " << id <<  "Department: " << department << endl;
			cout << "Address: " << address << endl;
		}

	
	private: 
		string id;
		string department;
	
};
