#include <iostream>
#include <string>
#include <sstream>
#include "menu.cpp"
#include "announcement.cpp"
#include "announcementMenu.h"
#include "announcementListType.cpp"
#include "linkedStack.h"
#include "utils.cpp"

using namespace std;

AnnouncementMenu::AnnouncementMenu()
    : Menu("Announcements Menu") {
    addOption("1) List");
    addOption("2) View");
    addOption("3) Add");
    addOption("4) Edit");
    addOption("5) Delete");
    addOption("x) Exit");

    pSelected = nullptr;
    list = new AnnouncementListType();
    init();
};

AnnouncementMenu::~AnnouncementMenu() {    
    delete list;
    inFile.close();
}

void AnnouncementMenu::init() {
    //string filename = "WRONG FILE";
    string filename = ANNOUNCEMENT_DATA;
    int count = 0;
    FileException except;
    while (true){
        try{
            openFile(inFile, filename);
            if (inFile.fail()){
                throw except;
            }
            break;
        } catch (exception &e){
            count++;
            if (count > 3){
                break;
            }
            cout << except.what() << endl;
            cout << "Enter filename: " << endl;
            cin >> filename;
        }
    }
    string title;
    string postDate;
    string text;
    while (!inFile.eof()) {
        getline(inFile, title);
        getline(inFile, postDate);
        getline(inFile, text);
        Announcement a;
        a.setTitle(title);
        a.setDateType(postDate);
        a.setText(text);
        list->push(a);
    }
    inFile.clear();
}

void AnnouncementMenu::doList() {
    cout << "***** Announcement *****" << endl;    
    //Make a copy of the stack to go through each element
    LinkedStackType<Announcement> copy = *list;
    while (!copy.isEmptyStack()) {
        Announcement a = copy.top();
        a.print();
        copy.pop(); // advance to next
    }
}

void AnnouncementMenu::doView() {
    cout << "***** View Announcement *****" << endl;
    // TODO...
}

void AnnouncementMenu::doAdd() {
    cout << "***** Add Announcement *****" << endl;
    // TODO...
}

void AnnouncementMenu::doEdit() {
    cout << "***** Edit Announcement *****" << endl;
    // TODO...
}

void AnnouncementMenu::doDelete() {
    cout << "***** Delete Announcement *****" << endl;
    // TODO...
}

/**
* Save to file
*/
void AnnouncementMenu::doSave() {    
    cout << "Saving... " << ANNOUNCEMENT_DATA << endl;
    // TODO...
}