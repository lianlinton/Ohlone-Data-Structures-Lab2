#include <iostream>
#include <string>
#include "discussion.cpp"
#include "discussionListType.h"
#include "linkedListIterator.h"

using namespace std;

DiscussionListType::DiscussionListType() {
}

Discussion* DiscussionListType::search(string fullname) {	
	Student s(fullname);
	Discussion d;
	d.setStudent(s);
	LinkedListIterator<Discussion> it;
	for (it = begin(); it != end(); ++it) {
		if (d == *it) {
			break;
		}
	}
	return &(*it);
}