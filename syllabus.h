/*******************************************************

 * Program Name: Lab2 Project

 * Author: Lian Elsa Linton

 * Date: September 23, 2022

 * Description: Syllabus class represents the Syllabus section on Canvas. 

 *******************************************************/
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Modified Lab 1

class Syllabus {
    public:
        /**
         * Construct a new Syllabus object
         * 
         */
        Syllabus();
        /**
         * Access title variable
         * 
         * @return title 
         */
        string getUserTitle(){
            return title;
        };
        /**
         * Access section variable
         * 
         * @return section 
         */
        string getSection(){
            return sectionName;
        };
        /**
         * Access book variable
         * 
         * @return book 
         */
        string getBook(){
            return textBookInfo;
        };
        /**
         * Access ide variable
         * 
         * @return ide 
         */
        string getIDE(){
            return ideInfo;
        };
        /**
         * Access summary variable
         * 
         * @return summary 
         */
        string getSummary(){
            return courseSummary;
        };
        /**
         * Set the class title
         * 
         * @param class title 
         */
        void setUserTitle(string title){
            this->title = title;
        };
        /**
         * Set the section 
         * 
         * @param section  
         */
        void setSection(string section){
            this->sectionName = section;
        };
        /**
         * Set the book 
         * 
         * @param book  
         */
        void setBook(string book){
            this->textBookInfo = book;
        };
        /**
         * Set the IDE
         * 
         * @param IDE 
         */
        void setIDE(string ide){
            this->ideInfo = ide;
        };
        /**
         * Set the course summary
         * 
         * @param course summary
         */
        void setSummary(string summary){
            this->courseSummary = summary;
        };
        /**
         * Show summary of syllabus
         * 
         */
        void showInfo(){
            cout << endl;
            cout << title << endl;
            cout << "Section:" << sectionName << endl;
            cout << "Textbook:" << textBookInfo << endl;
            cout << "IDE:" << ideInfo << endl;
            cout << "Course Summary" << courseSummary << endl;
            cout << endl;
        };
    private:
       string title;
       string sectionName;
       string textBookInfo;
       string ideInfo;
       string courseSummary;
};