#pragma once
#include <vector>
#include "course.h"
#include "orderedArrayListType.h"
#include "menu.h"

using namespace std;

enum COURSE_MENU_OPTION { COURSE_LIST = '1', COURSE_VIEW = '2', COURSE_ADD = '3', COURSE_EDIT = '4', COURSE_DELETE = '5', COURSE_EXIT = '6'};

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
};