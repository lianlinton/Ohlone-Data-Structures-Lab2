/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Handles managing the menu functions that are executed based on the user's choice. 
 *******************************************************/
#include "myCanvas.h"
#include "loginMenu.cpp"
#include "mainMenu.cpp"
#include "courseMenu.cpp"
#include <typeinfo>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>

using namespace std;
MyCanvas::MyCanvas() {
}


bool MyCanvas::doLogin() const {
	LoginMenu login;
	char option = login.getOption();
	switch (option) {
		case LOGIN_MENU_OPTION::LOGIN:
			return login.doLogin();
		case LOGIN_MENU_OPTION::CREATE:
			login.doCreate();
			break;
		case LOGIN_MENU_OPTION::RESET:
			login.doReset();
			break;
		case LOGIN_MENU_OPTION::EXIT:
			cout << "Exiting Login Menu" << endl;
			return false;
		default: {}
	}

	return false;
}

void MyCanvas::doCourseMenu() const {
	CourseMenu courseMenu;
	char option = EXIT;
	do {
		//char option = courseMenu.getOption();

		if (option == COURSE_MENU_OPTION::COURSE_LIST) {
			courseMenu.doList();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_VIEW) {
			courseMenu.doView();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_ADD) {
			courseMenu.doAdd();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_EDIT) {
			courseMenu.doEdit();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_DELETE) {
			courseMenu.doDelete();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_EXIT) {
			cout << "Exiting Course Menu" << endl;
		}
	} while (option != EXIT);

}

