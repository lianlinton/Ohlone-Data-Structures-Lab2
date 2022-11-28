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
