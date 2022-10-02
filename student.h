/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

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

	private: 
		int id;

};
