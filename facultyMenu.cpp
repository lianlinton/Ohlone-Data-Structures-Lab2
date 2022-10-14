#include "menu.h"
#include "facultyMenu.h"
#include "faculty.h"
#include "dateType.h"
#include <typeinfo>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

FacultyMenu:: FacultyMenu() : Menu("Faculty Menu"){
	addOption("1) Select a faculty");
	addOption("2) View faculty details");
	addOption("3) Add a faculty");
	addOption("4) Edit a faculty");
	addOption("5) Delete a faculty");
    addOption("x) Exit");
	list = new OrderedArrayListType<Faculty*>();
	pFaculty = nullptr;
	init();
}

FacultyMenu::~FacultyMenu(){
	for (int i = 0; i < (int) list->listSize(); i++){
		Faculty *p;
		list->retrieveAt(i, p);
		i++;
	}
	delete list;
}

void FacultyMenu::init(){
    ifstream inFile;
	inFile.open(FACULTY_DATA);
    string id;
	string department;
	string firstName; 
	string lastName; 
	string address; 
	string city; 
	string state; 
	string zip; 
	string phone;
	string email;
	string line = "";
	while (getline(inFile, line)) {
		stringstream ss(line);
		getline(ss, id, ',');
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, department, ',');
		getline(ss, address, ',');
		getline(ss, city, ',');
		getline(ss, state, ',');
		getline(ss, zip, ',');
		getline(ss, email, ',');
		getline(ss, phone, ',');
		//cout << phone << endl;
		Faculty* _faculty = new Faculty();
		int num = stoi(id);
		_faculty->setID(id);
		_faculty->setFirstName(firstName);
		_faculty->setLastName(lastName);
		_faculty->setDepartment(department);
		_faculty->setAddress(address);
		_faculty->setCity(city);
		_faculty->setState(state);
		num = stoi(zip);
		_faculty->setZip(num);
		_faculty->setEmail(email);
		_faculty->setPhoneNumber(phone);
		list->insertEnd(_faculty);
	}
	inFile.close();
}

void FacultyMenu::doList(){
	//cout << "Here!!!" << endl;
	Menu c("List of Faculty");
	Faculty* p;
	int count = 1;
	for (int i =1; i <= list->listSize(); i++){
		list->retrieveAt(i-1,p);
		//cout << "p Name: "<< i << p->getName() << endl;
		c.addOption(to_string(count) + ") "+ p->getFirstName() + " " + p->getLastName() + " " + p->getID() + " Department: "+p->getDepartment());
		count++;
	}
	int input = c.getInput();
	list->retrieveAt(input-1, p);
	pFaculty = p;
}

void FacultyMenu::doView(){
	if (pFaculty == nullptr){
		doList();
	}
	pFaculty->printFacultyInfo();
}

void FacultyMenu::doEdit(){
	if (pFaculty == nullptr){
		doList();
	} 
	Faculty* p = pFaculty;
	string temp;
	cout << "Enter new address (" + p->getAddress() << "):";
	cin.ignore();
	getline(cin, temp);
	if (!temp.empty()){
		p->setAddress(temp);
	}
	p->printFacultyInfo();
}

void FacultyMenu::doAdd(){
    string id;
	string department;
	string firstName; 
	string lastName; 
	string address; 
	string city; 
	string state; 
	string zip; 
	string phone;
	string email;

    cout << "Enter ID: ";
    cin.ignore();
    getline(cin, id);
    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, department);
	cout << "Enter first name: ";
	cin.ignore();
	getline(cin, firstName);
	cout << "Enter last name: ";
	cin.ignore();
	getline(cin, lastName);
	cout << "Enter address: ";
	cin.ignore();
	getline(cin, address);
	cout << "Enter city: ";
	getline(cin, city);
	cout << "Enter state: ";
	getline(cin, state);
	cout << "Enter zip: ";
	getline(cin, zip);
	cout << "Enter phone: ";
	getline(cin, phone);
	cout << "Enter email: ";
	getline(cin, email);

	Faculty* _faculty = new Faculty();
    int num = stoi(id);
    _faculty->setID(id);
    _faculty->setFirstName(firstName);
    _faculty->setLastName(lastName);
    _faculty->setDepartment(department);
    _faculty->setAddress(address);
    _faculty->setCity(city);
    _faculty->setState(state);
    num = stoi(zip);
    _faculty->setZip(num);
    _faculty->setEmail(email);
    _faculty->setPhoneNumber(phone);
    list->insertEnd(_faculty);
    pFaculty = _faculty;
}

void FacultyMenu::doDelete(){
	if (pFaculty == nullptr){
		doList();
	}
	list->remove(pFaculty);
}
