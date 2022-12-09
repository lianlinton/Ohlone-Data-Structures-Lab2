#pragma once

#include <fstream>
#include "announcement.h"
#include "menu.h"
#include "linkedStack.h"
#include "announcementListType.h"
#include "hashMap.cpp"
#include "dateTime.h"

using namespace std;

const string ANNOUNCEMENT_DATA = "announcements.dat";

enum ANNOUNCEMENT_MENU_OPTION {
	ANNOUNCEMENT_LIST = '1',
	ANNOUNCEMENT_VIEW = '2',
	ANNOUNCEMENT_ADD = '3',
	ANNOUNCEMENT_EDIT = '4',
	ANNOUNCEMENT_DELETE = '5',
	ANNOUNCEMENT_EXIT = 'x'
};

class AnnouncementMenu : public Menu {
	friend ostream& operator<<(ostream&, Announcement&);
	friend istream& operator>>(istream& in, Announcement& a);	

public:

	AnnouncementMenu();
	~AnnouncementMenu();

	void doList();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doSave();			

	Announcement& getSelected() {
		return *pSelected;
	};

private:
	void init();
	void setSelected(Announcement& a) {
		pSelected = &a;
	};

	fstream inFile;
	Announcement* pSelected;
	AnnouncementListType* list;
	HashMapTable table;
};