/*******************************************************

 * Program Name: Lab 4 Project

 * Author: Lian Elsa Linton

 * Date: October 14, 2022

 * Description: Template File

 *******************************************************/
#pragma once
#include <string>
using namespace std;

class DateType{
public:
	DateType(int m=0, int d=0, int y=0);
	~DateType(){};

	//Mutator functions
	void setMonth(int m) { month = m; };
	void setDay(int d) { day = d; };
	void setYear(int y) { year = y; };

	//Sets the date by passing in a string in month_day_year (any delimiter)
	void setDate(string, char = '/');

	//Accessor functions
	int getMonth() const { return month; };
	int getDay() const { return day; };
	int getYear() const { return year; };

	//Returns the date as month/day/year
	string getDate() const;

protected:
	int month;
	int day;
	int year;
};

