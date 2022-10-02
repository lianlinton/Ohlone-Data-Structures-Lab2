/*******************************************************

 * Program Name: Lab2 Project

 * Author: Lian Elsa Linton

 * Date: September 23, 2022

 * Description: Home class represents the Home section on Canvas. 

 *******************************************************/
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Home {
    public:
        //Accessor Funciton
        void setTitle(string title){
            this-> title = title;
        };
        //Mutator Functions
        string getTitle(){
            return title;
        };
    private:
        string title; 

};