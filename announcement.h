#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "dateTime.h"

using namespace std;

class Announcement{
    public:
        Announcement();

        void setTitle(string name) { title = name; };
        void setDateType(string dt) { postDate.setDate(dt); };
        void setText(string txt) { text = txt; };

        string getTitle() const { return title; }
        DateType getDateType() const {
            return postDate;
        };

        void print() const;

        //Overloaded operators
        bool operator>=(const Announcement&) const;
        bool operator<=(const Announcement&) const;
        bool operator<(const Announcement&) const;
        bool operator>(const Announcement&) const;
        bool operator==(const Announcement&) const;
        bool operator!=(const Announcement&) const;        

    private:
        string title;
        DateType postDate;
        string text;
};
