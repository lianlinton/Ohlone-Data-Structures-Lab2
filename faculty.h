/*******************************************************

 * Program Name: Lab2 Project

 * Author: Lian Elsa Linton

 * Date: September 23, 2022

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

		friend ostream& operator<<(ostream& out, Faculty a){
			out << a.getFirstName() << " " << a.getLastName() << "("
				<< a.getDepartment() << " ";
			return out;
		};

		//Operators
		// operator== (const Course& other) const;
	
	private: 
		string id;
		string department;
	
};
