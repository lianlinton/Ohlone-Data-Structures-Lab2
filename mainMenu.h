/*******************************************************

 * Program Name: Lab2 Project

 * Author: Lian Elsa Linton

 * Date: September 23, 2022

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

// TODO: enum MENU_OPTION { LOGIN='1', CREATE='2', RESET='3', EXIT='x' };

class MainMenu : public Menu {
public:
	MainMenu();
	//returns user input in the form of a character
	char getInput() const;
	/*
	To be determined...
	void doHome();
	void doAnnounce();
	void doDiscuss();
	void doAssign();
	void doGrades();
	void doQuiz();
	void doPeople();*/
};

