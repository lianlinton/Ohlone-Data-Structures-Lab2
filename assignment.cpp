#include "dateTime.cpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "assignment.h"
#include "stoiException.h"

using namespace std;
stoiException except;

Assignment::Assignment() {
	points = 0;
	possiblePoints = 0;
	status = 0;
}

void Assignment::setAvailableDate(string date) {
	availableDate.setDateTime(date); 
};

void Assignment::setDueDate(string date) {
	dueDate.setDateTime(date);
};

//Return the course information as a string in CSV format
string Assignment::toCSV() {
	return getName() + "," + getAvailableDate().toString() + "," + getDueDate().toString() + ","
		+ to_string(getPossiblePoint()) + "," + to_string(getPoint()) + "," + to_string(isCompleted());
}

bool Assignment::operator >= (const Assignment& a) const {
	return (name >= a.name);
}

bool Assignment::operator == (const Assignment& a) const {
	return (name == a.name);
}

Assignment& Assignment::operator=(const Assignment& other) {
	
	name = other.name;
	availableDate = DateTime(other.availableDate);
	dueDate = DateTime(other.dueDate);
	possiblePoints = other.possiblePoints;
	points = other.points;
	status = other.status;
	
	return *this;
}

void Assignment::printHeader() {
	cout << left << setw(40) << "Name";
	cout << setw(15) << "Available";
	cout << setw(15) << "Due";
	cout << setw(10) << "Possible";
	cout << setw(10) << "Point";
	cout << setw(10) << "Status" << endl;
}

ostream& operator<<(ostream& osObject, Assignment& a) {
	osObject << left << setw(40) << a.getName();
	osObject << setw(15) << a.getAvailableDate().getDate().toString();
	osObject << setw(15) << a.getDueDate().getDate().toString();
	osObject << setw(10) << a.getPossiblePoint();
	osObject << setw(10) << a.getPoint();
	osObject << setw(10) << a.getStatus();
	return osObject;
}

istream& operator>>(istream& in, Assignment& a) {
	string line;
	string s = a.getName() != "" ? "(" + a.getName() + ")" : "";
	cout << "Enter assignment name " << s << ": ";
	in.ignore();
	getline(in, line);
	if (!line.empty()) {
		a.setName(line);
	}
	s = !a.getAvailableDate().toString().empty() ? a.getAvailableDate().toString() : "MM/DD/YYYY";
	s = "(" + s + ")";
	cout << "Enter available date " << s << ": ";
	getline(in, line);
	if (!line.empty()) {
		a.setAvailableDate(line);
	}
	s = !a.getDueDate().toString().empty() ? a.getDueDate().toString() : "MM/DD/YYYY";
	s = "(" + s + ")";
	cout << "Enter due date " << s << ": ";
	getline(in, line);
	if (!line.empty()) {
		a.setDueDate(line);
	}
	s = a.getPossiblePoint() > 0 ? "(" + to_string(a.getPossiblePoint()) + ")" : "";
	cout << "Enter possible points " << s << ": ";
	getline(in, line);
	if (!line.empty()) {
		try {
			try {
				a.setPossiblePoint(stoi(line));
			} catch(exception& e){
				throw except;
			}
        } catch(stoiException& e){
            cout << e.what() << endl;
        }
	}
	s = a.getPoint() > 0 ? "(" + to_string(a.getPoint()) + ")" : "";
	cout << "Enter points " << s << ": ";
	getline(in, line);
	if (!line.empty()) {
		try {
			try {
				a.setPoint(stoi(line));
			} catch(exception& e){
				throw except;
			}
        } catch(stoiException& e){
            cout << e.what() << endl;
        }
	}
	cout << "Enter status" << " (0=Pending; 1=DONE): ";
	getline(in, line);
	if (!line.empty()) {
		try {
			try {
				a.setStatus(stoi(line));
			} catch(exception& e){
				throw except;
			}
        } catch(stoiException& e){
            cout << e.what() << endl;
        }
	}

	return in;
}