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
    Discussion d;
    cin >> d;
    list->insertLast(d);
}

void DiscussionMenu::doEdit() {
    cout << "***** Edit Discussion *****" << endl;
    cout << "Enter (\"firstname middlename(optional) lastname\"): ";
    string fullname;
    getline(cin, fullname);
    Discussion* p = list->search(fullname);

    if (p != nullptr) {
        // TODO...
    }
    else {
        cout << "Not found: " << fullname << endl;
    }
}

void DiscussionMenu::doDelete() {
    cout << "***** Delete Discussion *****" << endl;
    if (pDiscussion == nullptr) {
        cout << "Which discussion do you want to delete? " << endl;
        doList();
    }
    // TODO...
}

/**
* Save to file
*/
void DiscussionMenu::doSave() {
    cout << "Saving... " << DISCUSSION_DATA << endl;
    if (inFile.is_open()) {
        Discussion* p;
        // TODO...
    }
    else {
        cerr << "Failed to open file : " << DISCUSSION_DATA
            << " (errno " << errno << ")" << endl;
    }
    cout << "Save!!!" << endl << endl;
}