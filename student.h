/*******************************************************

 * Program Name: Lab 4 Project

 * Author: Lian Elsa Linton

 * Date: October 14, 2022

 * Description: Base class is Person class with student specific values like id added. 
 *******************************************************/
#pragma once
#include "person.h"

using namespace std;

class Student : public Person {
	public: 
		//Accessor Method
		int getID(){
			return id;
		};

		//Mutator Functions
		void setID(int id){
			this->id = id;
		};

		void printStudentInfo(){
			cout << "Student: " << firstName << " " << lastName << endl;
			cout << "ID: " << id << endl;
			cout << "Address: " << address << endl;
		}

	private: 
		int id;

};
