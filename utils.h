#pragma once
#include <fstream>
#include <string>

using namespace std;

void openFile(fstream& inFile, string fileName);

//Returns the system time
void getCurrentTime(int& mo, int& d, int& yr, int& hr, int& min, int& sec);