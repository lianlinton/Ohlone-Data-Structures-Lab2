#pragma once
#include <iostream>
#include <list>
#include "announcement.cpp"

/*using namespace std;
const int T_S = 200;
class HashTableEntry {
   public:
      int k;
      Announcement v;
      HashTableEntry(int k, Announcement v) {
         this->k= k;
         this->v = v;
      }
};
class HashMapTable {
   private:
      HashTableEntry **t;
   public:
      HashMapTable() {
         t = new HashTableEntry * [T_S];
         for (int i = 0; i< T_S; i++) {
            t[i] = NULL;
         }
      }
      int HashFunc(int k) {
         return k % T_S;
      }
      void Insert(int k, Announcement v) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] != NULL)
            delete t[h];
         t[h] = new HashTableEntry(k, v);
      }
      string SearchKey(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL)
            return "Not in the list";
         else
            return t[h]->v.getTitle();
      }
      void Remove(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL) {
            if (t[h]->k == k)
               break;
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL) {
            cout<<"No Element found at key "<<k<<endl;
            return;
         } else {
            delete t[h];
         }
         cout<<"Element Deleted"<<endl;
      }
      ~HashMapTable() {
         for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
               delete t[i];
               delete[] t;
         }
      }
};*/

using namespace std;

class HashMapTable {
    // size of the hash table
    int table_size;

    // Pointer to an array containing the keys
    list < Announcement >* table;

public:
    // creating constructor of the above class containing all the methods
    HashMapTable();

    // hash function to compute the index using table_size and key
    int hashFunction(const string& str) {
        int h = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (i%5==0){
                h = 2 * h + str[i];
            }
        }
        return h;
    }

    // inserting the key in the hash table
    void insertElement(Announcement key);

    // deleting the key in the hash table
    void deleteElement(string title);

    // displaying the full hash table
    void displayHashTable();

    void setTableSize(int size);

    void viewElement(string title);

    void editElement(string title, string message);

};

//creating the hash table with the given table size
HashMapTable::HashMapTable() {

    table = new list <Announcement>[2000000];
    table_size = 2000000;
}

// insert function to push the keys in hash table
void HashMapTable::insertElement(Announcement key) {
    int index = hashFunction(key.getTitle());
    table[index].push_back(key);
}

void HashMapTable::viewElement(string title){
    int index = hashFunction(title);
    Announcement* p;
    list < Announcement > ::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if ((*i).getTitle() == title+"\r") {
            (*i).print();
            break;
        }
    }
}

void HashMapTable::editElement(string title, string message){
    int index = hashFunction(title);
    Announcement* p;
    list < Announcement > ::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if ((*i).getTitle() == title+"\r") {
            (*i).setText(message);
            break;
        }
    }
}

// delete function to delete the element from the hash table
void HashMapTable::deleteElement(string title) {
    int index = hashFunction(title);

    // finding the key at the computed index
    list < Announcement > ::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if ((*i).getTitle() == title+"\r") {
            break;
        }
    }

    // removing the key from hash table if found
    if (i != table[index].end()) {
        table[index].erase(i);
    }
}

// display function to showcase the whole hash table
void HashMapTable::displayHashTable() {
    for (int i = 0; i < table_size; i++) {
        cout << i;
        // traversing at the recent/ current index
        for (auto j : table[i]) {
            cout << " ==> ";
            j.print();
        }
        cout << endl;
    }
}

void HashMapTable::setTableSize(int size){
    table_size = size;
}

/*Main function
int main() {
    // array of all the keys to be inserted in hash table
    nt arr[] = {
      20,
      34,
      56,
      54,
      76,
      87
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    // table_size of hash table as 6
    HashMapTable ht(6);

    for (int i = 0; i < n; i++) {
        ht.insertElement(arr[i]);
    }

    // deleting element 34 from the hash table
    ht.deleteElement(34);

    // displaying the final data of hash table
    ht.displayHashTable();

    return 0;
}*/