
#pragma once
#include <string>
#include <exception>

using namespace std;

class FileException: public exception{
    public:
        const char* what(){
            return "Invalid File Name";
        };
};