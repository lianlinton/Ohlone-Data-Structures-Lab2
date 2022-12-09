#include "dateTime.h"
#include <string>
#include <iostream>
#pragma once
#include <iomanip>
#include <fstream>

using namespace std;

//Constructor
DateType::DateType(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

void DateType::copy(const DateType& otherObject) {	
	month = otherObject.month;
	day = otherObject.day;
	year = otherObject.year;
}

//Set the date by passing in a string in month_day_year, _ to represent any FORMAT_SEPARATOR
void DateType::setDate(string dateString) {

	int pos = dateString.length() > 10 ? dateString.find(" ") : 10;
	string sdate = dateString.substr(0, pos);
	pos = sdate.find(FORMAT_SEPARATOR);
	month = stoi(sdate.substr(0, pos));
	sdate = sdate.substr(pos + 1); //skip past the first delimiter

	pos = sdate.find(FORMAT_SEPARATOR);
	day = stoi(sdate.substr(0, pos));
	sdate = sdate.substr(pos + 1);

	year = stoi(sdate); //year is all remaining in the string

}

DateType& DateType::getDate() {
	return *this;
}

//Date format - mm/dd/yyyy
string DateType::toString() const {	
	string date;
	if (month < 10){
		if (day < 10){
			date = "0"+to_string(month)+"/0"+to_string(day)+"/"+to_string(year);
		} else {
			date = "0"+to_string(month)+"/"+to_string(day)+"/"+to_string(year);
		}
	} else {
		date = ""+to_string(month)+"/"+to_string(day)+"/"+to_string(year);
	}
	return date;
}

bool DateType::operator>(const DateType& otherD) const {
	return (year > otherD.year) || (year == otherD.year && month > otherD.month)
		|| (year == otherD.year && month == otherD.month && day > otherD.day);
}
bool DateType::operator<(const DateType& otherD) const {
	//if either this > other or this = other, then this can't be < other
	return !(*this > otherD || *this == otherD);
}
bool DateType::operator>=(const DateType& otherD) const {
	//if this !< than other, then this must be > or =
	return !(*this < otherD);
}
bool DateType::operator<=(const DateType& otherD) const {
	return !(*this > otherD);
}
bool DateType::operator==(const DateType& otherD) const {
	return (year == otherD.year && month == otherD.month && day == otherD.day);
}
bool DateType::operator!=(const DateType& otherD) const {
	return !(*this == otherD);
}

/*******************************************************************/
//Constructor - also calls DateType's parameterized constructor
DateTime::DateTime(int h, int mi, int s, int mo, int d, int y) :DateType(mo, d, y) {
	hr = h;
	min = mi;
	sec = s;
}

void DateTime::copy(const DateTime& otherObject) {
	hr = otherObject.hr;
	min = otherObject.min;
	sec = otherObject.sec;

	DateType::copy(otherObject);
}

//Sets the time by passing in a string in hr:min:sec format
void DateTime::setDateTime(string dateTime) {
	string sdate, stime;
	if (dateTime.length() > 10) {
		int pos = dateTime.find(" ");
		sdate = dateTime.substr(0, pos);
		stime = dateTime.substr(pos + 1);
		this->setDate(sdate);
	}
	else {
		stime = dateTime;
	}
;	hr = stoi(stime.substr(0, 2));
	min = stoi(stime.substr(3, 2));
	sec = stoi(stime.substr(6, 2));
}

// Return MM/DD/YYYY HH:MM:SS
string DateTime::toString() {
	string time;
	if (hr < 10){
		if (min < 10){
			if (sec < 10){
				time = "0"+to_string(hr)+":0"+to_string(min)+":0"+to_string(sec);
			} else {
				time = "0"+to_string(hr)+":0"+to_string(min)+":"+to_string(sec);
			}
		} else {
			time = "0"+to_string(hr)+":"+to_string(min)+":"+to_string(sec);
		}
	} else {
		time = ""+to_string(hr)+":"+to_string(min)+":"+to_string(sec);
	}

	return this->getDate().toString() +" "+ time;
}

bool DateTime::operator>(const DateTime& otherD) const {
	return (hr > otherD.hr && min > otherD.min && sec > otherD.sec)
		&& DateType::operator>(otherD);
}
bool DateTime::operator<(const DateTime& otherD) const {
	//if either this > other or this = other, then this can't be < other
	return !(*this > otherD || *this == otherD);
}
bool DateTime::operator>=(const DateTime& otherD) const {
	//if this !< than other, then this must be > or =
	return !(*this < otherD);
}
bool DateTime::operator<=(const DateTime& otherD) const {
	return !(*this > otherD);
}
bool DateTime::operator==(const DateTime& otherD) const {
	return (hr == otherD.hr && min == otherD.min && sec == otherD.sec)
		&& DateTime::operator==(otherD);
}
bool DateTime::operator!=(const DateTime& otherD) const {
	return !(*this == otherD);
}