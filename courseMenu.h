#pragma once
#include <fstream>
#include <vector>
#include "course.h"
#include "courseListType.h"
#include "menu.h"
#include "facultyMenu.h"

using namespace std;

const string COURSE_DATA = "course_data.csv";

enum COURSE_MENU_OPTION {
	COURSE_LIST='1',
	COURSE_VIEW='2',
	COURSE_ADD='3',
	COURSE_EDIT='4',
	COURSE_DELETE='5',
	COURSE_EXIT='x' 
};

class CourseMenu : public Menu {
public:
	CourseMenu();
	~CourseMenu();

	void doList();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doSave();			// TODO
	void doFacultyMenu();	// Lab 5
	void doSortedList();	// Lab 5

	Course& getSelectedCourse() {
		return *pCourse;
	};

	bool isSelectedCourse() const {
		return pCourse != nullptr;
	};
	
private:
	void init();
	void selectedCourse(Course& c) {
		pCourse = &c;
	};

	fstream inFile;
	FacultyMenu facultyMenu;	// Lab 5
	Course* pCourse;	
	CourseListType *list;		// Lab 5
};