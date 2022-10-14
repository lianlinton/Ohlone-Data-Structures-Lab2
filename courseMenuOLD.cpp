/*#include "menu.h"
#include "courseMenu.h"
#include "orderedArrayListType.h"
#include "menu.cpp"
#include <typeinfo>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

CourseMenu::CourseMenu(): Menu("Course Menu") {
    addOption("1) Select a course from the list of courses");
    addOption("2) View course details");
    addOption("3) Add a course");
    addOption("4) Edit a course");
    addOption("5) Delete a course");
    addOption("x) Exit");

    list = new OrderedArrayListType<Course*>();
    init();

};

CourseMenu::~CourseMenu() {
    /*for (int i = 0; i < (int)list->listSize(); i++) {
        Course *p;
        list->retrieveAt();
        delete list->at(i);
    }
    delete list;
}

void CourseMenu::init() {
    ifstream inFile;
	inFile.open("course_data.csv");
    //Fall,2022,8/24/2022,12/20/2022,Programming W/ Data Structures,CS-124-03,085698,T TH,Online,Newark,Pham,3
	string term;        // Fall
	string year;            // 2022
	string startDate;    // 8/24/2022
	string endDate;        // 12/20/2022
	string name;        // Programming W/ Data Structures
	string sectionName;     // CS-124-03
	string sectionNumber;     //Number
	string occurrence; //T TH
	string platform;         // Online or On-Campus
	string location; //Newark
	string facultyName;         // JPHAM
	string credit;         // 3

	int counter = 0;
	string line = "";
	while (getline(inFile, line)) {
		stringstream ss(line);
		getline(ss, term, ',');
		getline(ss, year, ',');
		getline(ss, startDate, ',');
		getline(ss, endDate, ',');
		getline(ss, name, ',');
		getline(ss, sectionName, ',');
		getline(ss, sectionNumber, ',');
		getline(ss, occurrence, ',');
		getline(ss, platform, ',');
		getline(ss, location, ',');
		getline(ss, facultyName, ',');
		getline(ss, credit, ',');
		Course* _course = new Course();
		_course->setTerm(term);
		//cout << "Before Convert" << endl;
		int num = stoi(year);
		//cout << "Successfully Converted" << endl;
		_course->setYear(num);
		DateType start;
		start.setDate(startDate);
		//_course->setStartDate(start);
		DateType end;
		end.setDate(endDate);
		//_course->setEndDate(end);
		_course->setName(name);
		_course->setSectionName(sectionName);
		_course->setSectionNumber(sectionNumber);
		_course->setLocation(location);
		Faculty teacher;
		//teacher.setFirstName(" ");
		//teacher.setLastName(facultyName);
		_course->setFaculty(teacher);
		_course->setOccurrence(occurrence);
		_course->setPlatform(platform);
		num = stoi(credit);
		//cout << num << endl;
		_course->setCredit(num);
		//cout << "Course: " << sizeof(_course) << endl;
		list->insert(_course);
		//cout << "Counter:" << counter << endl;
		counter++;
	}
	inFile.close();
    //list insert->
}

void CourseMenu::doList() {
    /*Menu c("List of Courses");
    Course* p;
    for (int i = 1; i <= list-> listSize(); i++){
        list->retrieveAt(i-1, p);
       // c.addOption(p->getTerm() + " " + to_string(p->getYear())+" "+p->getSection() + " ")
    }
    int input = c.getInput();
    list->retrieveAt(input-1, p);
    this->selectedCourse(*p);
}

void CourseMenu::doView() {
    /*if (pCourse == nullptr){
        doList();
    }
    pCourse->printCourseInfo();
}

void CourseMenu::doAdd() {
    /*
    cout << "Enter course name: ";
    getline(cin, name);
    
}

void CourseMenu::doEdit() {
    /*if (pCourse == nullptr){
        doList();
    }
    Course* p = pCourse;
    string temp;
    cout << "Enter new term (" + p->getTerm() << "):";
    cin.ignore();
    getline(cin, temp);
    if (!temp.empty()){
        p->setTerm(temp);
    }
    p->printCourseInfo();
}

void CourseMenu::doDelete() {
    /*if (pCourse == nullptr){
        doList();
    } 
    list->remove(pCourse);
    
}
*/