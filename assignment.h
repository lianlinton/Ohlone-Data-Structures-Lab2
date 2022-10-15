/*******************************************************

 * Program Name: Lab 4 Project

 * Author: Lian Elsa Linton

 * Date: October 14, 2022

 * Description: Assignment class represents the Assignments section on Canvas. 

 *******************************************************/
#pragma once 
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

//Modified from Lab 1

class Assignment {
    public:
        /**
         * Construct a new Assignment object
         * 
         */
        Assignment();
        /**
         * Access name of assignment
         * 
         * @return name
         */
        string getUserName(){
            return name;
        };
        /**
         * Access due date of assignment
         * 
         * @return due date
         */
        string getUserDueDate(){
            return dueDate;
        };
        /**
         * Access points of assignment
         * 
         * @return points
         */
        int getUserPoints(){
            return points;
        };
        /**
         * Set the name of assignment
         * 
         * @param name 
         */
        void setUserName(string name){
            this->name = name;
        };
        /**
         * Set the due date of assignment
         * 
         * @param name 
         */
        void setUserDueDate(string dueDate){
            this->dueDate = dueDate;
        };
        /**
         * Set the points of assignment
         * 
         * @param name 
         */
        void setUserPoints(int points){
            this->points = points;
        };
        /**
         * Display assignment information
         * 
         */
        void showInfo(){
            cout << endl;
            cout << "Name: "+name << endl;
            cout << "Due Date: "+dueDate << endl;
            cout << "Points:" << points << endl;
            cout << endl;
        };
    private:
        string name;
        string dueDate;
        int points;
};