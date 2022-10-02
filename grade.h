/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Grade class represents the Grades section on Canvas. 

 *******************************************************/
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "dateType.h"
using namespace std;

class Grade{
    public:
        //Mutator Functions
        void setName(string name){
            this->name = name;
        };
        void setDate(DateType date){
            this->dueDate = date;
        };
        void setScore(int score){
            this->score = score;
        };
        //Accessor Functions
        string getName(){
            return name;
        };
        DateType getDate(){
            return dueDate;
        };
        int getScore(){
            return score;
        };

    private:
        string name;
        DateType dueDate;
        int score;
};