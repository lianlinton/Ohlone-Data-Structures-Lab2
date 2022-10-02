/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Template file
 *******************************************************/
#pragma once 
#include <vector>
#include <string>
#include "home.h"
#include "annoucement.h"
#include "discussion.h"
#include "assignment.h"
#include "grade.h"
#include "syllabus.h"
#include "student.h"
#include "person.h"
#include "loginMenu.h"
#include "course.h"
#include "faculty.h"
#include "myOhlone.h"

using namespace std;

class MyCanvas {
	public: 
		//Constructor
		MyCanvas();
		~MyCanvas(){
			courseList->clear();
			studentList->clear();
			faculty->clear();
			delete courseList;
			delete studentList;
			delete faculty;
		};
		//Handles Login Menu
		bool doLogin() const;
		//Handles Main Menu
		void doMenu();
		//Loads Course Data
		void initCourseData();
		void initFacultyData();
		void initStudentData();

	private:
		vector<Home> home;
		vector<Announcement> announcements;
		vector<Discussion> discussions;
		vector<Assignment> assignments;
		vector<Grade> grades;
		vector<Syllabus> syllabus;
		vector<Student> people;
		// additional methods, objects, and variables...
		vector<Course*> *courseList;
		vector<Student*> *studentList;
		vector<Faculty*> *faculty;
};