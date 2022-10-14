/*******************************************************

 * Program Name: Lab 3 Project

 * Author: Lian Elsa Linton

 * Date: October 1, 2022

 * Description: Template file
 *******************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "menu.h"

using namespace std;

Menu::Menu(string name) {
    this->name = name;
}

void Menu::addOption(string option) {
    options.push_back(option);
}

void Menu::display() const {
    // TODO: Use setfill and setw for menu-header
    // See example https://cplusplus.com/reference/iomanip/setfill/
    cout << "***** " << name << " *****" << endl;
    for (int i = 0; i < options.size(); i++) {
        cout << options[i] << endl;
    }
    cout << "\nEnter choice: ";
}

char Menu::getOption() const {
    char input;
    display();
    cin >> input;
    return input;
}

int Menu::getInput() const {
    int input;
    do {
        display();
        cin >> input;
    } while (input < 1 || input > options.size());
    return input;
}
