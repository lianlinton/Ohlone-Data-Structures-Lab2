#pragma once
#include <string>
#include <exception>

using namespace std;

class stoiException: public exception{
    public:
        const char* what(){
            return "Invalid Datatype";
        };
};