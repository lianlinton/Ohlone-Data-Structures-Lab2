#pragma once
#include <sstream>
#include "menu.cpp"
#include "studentMenu.h"
#include "studentType.cpp"
#include "linkedQueue.h"
#include "utils.cpp"

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

        //Student s;
        Student* p = new Student();
        mapStudent.insert(pair<string, Student*>(sid, p));
        p->setId(stoi(sid));
        p->setFirstName(firstName);
        p->setLastName(lastName);
        p->setAddress(address);
        p->setCity(city);
        p->setState(state);
        p->setZip(zip);
        p->setPhone(phoneNumber);
        p->setEmail(email);
        list->addQueue(*p);
    }
    inFile.clear();
}

void StudentMenu::doList() {
    cout << "***** Students *****" << endl;
    //Make a copy of the stack to go through each element
    LinkedQueueType<Student> tmp = *list;
    while (!tmp.isEmptyQueue())  {
        //Student s = tmp.front();
        tmp.front().print();
        tmp.deleteQueue();
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
    /*string sid;
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phoneNumber;
    string email;

    string studentLine = "";

    //Student s;
    Student* p = new Student();
    mapStudent.insert(pair<string, Student*>(sid, p));
    p->setId(stoi(sid));
    p->setFirstName(firstName);
    p->setLastName(lastName);
    p->setAddress(address);
    p->setCity(city);
    p->setState(state);
    p->setZip(zip);
    p->setPhone(phoneNumber);
    p->setEmail(email);
    list->addQueue(*p);*/
}

void StudentMenu::doEdit() {
    cout << "Enter student Id: ";
    string sid;
    cin >> sid;
    Student *p = mapStudent[sid];
}

void StudentMenu::doDelete() {
   cout << "Enter student Id: ";
   string sid;
   cin >> sid;
   delete mapStudent[sid];
}

/**
* Save to file
*/
void StudentMenu::doSave() {
    cout << "Saving... " << STUDENT_DATA << endl;
    // TODO
}