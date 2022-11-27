#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "menu.h"
#include "assignment.cpp"
#include "assignmentMenu.h"
#include "unorderedArrayListType.h"
#include "utils.cpp"

using namespace std;

AssignmentMenu::AssignmentMenu()
    : Menu("Assignments Menu") {
    addOption("1) List all assignments");
    addOption("2) List pending assignments");
    addOption("3) List completed assignments");
    addOption("4) View");
    addOption("5) Add");
    addOption("6) Edit");
    addOption("7) Delete");
    addOption("x) Exit");

    pAssignment = nullptr;
    list = new UnorderedArrayListType<Assignment*>();    
    init();
};

AssignmentMenu::~AssignmentMenu() {
    int i = 0;
    while (i < list->listSize()) {
        Assignment* p;
        list->retrieveAt(i, p);
        delete p;
        i++;
    }
    delete list;
    inFile.close();
}

/**
*
* Read/populate course_data.csv into the list
*/
void AssignmentMenu::init() {   
    string filename = ASSIGNMENT_DATA;    
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

    string name;
    string availableDate;
    string dueDate;
    string possiblePoints;
    string points;
    string status;  // 1=Yes; 0=No

    string line = "";
    while (getline(inFile, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, availableDate, ',');
        getline(ss, dueDate, ',');
        getline(ss, possiblePoints, ',');
        getline(ss, points, ',');
        getline(ss, status, ',');

        Assignment* p = new Assignment();
        p->setName(name);
        p->setAvailableDate(availableDate);
        p->setDueDate(dueDate);
        p->setPossiblePoint(stoi(possiblePoints));
        p->setPoint(stoi(points));
        p->setStatus(stoi(status));
        list->insertEnd(p);
    }
    inFile.clear();
}

void AssignmentMenu::doList() {
    Menu c("Assignments");
    Assignment* p;
    for (int i = 1; i <= list->listSize(); i++) {
        list->retrieveAt(i - 1, p);
        c.addOption(p->getName());
    }
    int input = c.getInput();
    list->retrieveAt(input - 1, p);
    this->setAssignment(*p);
    cout << endl;
}

void AssignmentMenu::doListPending() {
    UnorderedArrayListType<Assignment*> tmpList;
    Assignment* p;
    for (int i = 1; i <= list->listSize(); i++) {
        list->retrieveAt(i - 1, p);
        if (!p->isCompleted()) {
            tmpList.insertEnd(p);
        }
    }    

    cout << "***** View Pending Assignments *****" << endl;
    if (tmpList.listSize() != 0) {
        Assignment::printHeader();
        for (int i = 1; i <= tmpList.listSize(); i++) {
            tmpList.retrieveAt(i - 1, p);
            cout << *p << endl;
        }
    } else {
        cout << "No Pending Assignments" << endl;
    }
    cout << endl;
}

void AssignmentMenu::doListCompleted() {
    UnorderedArrayListType<Assignment*> tmpList;
    Assignment* p;
    for (int i = 1; i <= list->listSize(); i++) {
        list->retrieveAt(i - 1, p);
        if (p->isCompleted()) {
            tmpList.insertEnd(p);
        }
    }
    cout << "***** View Completed Assignments *****" << endl;
    if (tmpList.listSize() != 0) {
        Assignment::printHeader();
        for (int i = 1; i <= tmpList.listSize(); i++) {
            tmpList.retrieveAt(i - 1, p);
            cout << *p << endl;
        }
    }
    else {
        cout << "No Completed Assignments" << endl;
    }
    cout << endl;
}

void AssignmentMenu::doView() {
    if (pAssignment == nullptr) {
        doList();
    }
    cout << "***** View Selected Assignment *****" << endl;
    Assignment a = getSelectedAssignment();
    a.printHeader();
    cout << a << endl << endl;
}

void AssignmentMenu::doAdd() {
    cout << "***** Add New Assignment *****" << endl;
    Assignment* p = new Assignment();
    cin >> *p;
    list->insertEnd(p);
}

void AssignmentMenu::doEdit() {
    if (pAssignment == nullptr) {
        doList();
    }
    cout << "***** Edit Selected Assignment *****" << endl;
    if (pAssignment != nullptr) {
        cin >> *pAssignment;
    }
    else {
        // Users need to select an assignment to edit
        doList();
        doEdit();
    }
    cout << endl;
}

void AssignmentMenu::doDelete() {
    cout << "***** Delete Assignment *****" << endl;
    if (pAssignment == nullptr) {
        doList();
    }
    string name = pAssignment->getName();
    list->remove(pAssignment);
    pAssignment = nullptr;
    cout << name << ", deleted!" << endl << endl;
}

/**
* Save to file
*/
void AssignmentMenu::doSave() {
    cout << "Saving... " << ASSIGNMENT_DATA << endl;
    if (inFile.is_open()) {
        Assignment* p;
        for (int i = 1; i <= list->listSize(); i++) {
            list->retrieveAt(i - 1, p);
            inFile << p->toCSV() << endl;
        }
    }
    else {
        cerr << "Failed to open file : " << ASSIGNMENT_DATA
            << " (errno " << errno << ")" << endl;
    }
    cout << "Save!!!" << endl << endl;
}