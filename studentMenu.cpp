#include "menu.h"
#include "studentMenu.h"
#include "dateType.h"
#include <typeinfo>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

StudentMenu:: StudentMenu() : Menu("Student Menu"){
	addOption("1) Select a student");
	addOption("2) View student details");
	addOption("3) Add a student");
	addOption("4) Edit a student");
	addOption("5) Delete a student");
    addOption("x) Exit");
	list = new OrderedArrayListType<Student*>();
	pStudent = nullptr;
	init();
}

StudentMenu::~StudentMenu(){
	for (int i = 0; i < (int) list->listSize(); i++){
		Student *p;
		list->retrieveAt(i, p);
		i++;
	}
	delete list;
}

void StudentMenu::init(){
    ifstream inFile;
	inFile.open(STUDENT_DATA);
    string id;
	string firstName; 
	string lastName; 
	string address; 
	string city; 
	string state; 
	string zip; 
	string phone;
	string email;
	//2,Yong,Gao,CS,43600 Mission Blvd.,Fremont,CA,94538,ygao@ohlone.edu,510-659-6000
	string line = "";
	while (getline(inFile, line)) {
		stringstream ss(line);
		getline(ss, id, ',');
		getline(ss, firstName, ',');
		getline(ss, lastName, ',');
		getline(ss, address, ',');
		getline(ss, city, ',');
		getline(ss, state, ',');
		getline(ss, zip, ',');
		getline(ss, email, ',');
		getline(ss, phone, ',');
		//cout << phone << endl;
		Student* _student = new Student();
		int num = stoi(id);
		_student->setID(num);
		_student->setFirstName(firstName);
		_student->setLastName(lastName);
		_student->setAddress(address);
		_student->setCity(city);
		_student->setState(state);
		num = stoi(zip);
		_student->setZip(num);
		_student->setEmail(email);
		_student->setPhoneNumber(phone);
		list->insertEnd(_student);
	}
	inFile.close();
}

void StudentMenu::doList(){
	//cout << "Here!!!" << endl;
	Menu c("List of Students");
	Student* p;
	int count = 1;
	for (int i =1; i <= list->listSize(); i++){
		list->retrieveAt(i-1,p);
		//cout << "p Name: "<< i << p->getName() << endl;
		c.addOption(to_string(count) + ") "+ p->getFirstName() + " " + p->getLastName() + " " + to_string(p->getID()));
		count++;
	}
	int input = c.getInput();
	list->retrieveAt(input-1, p);
	pStudent = p;
}

void StudentMenu::doView(){
	if (pStudent == nullptr){
		doList();
	}
	pStudent->printStudentInfo();
}

void StudentMenu::doEdit(){
	if (pStudent == nullptr){
		doList();
	} 
	Student* p = pStudent;
	string temp;
	cout << "Enter new address (" + p->getAddress() << "):";
	cin.ignore();
	getline(cin, temp);
	if (!temp.empty()){
		p->setAddress(temp);
	}
	p->printStudentInfo();
}

void StudentMenu::doAdd(){
    string id;
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

	Student* _student = new Student();
    int num = stoi(id);
    _student->setID(num);
    _student->setFirstName(firstName);
    _student->setLastName(lastName);
    _student->setAddress(address);
    _student->setCity(city);
    _student->setState(state);
    num = stoi(zip);
    _student->setZip(num);
    _student->setEmail(email);
    _student->setPhoneNumber(phone);
    list->insertEnd(_student);
    pStudent = _student;
}

void StudentMenu::doDelete(){
	if (pStudent == nullptr){
		doList();
	}
	list->remove(pStudent);
}
