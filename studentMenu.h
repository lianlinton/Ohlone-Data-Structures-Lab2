#pragma once
#include <fstream>
#include <map>
#include "menu.h"
#include "student.h"
#include "linkedQueue.h"

using namespace std;

enum STUDENT_MENU_OPTION { STUDENT_LIST = '1', STUDENT_VIEW = '2', STUDENT_ADD = '3', STUDENT_EDIT = '4', STUDENT_DELETE = '5', STUDENT_EXIT = 'x' };

const string STUDENT_DATA = "student_data.csv";

class StudentMenu : public Menu {
public:
	StudentMenu();
	~StudentMenu();
	void doList();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doSave();			// TODO
private:
	fstream inFile;
	void init();
	LinkedQueueType<Student>* list;
	map<string /**key*/, Student* /**data*/> mapStudent;
};