#ifndef H_OrderedArrayListType
#define H_OrderedArrayListType

#include <iostream>
#include "arrayListType.h"

using namespace std;

template <class elemType>
class OrderedArrayListType: public ArrayListType<elemType>
{
public:
    virtual void insertAt(int location, const elemType& insertItem);
    virtual void insertEnd(const elemType& insertItem);
    virtual void replaceAt(int location, const elemType& repItem);
    virtual int seqSearch(const elemType& searchItem) const;
    virtual void insert(const elemType& insertItem);
    virtual void remove(const elemType& removeItem);

    //Constructor
    OrderedArrayListType(int size = 100);
       
};

template <class elemType>
void OrderedArrayListType<elemType>::insert(const elemType& insertItem)
{
    if (this->length == 0)          //list is empty
        this->list[this->length++] = insertItem;  //insert insertItem
                                      //and increment length
    else if (this->length == this->maxSize)
        cout << "Cannot insert in a full list." << endl;
    else
    {
          //Find the location in the list where to insert
          //insertItem.
        int loc;

        bool found = false;

        for (loc = 0; loc < this->length; loc++)
        {
            if (this->list[loc] >= insertItem)
            {
                found = true;
                break;
            }
        }

        for (int i = this->length; i > loc; i--)
             this->list[i] = this->list[i - 1];  //move the elements down

        this->list[loc] = insertItem;  //insert insertItem
        this->length++;   //increment the length
    }
} //end insert

template <class elemType>
int OrderedArrayListType<elemType>::seqSearch(const elemType& searchItem) const
{
    int loc;
    bool found = false;

    for (loc = 0; loc < this->length; loc++)
    {
        if (this->list[loc] >= searchItem)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        if (this->list[loc] == searchItem)
            return loc;
        else
            return -1;
    }
    else
        return -1;
} //end seqSearch

template <class elemType>
void OrderedArrayListType<elemType>::insertAt
                         (int location, const elemType& insertItem)
{
    if (location < 0 || location >= this->maxSize)
            cout << "The position of the item to be "
                 << "inserted is out of range." << endl ;
    else if (this->length == this->maxSize)  //list is full
            cout << "Cannot insert in a full list." << endl;
    else
    {
        cout << "This is a sorted list. Inserting at the proper place."
             << endl;
        insert(insertItem);
    }
} //end insertAt

template <class elemType>
void OrderedArrayListType<elemType>::insertEnd(const elemType& insertItem)
{
    if (this->length == this->maxSize)  //the list is full
        cout << "Cannot insert in a full list." << endl;
    else
    {
        cout << "This is a sorted list. Inserting at the proper "
             << "place." << endl;
        insert(insertItem);
    }
} //end insertEnd

template <class elemType>
void OrderedArrayListType<elemType>::replaceAt(int location, const elemType& repItem)
{
    if (location < 0 || location >= this->length)
        cout << "The location of the item to be replaced is out "
             << "of range." << endl;
    else
    {
        this->removeAt(location);
        insert(repItem);
    }
} //end replaceAt

template <class elemType>
void OrderedArrayListType<elemType>::remove(const elemType& removeItem)
{
    int loc;

    if (this->length == 0)
        cout << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            this->removeAt(loc);
        else
            cout << "The item to be deleted is not in the list." << endl;
    }
} //end remove

template <class elemType>
OrderedArrayListType<elemType>::OrderedArrayListType(int size): ArrayListType<elemType>(size)
{
}

#endif
