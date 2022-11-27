#pragma once
#include <string>
#include <exception>

using namespace std;

class LoginException: public exception{
    public:
        const char* what(){
            return "Invalid Username or Password";
        };
};