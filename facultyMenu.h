/*******************************************************

 * Program Name: Lab 4 Project

 * Author: Lian Elsa Linton

 * Date: October 14, 2022

 * Description: The Faculty Menu class header file.

 *******************************************************/

#pragma once
#include <vector>
#include "faculty.h"
#include "orderedArrayListType.h"
#include "menu.h"

using namespace std;

enum FACULTY_MENU_OPTION { FACULTY_LIST = '1', FACULTY_VIEW = '2', FACULTY_ADD = '3', FACULTY_EDIT = '4', FACULTY_DELETE = '5', FACULTY_EXIT = 'x'};

const string FACULTY_DATA = "faculty_data.csv";

class FacultyMenu : public Menu {
    public:
        FacultyMenu();
       ~FacultyMenu();
        void doList();
        void doView();
        void doAdd();
        void doEdit();
        void doDelete();
    private:
        void init();
        OrderedArrayListType<Faculty*> *list; //facultyList
        Faculty* pFaculty;
};