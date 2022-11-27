#pragma once
#define _CRT_SECURE_NO_WARNINGS // supress localtime warning

#include <fstream>
#include <ctime>
#include "utils.h"
#include "fileException.h"

using namespace std;
//Returns the system time
void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec) {
	time_t t = std::time(0);    // get time now
	tm* now = localtime(&t);

	mo = now->tm_mon + 1;
	d = now->tm_mday;
	yr = now->tm_year + 1900;

	hr = now->tm_hour;
	min = now->tm_min;
	sec = now->tm_sec;
}

void openFile(fstream &inFile, string fileName) {
	//inFile.open(fileName, ios::in | ios::out | ios::app);
	ifstream file(fileName);
	try {
		if (inFile.fail()){
            FileException except;
			throw except;
        }
		inFile.open(fileName);
	} catch (exception& e){
		FileException except;
		throw except;
	}
}