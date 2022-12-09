#pragma once
#include <sstream>
#include "menu.cpp"
#include "studentMenu.h"
#include "studentType.cpp"
#include "linkedQueue.h"
#include "utils.cpp"
#include "stoiException.h"

StudentMenu::StudentMenu()
    : Menu("Course Menu") {
    addOption("1) Student list");   // Lab 5 - sortBy any field in class Student and Person
    addOption("2) View student details");
    addOption("3) Add a student");
    addOption("4) Edit a student");
    addOption("5) Delete a student");
    addOption("x) Exit");

    list = new LinkedQueueType<Student>();
    init();    
};

StudentMenu::~StudentMenu() {    
    map<string, Student*>::iterator it;
    for (it = mapStudent.begin(); it != mapStudent.end(); ++it){
        delete it->second;
    }
    delete list;
    inFile.close();
}

void StudentMenu::init() {
    //string filename = "WRONG FILE";
    string filename = STUDENT_DATA;
    int count = 0;
    FileException except;
    while (true){
        try{
            openFile(inFile, filename);
            if (inFile.fail()){
                throw except;
            }
            break;
        } catch (exception &e){
            count++;
            if (count > 3){
                break;
            }
            cout << except.what() << endl;
            cout << "Enter filename: " << endl;
            cin >> filename;
        }
    }
    stoiException stoiExcept;
    string sid;
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phoneNumber;
    string email;

    string studentLine = "";

    while (getline(inFile, studentLine)) {
        stringstream ss(studentLine);
        getline(ss, sid, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, address, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        getline(ss, zip, ',');
        getline(ss, phoneNumber, ',');
        getline(ss, email, ',');
        try {
            //Student s;
            Student* p = new Student();
            try {
                p->setId(stoi(sid));
            } catch(exception& e){
                throw stoiExcept;
            }
            p->setFirstName(firstName);
            p->setLastName(lastName);
            p->setAddress(address);
            p->setCity(city);
            p->setState(state);
            p->setZip(zip);
            p->setPhone(phoneNumber);
            p->setEmail(email);
            list->addQueue(*p);
            mapStudent.insert(pair<string, Student*>(sid, p));

        } catch(stoiException& e){
            cout << e.what() << endl;
        }
    }
    inFile.clear();
    inFile.close();
}

void StudentMenu::doList() {
    cout << "***** Students *****" << endl;
    //Make a copy of the stack to go through each element
    /*LinkedQueueType<Student> tmp = *list;
    while (!tmp.isEmptyQueue())  {
        //Student s = tmp.front();
        tmp.front().print();
        tmp.deleteQueue();
    }*/
    map<string, Student*>::iterator it;
    for (it = mapStudent.begin(); it != mapStudent.end(); ++it){
        it->second->print();
    }
}

void StudentMenu::doView() {
    cout << "Enter student Id: ";
    string sid;
    cin >> sid;
    Student *p = mapStudent[sid];
    if (p != nullptr){
        p->print();
    } else {
        cout << "Id not found" << endl;
    }
}

void StudentMenu::doAdd() {
    stoiException stoiExcept;
    string sid;
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phoneNumber;
    string email;

    string studentLine = "";

    cout << "Enter ID: ";
    cin.ignore();
    getline(cin, sid);
	cout << "Enter first name: ";
	//cin.ignore();
	getline(cin, firstName);
	cout << "Enter last name: ";
	//cin.ignore();
	getline(cin, lastName);
	cout << "Enter address: ";
	//cin.ignore();
	getline(cin, address);
	cout << "Enter city: ";
	getline(cin, city);
	cout << "Enter state: ";
	getline(cin, state);
	cout << "Enter zip: ";
	getline(cin, zip);
	cout << "Enter phone: ";
	getline(cin, phoneNumber);
	cout << "Enter email: ";
	getline(cin, email);

    //Student s;
    try {
        //Student s;
        Student* p = new Student();
        try {
            p->setId(stoi(sid));
        } catch(exception& e){
            throw stoiExcept;
        }
        p->setFirstName(firstName);
        p->setLastName(lastName);
        p->setAddress(address);
        p->setCity(city);
        p->setState(state);
        p->setZip(zip);
        p->setPhone(phoneNumber);
        p->setEmail(email);
        list->addQueue(*p);
        mapStudent.insert(pair<string, Student*>(sid, p));

    } catch(stoiException& e){
        cout << e.what() << endl;
    }
}

void StudentMenu::doEdit() {
    cout << "Enter student Id: ";
    string sid;
    cin >> sid;
    cout << "Enter new address: ";
    string address;
    cin >> address;
    map<string, Student*>::iterator itr;
    for (itr = mapStudent.begin(); itr != mapStudent.end(); ++itr) {
        if((itr->second)->getId() == stoi(sid)){
            (itr->second)->setAddress(address);
            cout << itr->second->getAddress() << endl;
            cout << mapStudent[sid]->getAddress() << endl;
        }
    }
    doList();
    //mapStudent[sid]->setAddress(address);
}

void StudentMenu::doDelete() {
   cout << "Enter student Id: ";
   string sid;
   cin >> sid;
   mapStudent.erase(sid);
}

/**
* Save to file
*/
void StudentMenu::doSave() {
	cout << "Saving... " << STUDENT_DATA << endl;
    string filename = STUDENT_DATA;
    inFile.open(filename);
    inFile.clear();
    if (inFile.is_open()) {
        map<string, Student*>::iterator it;
        for (it = mapStudent.begin(); it != mapStudent.end(); ++it){
            inFile << it->second->toCSV() << endl;
        }
	}
    else {
        cerr << "Failed to open file : " << STUDENT_DATA
            << " (errno " << errno << ")" << endl;
    }
    inFile.close();
    cout << "Save!!!" << endl << endl;   

}