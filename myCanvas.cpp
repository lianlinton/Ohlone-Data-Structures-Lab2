/*******************************************************

 * Program Name: Lab 4 Project

 * Author: Lian Elsa Linton

 * Date: October 14, 2022

 * Description: Handles managing the menu functions that are executed based on the user's choice. 
 *******************************************************/
#include "myCanvas.h"
#include "loginMenu.cpp"
#include "mainMenu.cpp"
#include "courseMenu.cpp"
#include "studentMenu.cpp"
#include "facultyMenu.cpp"
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

//Login Menu Option: Calls the required functions of Login Menu based on user's choice
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

//Course Menu Option: Calls the required functions of Course Menu based on user's choice
void MyCanvas::doCourseMenu() const {
	CourseMenu courseMenu;
	char option = EXIT;
	//cout << "We've reached here!" << endl;
	do {
		option = courseMenu.getOption();

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
			option = EXIT;
		}
	} while (option != EXIT);

}

//Student Menu Option: Calls the required functions of Student Menu based on user's choice
void MyCanvas::doStudentMenu() const {
	StudentMenu student;
	char option = EXIT;
	do {
		option = student.getOption();
		//STUDENT_MENU_OPTION { STUDENT_LIST = '1', STUDENT_VIEW = '2', STUDENT_ADD = '3', STUDENT_EDIT = '4', STUDENT_DELETE = '5', STUDENT_EXIT = '6'};

		if (option == STUDENT_MENU_OPTION::STUDENT_LIST) {
			student.doList();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_VIEW) {
			student.doView();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_ADD) {
			student.doAdd();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_EDIT) {
			student.doEdit();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_DELETE) {
			student.doDelete();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_EXIT) {
			cout << "Exiting Student Menu" << endl;
			option = EXIT;
		}
	} while (option != EXIT);

}

//Faculty Menu Option: Calls the required function of Course Menu based on user's choice
void MyCanvas::doFacultyMenu() const {
	FacultyMenu faculty;
	char option = EXIT;
	do {
		option = faculty.getOption();

		if (option == FACULTY_MENU_OPTION::FACULTY_LIST) {
			faculty.doList();
		}
		else if (option == FACULTY_MENU_OPTION::FACULTY_VIEW) {
			faculty.doView();
		}
		else if (option == FACULTY_MENU_OPTION::FACULTY_ADD) {
			faculty.doAdd();
		}
		else if (option == FACULTY_MENU_OPTION::FACULTY_EDIT) {
			faculty.doEdit();
		}
		else if (option == FACULTY_MENU_OPTION::FACULTY_DELETE) {
			faculty.doDelete();
		}
		else if (option == FACULTY_MENU_OPTION::FACULTY_EXIT) {
			cout << "Exiting Student Menu" << endl;
			option = EXIT;
		}
	} while (option != EXIT);

}

//Faculty Menu Option: Calls the required function of Course Menu based on user's choice
void MyCanvas::doMenu() const {
	MainMenu mainMenu;
	MAIN_MENU_OPTION option = (MAIN_MENU_OPTION) mainMenu.getOption();

	if (option == MAIN_MENU_OPTION::MAIN_MENU_HOME){
		//mainMenu.doHome();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_ANNOUNCEMENT) {
		//mainMenu.doAnnounce();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_DISCUSSION) {
		//mainMenu.doDiscuss();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_ASSIGNMENT) {
		//mainMenu.doAssign();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_QUIZ) {
		//mainMenu.doQuiz();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_STUDENT) {
		//mainMenu.doPeople();
	}
	else if (option == MAIN_MENU_OPTION::MAIN_MENU_SYLLABUS) {
		//mainMenu.doSyllabus();
	} else {
		cout << "Exiting Student Menu" << endl;
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


