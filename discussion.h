/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Discussion class represents the Discussions section on Canvas. 

 *******************************************************/
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Discussion{
    public:

    //Accessor Functions
    string getTitle(){
        return title;
    }
    bool getPinned(){
        return isPinned;
    }
    int getResponses(){
        return numResponses;
    }
    //Mutator Functions
    void setTitle(string title){
        this->title = title;
    }
    void setPinned(bool pinned){
        this->isPinned = pinned;
    }
    void setResponses(int responses){
        this->numResponses = responses;
    }

    private:
        string title;
        bool isPinned;
        int numResponses;

};