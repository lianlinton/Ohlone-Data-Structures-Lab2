#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void doSave() {
    cout << "Saving... sample.csv" << endl;
    fstream inFile;
    inFile.open("sample.csv");
    if (inFile.is_open()){
        //add to file
        inFile << "hello there BROSKIES" << endl;
    } else {
        cerr << "Failed to open sample.csv " << " (errno " << errno << ")" << endl;
    }
    inFile.close();
    cout << "Save!!!" << endl << endl;
    
    /*if (inFile.is_open()) {
            Assignment* p;
            for (int i = 1; i <= list->listSize(); i++) {
                list->retrieveAt(i - 1, p);
                inFile << p->toCSV() << endl;
            }
        }
        else {
            cerr << "Failed to open file : " << ASSIGNMENT_DATA
                << " (errno " << errno << ")" << endl;
        }
        cout << "Save!!!" << endl << endl;
    }*/

}

int main(){
    doSave();
    return 0;
}