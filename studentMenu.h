/*******************************************************

 * Program Name: Lab 4 Project

 * Author: Lian Elsa Linton

 * Date: October 14, 2022

 * Description: The Student Menu class header file.

 *******************************************************/
#pragma once
#include <vector>
#include "student.h"
#include "orderedArrayListType.h"
#include "menu.h"

using namespace std;

//Student Menu Options
enum STUDENT_MENU_OPTION { STUDENT_LIST = '1', STUDENT_VIEW = '2', STUDENT_ADD = '3', STUDENT_EDIT = '4', STUDENT_DELETE = '5', STUDENT_EXIT = 'x'};

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
    private:
        void init();
        OrderedArrayListType<Student*> *list; //studentList
        Student* pStudent;
};