#pragma once
#include <iostream>
#include <iomanip>
#include "announcement.h"
#include "dateTime.cpp"
using namespace std;

Announcement::Announcement() {
}

void Announcement::print() const {
	cout << title << endl;
	cout << postDate.toString() << endl;
	cout << text << endl << endl;
	cout << "--------------------------------------------------" << endl;
	cout << endl;
}

bool Announcement::operator==(const Announcement& otherF) const {
	return getTitle() == otherF.getTitle();
}
bool Announcement::operator!=(const Announcement& otherF) const {
	return !(*this == otherF);
}

bool Announcement::operator>(const Announcement& otherF) const {
	return getTitle() > otherF.getTitle();
}
bool Announcement::operator<(const Announcement& otherF) const {
	return !(*this > otherF || *this == otherF);
}
bool Announcement::operator>=(const Announcement& otherF) const {
	return !(*this < otherF);
}
bool Announcement::operator<=(const Announcement& otherF) const {
	return !(*this > otherF);
}

/*void Announcement::operator=(Announcement& otherF) const{
	otherF.setTitle(this->title);
	otherF.setDateType(this->postDate);
	otherF.setText(this->text);
}*/

string Announcement::toCSV(){
	//Fall 2022 semester begins 08/29/2022
	//08/29/2022
	//Hello Students, The first-class meeting starts on Tuesday, 08/30/2022, at 6:30 PM, in room NC2308. Jim D. Pham
	return title+"\n"+postDate.toString()+"\n"+text;
}
