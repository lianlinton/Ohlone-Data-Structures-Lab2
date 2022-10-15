/*******************************************************

 * Program Name: Lab 4 Project

 * Author: Lian Elsa Linton

 * Date: October 14, 2022

 * Description: The Course Menu class header file.

 *******************************************************/
#pragma once
#include <vector>
#include "course.h"
#include "orderedArrayListType.h"
#include "menu.h"

using namespace std;

//Course Menu Options
enum COURSE_MENU_OPTION { COURSE_LIST = '1', COURSE_VIEW = '2', COURSE_ADD = '3', COURSE_EDIT = '4', COURSE_DELETE = '5', COURSE_EXIT = 'x'};

const string COURSE_DATA = "course_data.csv";

class CourseMenu : public Menu {
    public:
        CourseMenu();
      ~CourseMenu();
        void doList();
        void doView();
        void doAdd();
        void doEdit();
        void doDelete();
    private:
        void init();
        OrderedArrayListType<Course*> *list; //courseList
        Course* pCourse;
};
