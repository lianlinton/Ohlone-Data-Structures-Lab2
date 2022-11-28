#include <iostream>
#include "studentMenu.cpp"

using namespace std;
int main() {
    StudentMenu men;
    men.doView();
    men.doEdit();
    men.doList();
    men.doDelete();
    men.doList();
    return 0;
}