/*******************************************************

 * Program Name: Lab2 Project

 * Author: Lian Elsa Linton

 * Date: September 23, 2022

 * Description: Announcement class represents the Announcements section on Canvas. 

 *******************************************************/
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "dateType.h"
using namespace std;

class Announcement{
    public:
        //Accessor and Mutator Methods for the Announcement Class
        /**
         * Access the title of announcement
         * @return title 
         */
        string getTitle(){
            return title;
        };
        /**
         * Access the message of announcement
         * @return message 
         */
        string getMessage(){
            return message;
        };
        /**
         * Access the date of announcement
         * @return date 
         */
        DateType getDate(){
            return date;
        };
        /**
         * Set the title of Announcement 
         * 
         * @param title 
         */
        void setTitle(string title){
            this->title = title;
        }
        /**
         * Set the message of Announcement 
         * 
         * @param message 
         */
        void setMessage(string message){
            this->message = message;
        }
        /**
         * Set the date of Announcement 
         * 
         * @param setDate 
         */
        void setDate(DateType date){
            this->date = date;
        }

    private:
        string title;
        string message;
        DateType date;
        
};
