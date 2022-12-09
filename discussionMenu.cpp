#include <iostream>
#include <iomanip>
#include "discussionMenu.h"
#include "discussion.cpp"
#include "unorderedLinkedList.h"
#include "discussionListType.cpp"
#include "linkedListIterator.h"
#include "utils.cpp"
#include "menu.cpp"

using namespace std;

DiscussionMenu::DiscussionMenu()
    : Menu("Discussions Menu") {
    addOption("1) List discussions");
    addOption("2) View");
    addOption("3) Add");
    addOption("4) Edit");
    addOption("5) Delete");
    addOption("x) Exit");

    pDiscussion = nullptr;
    list = new DiscussionListType();
    init();
};

DiscussionMenu::~DiscussionMenu() {
    delete list;
    inFile.close();
}

void DiscussionMenu::init() {
    //string filename = "WRONG FILE";
    string filename = DISCUSSION_DATA;
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
    string name;
    string postDate;
    string text;
    while (!inFile.eof()) {
        getline(inFile, name);
        getline(inFile, postDate);
        getline(inFile, text);

        // Add new discussion and update student info
        Discussion d;
        Student s(name);
        d.setStudent(s);
        d.setDateTime(postDate);
        d.setText(text);
        list->insertLast(d);
    }
    inFile.clear();
    inFile.close();
}
void DiscussionMenu::doList() {
    cout << "***** Discussions *****" << endl;
    LinkedListIterator<Discussion> it;
    for (it = list->begin(); it != list->end(); ++it) {        
        ((Discussion*) &(*it))->print();
    }
    cout << endl;
}

void DiscussionMenu::doView() {
    cout << "***** View Discussion *****" << endl;
    cout << "Enter (\"firstname middlename(optional) lastname\"): ";
    string fullname;
    cin.ignore();
    getline(cin, fullname);
    Discussion* p = list->search(fullname);
    
    if (p != nullptr) {
        p->print();
    }
    else {
        cout << "Not found: " << fullname << endl;
    }
}

void DiscussionMenu::doAdd() {
    cout << "***** Add New Discussion *****" << endl;
    string user;
    string date; // convert previous date string to class DateType
    string post;
    cout << "Enter student name: ";
    cin >> user;
    cout << "Enter date (MM/DD/YYYY): ";
    cin >> date;
    cout << "Enter message: ";
    cin >> post;
    Discussion d;
    Student s(user);
    d.setStudent(s);
    d.setDateTime(date);
    d.setText(post);
    list->insertLast(d);
}

void DiscussionMenu::doEdit() {
    cout << "***** Edit Discussion *****" << endl;
    cout << "Enter (\"firstname middlename(optional) lastname\"): ";
    string fullname;
    getline(cin, fullname);
    Discussion* p = list->search(fullname);

    if (p != nullptr) {
        cout << "Enter new title (" << p->getText() << "): ";
        string newText;
        getline(cin, newText);
        p->setText(newText);
    }
    else {
        cout << "Not found: " << fullname << endl;
    }
}

void DiscussionMenu::doDelete() {
    cout << "***** Delete Discussion *****" << endl;
    cout << "Which discussion do you want to delete? " << endl;
    doList();
    cout << "Enter (\"firstname middlename(optional) lastname\"): ";
    string fullname;
    getline(cin, fullname);
    Discussion* p = list->search(fullname);
    list->deleteNode(*p);
}

/**
* Save to file
*/
void DiscussionMenu::doSave() {
    cout << "Saving... " << DISCUSSION_DATA << endl;
    string filename = DISCUSSION_DATA;
    inFile.open(filename);
    inFile.clear();
    if (inFile.is_open()) {
        LinkedListIterator<Discussion> it;
        for (it = list->begin(); it != list->end(); ++it) {        
            ((Discussion*) &(*it))->toCSV();
        }
    }
    else {
        cerr << "Failed to open file : " << DISCUSSION_DATA
            << " (errno " << errno << ")" << endl;
    }
    inFile.close();
    cout << "Save!!!" << endl << endl;   
}