void MyCanvas::doMenu() const {
	// todo
	MainMenu mainMenu;
	MAIN_MENU_OPTION option = (MAIN_MENU_OPTION) mainMenu.getOption();

	if (option == MAIN_MENU_OPTION::MAIN_MENU_HOME){
		//mainMenu.doHome();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_ANNOUNCEMENT) {
		//mainMenu.doAnnouncement();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_DISCUSSION) {
		//mainMenu.doDiscussion();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_ASSIGNMENT) {
		//mainMenu.doAssignment();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_QUIZ) {
		//mainMenu.doQuiz();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_STUDENT) {
		//mainMenu.doStudentMenu();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_SYLLABUS) {

	} // else EXIT
}
/*
//Constructor
MyCanvas::MyCanvas() {
	Course *pCourse = new Course;
	MyOhlone page(pCourse);
	Faculty *pFaculty = new Faculty;
	MyOhlone page1(pFaculty);
	Student *pStudent = new Student;
	MyOhlone page2(pStudent);
	faculty = new vector<Faculty*>();
	courseList = new vector<Course*>();
	studentList = new vector<Student*>();
}


//Loading Faculty Data
void MyCanvas::initFacultyData() {
	ifstream inFile;
	inFile.open("faculty_data.csv");
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
	//2,Yong,Gao,CS,43600 Mission Blvd.,Fremont,CA,94538,ygao@ohlone.edu,510-659-6000
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
		faculty->push_back(_faculty);
	}

	inFile.close();
}

//Loading Course Data
void MyCanvas::initCourseData(){
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
		_course->setStartDate(start);
		DateType end;
		end.setDate(endDate);
		_course->setEndDate(end);
		_course->setName(name);
		_course->setSectionName(sectionName);
		_course->setSectionNumber(sectionNumber);
		_course->setLocation(location);
		Faculty teacher;
		teacher.setFirstName(" ");
		teacher.setLastName(facultyName);
		_course->setFaculty(teacher);
		_course->setOccurrence(occurrence);
		_course->setPlatform(platform);
		num = stoi(credit);
		//cout << num << endl;
		_course->setCredit(num);
		//cout << "Course: " << sizeof(_course) << endl;
		courseList->push_back(_course);
		//cout << "Counter:" << counter << endl;
		counter++;
	}
	inFile.close();
}

//Loading Student Data
void MyCanvas::initStudentData(){
	ifstream inFile;
	inFile.open("student_data.csv");
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
		studentList->push_back(_student);
	}
}

//DateType Operator Overloading
bool operator==(DateType first, DateType second){
	return first.getDate() == second.getDate();
}

bool operator!=(DateType first, DateType second){
	return first.getDate() != second.getDate();
}

//Faculty Operator Overloading
bool operator!=(Faculty first, Faculty second){
	return first.getID() != second.getID() || first.getFirstName() != second.getFirstName() || first.getLastName() != second.getLastName()
		|| first.getAddress() != second.getAddress() || first.getCity() != second.getCity() || first.getDepartment() != second.getDepartment()
		|| first.getState() != second.getState() || first.getZip() != second.getZip() 
		|| first.getNumber() != second.getNumber() || first.getEmail() != second.getEmail();
}

bool operator==(Faculty first, Faculty second){
	return first.getID() == second.getID() && first.getFirstName() == second.getFirstName() && first.getLastName() == second.getLastName()
		&& first.getAddress() == second.getAddress() && first.getCity() == second.getCity() && first.getDepartment() == second.getDepartment()
		&& first.getState() == second.getState() && first.getZip() == second.getZip() 
		&& first.getNumber() == second.getNumber() && first.getEmail() == second.getEmail();
}

bool operator<(Faculty first, Faculty second){
	if (first.getID() < second.getID()){
		return true;
	} else if (first.getID() == second.getID()){
		if (first.getLastName() < second.getLastName()){
			return true;
		} else if(first.getLastName() == second.getLastName()){
			if (first.getFirstName() < second.getFirstName()){
				return true;
			} else if (first.getFirstName() == second.getFirstName()){
				if (first.getDepartment() < second.getDepartment()){
					return true;
				} else if (first.getDepartment() == second.getDepartment()){
					if (first.getAddress() < second.getAddress()){
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool operator>(Faculty first, Faculty second){
	if (first.getID() > second.getID()){
		return true;
	} else if (first.getID() == second.getID()){
		if (first.getLastName() > second.getLastName()){
			return true;
		} else if(first.getLastName() == second.getLastName()){
			if (first.getFirstName() > second.getFirstName()){
				return true;
			} else if (first.getFirstName() == second.getFirstName()){
				if (first.getDepartment() > second.getDepartment()){
					return true;
				} else if (first.getDepartment() == second.getDepartment()){
					if (first.getAddress() > second.getAddress()){
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool operator<=(Faculty first, Faculty second){
	return (first < second) || (first == second);
};

bool operator>=(Faculty first, Faculty second){
	return (first > second) || (first == second);
};

//Student Operator Overloading
bool operator!=(Student first, Student second){
	return first.getID() != second.getID() || first.getFirstName() != second.getFirstName() || first.getLastName() != second.getLastName()
		|| first.getAddress() != second.getAddress() || first.getCity() != second.getCity() 
		|| first.getState() != second.getState() || first.getZip() != second.getZip() 
		|| first.getNumber() != second.getNumber() || first.getEmail() != second.getEmail();
}

bool operator==(Student first, Student second){
	return first.getID() == second.getID() && first.getFirstName() == second.getFirstName() && first.getLastName() == second.getLastName()
		&& first.getAddress() == second.getAddress() && first.getCity() == second.getCity() 
		&& first.getState() == second.getState() && first.getZip() == second.getZip() 
		&& first.getNumber() == second.getNumber() && first.getEmail() == second.getEmail();
}

bool operator<(Student first, Student second){
	if (first.getID() < second.getID()){
		return true;
	} else if (first.getID() == second.getID()){
		if (first.getLastName() < second.getLastName()){
			return true;
		} else if(first.getLastName() == second.getLastName()){
			if (first.getFirstName() < second.getFirstName()){
				return true;
			} else if (first.getFirstName() == second.getFirstName()){
				if (first.getAddress() < second.getAddress()){
					return true;
				} else if (first.getAddress() == second.getAddress()){
					if (first.getCity() < second.getCity()){
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool operator>(Student first, Student second){
	if (first.getID() > second.getID()){
		return true;
	} else if (first.getID() == second.getID()){
		if (first.getLastName() > second.getLastName()){
			return true;
		} else if(first.getLastName() == second.getLastName()){
			if (first.getFirstName() > second.getFirstName()){
				return true;
			} else if (first.getFirstName() == second.getFirstName()){
				if (first.getAddress() > second.getAddress()){
					return true;
				} else if (first.getAddress() == second.getAddress()){
					if (first.getCity() > second.getCity()){
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool operator<=(Student first, Student second){
	return (first < second) || (first == second);
};

bool operator>=(Student first, Student second){
	return (first > second) || (first == second);
};

//Course Operator Overloading
bool operator!=(Course first, Course second){
	return first.getTerm() != second.getTerm() || first.getYear() != second.getYear() || first.getName() != second.getName()
		|| first.getSectionName() != second.getSectionName() || first.getSectionNumber() != second.getSectionNumber()
		|| first.getLocation() != second.getLocation() || first.getCredit() != second.getCredit()
		|| first.getStartDate() != second.getStartDate() || first.getEndDate() != second.getEndDate() || first.getFaculty() != second.getFaculty()
		|| first.getOccurrence() != second.getOccurrence() || first.getPlatform() != second.getPlatform();
}

bool operator==(Course first, Course second){
		return first.getTerm() == second.getTerm() && first.getYear() == second.getYear() && first.getName() == second.getName()
		&& first.getSectionName() == second.getSectionName() && first.getSectionNumber() == second.getSectionNumber()
		&& first.getLocation() == second.getLocation() && first.getCredit() == second.getCredit() 
		&& first.getStartDate() == second.getStartDate() && first.getEndDate() == second.getEndDate() && first.getFaculty() == second.getFaculty()
		&& first.getOccurrence() == second.getOccurrence() && first.getPlatform() == second.getPlatform();
}


bool operator<(Course first, Course second){
	if (first.getName() < second.getName()){
		return true;
	} else if (first.getName() == second.getName()){
		if (first.getYear() < second.getYear()){
			return true;
		} else if(first.getYear() == second.getYear()){
			if (first.getTerm() < second.getTerm()){
				return true;
			} else if (first.getTerm() == second.getTerm()){
				if (first.getSectionName() < second.getSectionName()){
					return true;
				} else if (first.getSectionName() == second.getSectionName()){
					if (first.getSectionNumber() < second.getSectionNumber()){
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool operator>(Course first, Course second){
	if (first.getName() > second.getName()){
		return true;
	} else if (first.getName() == second.getName()){
		if (first.getYear() > second.getYear()){
			return true;
		} else if(first.getYear() == second.getYear()){
			if (first.getTerm() > second.getTerm()){
				return true;
			} else if (first.getTerm() == second.getTerm()){
				if (first.getSectionName() > second.getSectionName()){
					return true;
				} else if (first.getSectionName() == second.getSectionName()){
					if (first.getSectionNumber() > second.getSectionNumber()){
						return true;
					} else {
						return false;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return false;
		}
	} else {
		return false;
	}
}

bool operator<=(Course first, Course second){
	return (first < second) || (first == second);
};

bool operator>=(Course first, Course second){
	return (first > second) || (first == second);
};

bool MyCanvas::doLogin() const {
	LoginMenu login;
	bool success = false;
	char i;
	enum MENU_OPTION { LOGIN='1', CREATE='2', RESET='3', EXIT='x' };
	do {
		i = login.getInput();
		switch (i) {
			case LOGIN: // todo enum
				return login.doLogin();
				break;
			case CREATE:
				return login.createLogin();
				break;
			case RESET:
				return login.resetPassword();
				break;
			case EXIT:
				cout << "Logged Out." << endl;
				break;
			default: {
			}
		} 
	} while (i < 4);

	return false;
}

void MyCanvas::doMenu() {
	MainMenu mainMenu;

	char j;
	initFacultyData();
	initCourseData();
	initStudentData();

	enum MENU_OPTION { HOME='1', ANNOUNCE='2', ASSIGN='3',  DISCUSS='4', GRADES='5', QUIZ='6', PEOPLE='7', EXIT='x' };
	int i = 0;
	do {
		cout << "Course List (first greater than or equal to second): " << (*(courseList->at(0)) <= *(courseList->at(1))) << endl;
		cout << "Faculty List (first less than or equal to second): " <<(*(faculty->at(0)) >= *(faculty->at(1))) << endl;
		cout << "Student List (first greater than or equal to second): " <<(*(studentList->at(0)) <= *(studentList->at(1))) << endl;
		j = mainMenu.getInput();
		switch (j) {
			case HOME: 
				cout << "Home " << endl;
				break;
			case ANNOUNCE:
				//mainMenu.doAnnounce();
				cout << "Announcements " << endl;
				break;
			case ASSIGN:
				//mainMenu.doAssign();
				cout << "Assignments " << endl;
				break;
			case DISCUSS:
				//mainMenu.doDiscuss();
				cout << "Discussions " << endl;
				break;
			case GRADES:
				//mainMenu.doGrades();
				cout << "Grades " << endl;
				break;
			case QUIZ:
				//mainMenu.doQuiz();
				cout << "Quizzes " << endl;
				break;
			case PEOPLE:
				//mainMenu.doPeople();
				cout << "People " << endl;
				break;
			case EXIT:
				cout << "Logged out." << endl;
				break;
			default: {
			}
		} 
	i++;
	} while (i < 1);
	return;
}

*/