/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Template File

 *******************************************************/
#pragma once
#include "dateType.h"
#include <iomanip>
#include <fstream>

using namespace std;

class DateTime: public DateType{
public:
	DateTime(int h=0, int mi=0, int s=0, int mo=0, int d=0, int y=0);
	~DateTime(){};

	//Mutator functions
	void setHr(int h) { hr = h; };
	void setMin(int m) { min = m ;};
	void setSec(int s) { sec = s; };

	//Sets the time by passing in a string in hr:min:sec
	void setTime(string);

	//Accessor functions
	int getHr() const { return hr; };
	int getMin() const { return min; };
	int getSec() const { return sec; };

private:
    int hr;  //variable to store the hours
    int min; //variable to store the minutes
    int sec; //variable to store the seconds
};



