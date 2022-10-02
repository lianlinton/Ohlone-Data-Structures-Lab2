/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Template file
 *******************************************************/
#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
   A menu that is displayed on a console.
*/
class Menu
{
public:
    /**
       Constructs a menu with no options.
    */
    Menu(string name);

    /**
       Adds an option to the end of this menu.
       @param option the option to add
    */
    void addOption(string option);

    /**
       Displays the menu, with options numbered starting with 1,
       and prompts the user for input. Repeats until a valid input
       is supplied.
       @return the number that the user supplied
    */
    int getInput() const;
    /**
     * Prints out the menu
     * 
     */
    void display() const;

private:
    string name;
    vector<string> options;
};