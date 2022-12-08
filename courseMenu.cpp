#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "menu.cpp"
#include "courseMenu.h"
//#include "unorderedArrayListType.h"
#include "facultyMenu.cpp"
#include "courseListType.cpp"
#include "utils.cpp"
#include "fileException.h"
#include "stoiException.h"

using namespace std;

CourseMenu::CourseMenu()
    : Menu("Course Menu") {
    addOption("1) Select a course from the list of courses"); // Lab 5 - 1) sortBy any field in class Course; 2) use FacultyMenu to set the faculty info
    addOption("2) View course details");
    addOption("3) Add a course");   // Lab 5 - use FacultyMenu to select a faculty to add 
    addOption("4) Edit a course");  // Lab 5 - use FacultyMenu to select a faculty to edit
    addOption("5) Delete a course");
    addOption("x) Exit");

    pCourse = nullptr;    
    list = new CourseListType();    // Lab 5 UnorderedArrayListType to CourselistType
     init();
};

CourseMenu::~CourseMenu() {    
    delete list;
    inFile.close();
}

/**
* 
* Read/populate course_data.csv into the list
*/
void CourseMenu::init() {
    string filename = COURSE_DATA;
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
            cout << "Enter filename: ";
            cin.ignore();
            cin >> filename;
        }
    }

    string term;
    string year;
    string startDate; // convert previous date string to class DateType
    string endDate;  // convert previous date string to class DateType
    string name;
    string section;
    string id = "";
    string meetDays;
    string location;
    string meetInfo;
    string instructor;
    string units;

    stoiException stoixcept;

    string line = "";
    while (getline(inFile, line)) {
        stringstream ss(line);
        getline(ss, term, ',');
        getline(ss, year, ',');
        getline(ss, startDate, ',');
        getline(ss, endDate, ',');
        getline(ss, name, ',');
        getline(ss, section, ',');
        getline(ss, id, ',');
        getline(ss, meetDays, ',');
        getline(ss, location, ',');
        getline(ss, meetInfo, ',');
        getline(ss, instructor, ',');
        getline(ss, units, ',');
        
        Course c;
        Course* p = &c;
        try {
            p->setTerm(term);
            try {
				p->setYear(stoi(year));
			} catch(exception& e){
				throw stoixcept;
			}
            p->setStartDate(startDate);
            p->setEndDate(endDate);
            p->setName(name);
            p->setSection(section);
            p->setId(id);
            p->setMeetDays(meetDays);
            p->setLocation(location);
            p->setMeetInfo(meetInfo);
            p->setInstructor(instructor);
            // Lab 5 - find and update faculty
            Faculty* f = facultyMenu.find(p->getInstructor());
            p->setInstructor(*f);
            try {
				p->setUnits(stoi(units));
			} catch(exception& e){
				throw stoixcept;
			}
            list->insertEnd(*p);
        } catch(stoiException& e){
            cout << e.what() << endl;
        }
    }
    inFile.clear();
    inFile.close();
}

void CourseMenu::doList() {
    Menu menu("List of Courses");
    Course* p = nullptr;
    cin.ignore();
    for (int i = 1; i <= list->listSize(); i++) {
        //list->retrieveAt(i - 1, c);
        p = list->at(i - 1);
        menu.addOption(p->getTerm() + " " + to_string(p->getYear()) + " " + p->getSection() + " " + p->getName());
    }
    int input = menu.getInput();
    //list->retrieveAt(input - 1, c);
    p = list->at(input - 1);
    this->selectedCourse(*p);
}

void CourseMenu::doView() {
    if (pCourse == nullptr) {        
        doList();
    }
    pCourse->print();
}

void CourseMenu::doAdd() {
    //Course* p = new Course();
    Course c;    
    Course* p = &c;

    string term;
    string year;
    string startDate; // convert previous date string to class DateType
    string endDate;  // convert previous date string to class DateType
    string name;
    string section;
    string id;
    string meetDays;
    string location;
    string meetInfo;
    string instructor;
    string units;
    stoiException stoixcept;

    cout << "Enter Term: ";
    cin >> term;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter start date (MM/DD/YYYY): ";
    cin >> startDate;
    cout << "Enter end date (MM/DD/YYYY): ";
    cin >> endDate;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter section: ";
    cin >> section;
    cout << "Enter course Id: ";
    cin >> id;
    cin.ignore();
    cout << "Enter meeting days: ";
    cin >> meetDays;
    cout << "Enter meeting location: ";
    cin >> location;
    cout << "Enter meeting information: ";
    cin >> meetInfo;
    cout << "Enter instructor id: ";
    cin >> instructor;
    cout << "Enter units: ";
    cin >> units;
    try {
        p->setTerm(term);
        try {
            p->setYear(stoi(year));
        } catch(exception& e){
            throw stoixcept;
        }
        p->setStartDate(startDate);
        p->setEndDate(endDate);
        p->setName(name);
        p->setSection(section);
        p->setId(id);
        p->setMeetDays(meetDays);
        p->setLocation(location);
        p->setMeetInfo(meetInfo);
        p->setInstructor(instructor);
        // Lab 5 - find and update faculty
        Faculty* f = facultyMenu.find(p->getInstructor());
        p->setInstructor(*f);
        try {
            p->setUnits(stoi(units));
        } catch(exception& e){
            throw stoixcept;
        }
        list->insertEnd(*p);
    } catch(stoiException& e){
        cout << e.what() << endl;
    }
    this->selectedCourse(*p);



}

void CourseMenu::doEdit() {
    if (pCourse == nullptr) {
        doList();
    }
    Course* p = pCourse;

    string temp;
    cout << "Enter new term or default  (" + p->getTerm() + "): ";
    cin.ignore();
    getline(cin, temp);

    if (!temp.empty()) {
        p->setTerm(temp);
    }
    
    p->print();
}

void CourseMenu::doDelete() {
    if (pCourse == nullptr) {
        doList();
    }
    getSelectedCourse().print();
    list->remove(getSelectedCourse());
    pCourse = nullptr;
}

void CourseMenu::doFacultyMenu() {    
    char option = FACULTY_MENU_OPTION::FACULTY_EDIT;
    do {
        option = facultyMenu.getOption();

        if (option == FACULTY_MENU_OPTION::FACULTY_LIST) {
            facultyMenu.doList();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_VIEW) {
            facultyMenu.doView();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_ADD) {
            facultyMenu.doAdd();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_EDIT) {
            facultyMenu.doEdit();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_DELETE) {
            facultyMenu.doDelete();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_EXIT) {
            // TODO facultyMenu.doSave();
            cout << "Exiting Faculty Menu" << endl;
        }
    } while (option != FACULTY_MENU_OPTION::FACULTY_EXIT);
}

void CourseMenu::doSortedList() {    
    // Sortby the list
    list->sortBy();

    // show list    
    list->print();
}

/**
* Save to file
*/
void CourseMenu::doSave() {
    cout << "Saving... " << COURSE_DATA << endl;
    string filename = COURSE_DATA;
    inFile.open(filename);
    if (inFile.is_open()) {
        Course* p;
        for (int i = 1; i <= list->listSize(); i++) {
            //list->retrieveAt(i - 1, p);
            p = list->at(i - 1);
            inFile << p->toCSV() << endl;
        }
    }
    else {
        cerr << "Failed to open file : " << COURSE_DATA
            << " (errno " << errno << ")" << endl;
    }
    inFile.close();
    cout << "Save!!!" << endl << endl;
    
}