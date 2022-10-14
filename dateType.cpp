//Implementation file for DateType and DateTime
#include "dateType.h"
#include "dateTime.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Constructor
DateType::DateType(int m, int d, int y){
	month = m;
	day = d;
	year = y;
}
//Set the date by passing in a string in month_day_year, _ to represent any delimiter
void DateType::setDate(string date, char delim){

	int pos = date.find(delim);

	month = stoi(date.substr(0,pos));
	date = date.substr(pos+1); //skip past the first delimiter

	pos = date.find(delim);
	day = stoi(date.substr(0,pos));
	date = date.substr(pos+1);

	year = stoi(date); //year is all remaining in the string
}

//Return the date as month/day/year
string DateType::getDate() const{
	return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}



/*******************************************************************/
//Constructor - also calls DateType's parameterized constructor
DateTime::DateTime(int h, int mi, int s, int mo, int d, int y)
	: DateType(mo,d,y){
	hr = h;
	min = mi;
	sec = s;
}

//Sets the time by passing in a string in hr:min:sec format
void DateTime::setTime(string time){
	hr = stoi(time.substr(0,2));

	min = stoi(time.substr(3,2));

	sec = stoi(time.substr(6,2));
}

