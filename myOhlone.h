/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Uses dynamic memory allocation with an array of Course pointer objects
 *******************************************************/
#pragma once 
#include <vector>
#include <string>
#include "student.h"
#include "login.h"
#include "course.h"

class MyOhlone{
    public: 
        //Constructor
        MyOhlone();
        //Dynamic memory allocation: adds Course object pointers
        MyOhlone(Course* elem){
            list.push_back(elem);
        }
        MyOhlone(Faculty* elem){
            list2.push_back(elem);
        }
        MyOhlone(Student* elem){
            list3.push_back(elem);
        }
    private:
        vector<Course*> list;
        vector<Faculty*> list2;
        vector<Student*> list3;
        Login login;
};