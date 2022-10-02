/*******************************************************

 * Program Name: Lab2 Project

 * Author: Lian Elsa Linton

 * Date: September 23, 2022

 * Description: Helps the user navigate through Main Canvas area (Work in progress.)
 *******************************************************/
#include "menu.h"
#include "mainMenu.h"

MainMenu::MainMenu()
    : Menu("My Canvas Menu") {
    addOption("1) Home");
    addOption("2) Announcements");
    addOption("3) Assignments");
    addOption("4) Discussions");
    addOption("5) Grades");
    addOption("6) Quizzes");
    addOption("7) People");
    addOption("x) Logout");
};

/*
To be determined...

void MainMenu::doHome(){
    Home home; 
    cout << home.getTitle() << endl;
}

void MainMenu::doAnnounce(){
    Announcement announce; 
    cout << announce.getTitle() << endl;
}

void MainMenu::doDiscuss(){
    Discussion discuss; 
    cout << discuss.getTitle() << endl;
}

void MainMenu::doAssign(){
    Assignment assign; 
    cout << assign.getUserName() << endl;
}

void MainMenu::doGrades(){
    Grade grade; 
    cout << grade.getName() << endl;
}

void MainMenu::doQuiz(){
    Quizzes quiz;
    quiz.assignmentQuizzes();
}

void MainMenu::doPeople(){
    Student student; 
    cout << student.getName() << endl;
}
*/

char MainMenu::getInput() const{
	/*char option = Menu::getInput();
	return option;*/

	char input;
    Menu::display();
    cin >> input;
    return input;
}