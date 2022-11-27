#pragma once
#include "person.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student: public Person{
public:
	Student();
	Student(const Person& otherObject);
	~Student(){};

	string getFullName();

	void print() const;

	Student& operator=(const Student& other); // Lab 5

	//Overloaded operators
	bool operator==(const Student&) const;
	bool operator!=(const Student&) const;
	bool operator>(const Student&) const;
	bool operator<(const Student&) const;
	bool operator>=(const Student&) const;
	bool operator<=(const Student&) const;

private:
    // string studentID; lab 5 use id in class Person
   

};
