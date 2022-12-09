#include <iostream>
#include <string>
#include <sstream>
#include "menu.cpp"
#include "announcement.cpp"
#include "announcementMenu.h"
#include "announcementListType.cpp"
#include "linkedStack.h"
#include "utils.cpp"
#include "hashMap.cpp"
#include "dateTime.h"

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
    int annCount = 0;
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
        table.insertElement(a);
        annCount++;
    }
    inFile.clear();
    inFile.close();
    //table.setTableSize(annCount);
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
    /*string title;
    cout << "Enter the title: " << endl;
    cin.ignore();
    stringstream ss(title);
    getline(ss, title, '\n');*/
    table.viewElement("Week 5 Announcement (9/26/2022)");
}

void AnnouncementMenu::doAdd() {
    cout << "***** Add Announcement *****" << endl;
    string title;
    string date;
    string text;
    Announcement announce;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter date (MM/DD/YYYY): ";
    cin >> date;
    cout << "Enter message: ";
    cin >> text;
    announce.setTitle(title);
    announce.setDateType(date);
    announce.setText(text);
    //Announcement *p = &announce;
    list->push(announce);
    table.insertElement(announce);
}

void AnnouncementMenu::doEdit() {
    cout << "***** Edit Announcement *****" << endl;
    string message;
    string title = "Week 5 Announcement (9/26/2022)";
    cout << "Enter new message for "<< title << ": ";
    //cin.ignore();
    cin >> message;
    cout << message << endl;
    table.editElement(title, message);
    LinkedStackType<Announcement> copy;
    while (!list->isEmptyStack()) {
        Announcement a = list->top();
        if(a.getTitle() == title+"\r"){
            a.setText(message);
        }
        //a.print();
        copy.push(a); // advance to next
        list->pop();
    }
    while (!copy.isEmptyStack()){
        Announcement a = copy.top();
        list->push(a);
        copy.pop();
    }
}

void AnnouncementMenu::doDelete() {
    cout << "***** Delete Announcement *****" << endl;
    cout << "Deleted for Week 2 Announcement (9/6/2022)" << endl;
    table.deleteElement("Week 2 Announcement (9/6/2022)");
    LinkedStackType<Announcement> copy;
    while (!list->isEmptyStack()) {
        Announcement a = list->top();
        if(a.getTitle() == "Week 2 Announcement (9/6/2022)\r"){
            list->pop();
            break;
        }
        //a.print();
        copy.push(a); // advance to next
        list->pop();
    }
    while (!copy.isEmptyStack()){
        Announcement a = copy.top();
        list->push(a);
        copy.pop();
    }
}

/**
* Save to file
*/
void AnnouncementMenu::doSave() {  
    cout << "Saving... " << ANNOUNCEMENT_DATA << endl;
    string filename = ANNOUNCEMENT_DATA;
    inFile.open(filename);
    inFile.clear();
    if (inFile.is_open()) {
        LinkedStackType<Announcement> copy = *list;
        while (!copy.isEmptyStack()) {
            Announcement a = copy.top();
            inFile << a.toCSV() << endl;
            copy.pop(); // advance to next
        }
    }
    else {
        cerr << "Failed to open file : " << ANNOUNCEMENT_DATA
            << " (errno " << errno << ")" << endl;
    }
    inFile.close();
    cout << "Save!!!" << endl << endl;   
}