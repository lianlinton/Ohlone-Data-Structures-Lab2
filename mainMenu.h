/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Base class is the Menu Class and identifies the user's desired goal based on user input. 
 *******************************************************/
#pragma once
#include "menu.h"
#include "home.h"
#include "annoucement.h"
#include "discussion.h"
#include "assignment.h"
#include "quiz.h"
#include "grade.h"
#include "syllabus.h"
#include "student.h"
#include "person.h"
#include "loginMenu.h"
#include "course.h"
#include "faculty.h"

using namespace std;

enum MAIN_MENU_OPTION {
	MAIN_MENU_HOME='1', 
	MAIN_MENU_ANNOUNCEMENT='2',
	MAIN_MENU_DISCUSSION='3',
	MAIN_MENU_ASSIGNMENT = '4',
	MAIN_MENU_QUIZ = '5',
	MAIN_MENU_GRADE = '6',
	MAIN_MENU_SYLLABUS = '7',
	MAIN_MENU_STUDENT = '8',
	MAIN_MENU_EXIT='x' };

class MainMenu : public Menu {
public:
	MainMenu();
};
