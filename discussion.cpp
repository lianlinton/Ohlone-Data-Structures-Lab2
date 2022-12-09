#pragma once
#include "dateTime.cpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "discussion.h"

using namespace std;

Discussion::Discussion() {
	// TODO...
}

string Discussion::getText() const {
	return text;
}

string Discussion::getName() const {
	return student.getFirstName()
		+ (student.getMiddleName().empty() ? (" " + student.getMiddleName()) : "")
		+ " " + student.getLastName();
}

void Discussion::print() const {
	cout << getName() << endl;
	cout << getDateTime().toString() << endl;
	cout << getText() << endl;
	cout << "--------------------------------------------------" << endl;
}

Discussion& Discussion::operator=(const Discussion& other) {
	student.copy(other.getStudent());
	postDate.copy(other.getDateTime());
	text = other.getText();
	return *this;
}

bool Discussion::operator==(const Discussion& otherF) const {
	return getName() == otherF.getName();
}
bool Discussion::operator!=(const Discussion& otherF) const {
	return !(*this == otherF);
}

bool Discussion::operator>(const Discussion& otherF) const {
	return getName() > otherF.getName();
}
bool Discussion::operator<(const Discussion& otherF) const {
	return !(*this > otherF || *this == otherF);
}
bool Discussion::operator>=(const Discussion& otherF) const {
	return !(*this < otherF);
}
bool Discussion::operator<=(const Discussion& otherF) const {
	return !(*this > otherF);
}



ostream& operator<<(ostream& osObject, Discussion& a) {
	osObject << a.getName() << endl;
	osObject << a.getDateTime().toString() << endl;
	osObject << a.getText() << endl << endl;
	osObject << setfill('-') << setw(50) << "\n";
	osObject << endl;
	return osObject;
}

istream& operator>>(istream& in, Discussion& a) {
	// TODO
	// cin >> p;
	return in;
}

string Discussion::toCSV(){
	//Fall 2022 semester begins 08/29/2022
	//08/29/2022
	//Hello Students, The first-class meeting starts on Tuesday, 08/30/2022, at 6:30 PM, in room NC2308. Jim D. Pham
	return this->getName()+"\n"+postDate.toString()+"\n"+text;
}