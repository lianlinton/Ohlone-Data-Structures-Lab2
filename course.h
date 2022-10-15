/*******************************************************

 * Program Name: Lab 4 Project

 * Author: Lian Elsa Linton

 * Date: October 14, 2022

 * Description: The Course class represents a complete course in Canvas. 

 *******************************************************/
#pragma once
#include "faculty.h"
#include <iostream>
#include <iomanip>
//#include "dateImp.cpp"
using namespace std;
#include <typeinfo>

class Course {
	public: 
		//Constructor
		Course(){

		};
		//Destructor
		/*~Course(){
		};*/
		//Mutator Methods
		void setTerm(string term){
			this->term = term;
		};
		void setYear(int year){
			this->year=year;
		};
		void setStartDate(DateType startDate){
			this->startDate = startDate;
		};
		void setEndDate(DateType endDate){
			this->endDate = endDate;
		};
		void setName(string name){
			this->name = name;
		};
		void setSectionName(string sectionName){
			this->sectionName = sectionName;
		};
		void setSectionNumber(string sectionNumber){
			this->sectionNumber = sectionNumber;
		};
		void setLocation(string location){
			this->location = location;
		};
		void setFaculty(Faculty faculty){
			this->faculty = faculty;
		};
		void setCredit(int credit){
			this->credit = credit;
		};
		void setOccurrence(string occurrence){
			this->occurrence = occurrence;
		}
		void setPlatform(string platform){
			this->platform = platform;
		}
		//Accessor Methods
		string getTerm() const{
			return this->term;
		};
		int getYear() const{
			return this->year;
		};
		DateType getStartDate() const{
			return this->startDate;
		};
		DateType getEndDate() const{
			return this->endDate;
		};
		string getName() const{
			return this->name;
		};
		string getSectionName() const{
			return this->sectionName;
		};
		string getSectionNumber() const{
			return this->sectionNumber;
		};
		string getLocation() const{
			return this->location;
		};
		Faculty getFaculty() const{
			return this->faculty;
		};
		int getCredit() const{
			return this->credit;
		};
		string getPlatform() const{
			return this->platform;
		};
		string getOccurrence() const{
			return this->occurrence;
		};
		void printCourseInfo() const{
			cout << endl;
			//Spring,2022,12/24/2022,5/12/2023,Assembly Programming,CS-118-03,068589,M,On-Campus,Fremont,Sha,3
			cout << "Name: " << name << ", Faculty: " << faculty.getLastName() << endl;
			cout << "Section Name: " << sectionName << ", Section Number: " << sectionNumber << endl;
			cout << "Term: " << term << ", Year: " << year << endl;
			cout << "Start Date: " << startDate.getDate() << ", End Date: " << endDate.getDate() << endl;
			cout << endl;
		}


	private: 
		string term;        // Fall
		int year;            // 2022
		DateType startDate;    // 8/24/2022
		DateType endDate;        // 12/20/2022
		string name;        // Programming W/ Data Structures
		string sectionName;     // CS-124-03
		string sectionNumber;     // T TH
		string location;         // Online or On-Campus
		Faculty faculty;         // JPHAM
		int credit;         // 3
		string occurrence;
		string platform;
};