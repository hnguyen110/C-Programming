/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 6
Module: ParkingAppTester
Filename: ParkingAppTester.cpp
Version 1.0
Author	Hien Dao The Nguyen
Revision History
-----------------------------------------------------------
Date      Reason
2020/04/01  Preliminary release
2020/04/01  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <fstream>
#include <iostream>
#include <cctype>
#include "Parking.h"
using namespace std;
using namespace sdds;
void runParking() {
    Parking P("ParkingData.csv", 10);
    P.run();
}
void ShowDatafile() {
    char ch;
    ifstream file("ParkingData.csv");
    cout << endl << "Content of ParkingData.csv after the program exits" << endl;
    cout << "-----------------------------------------------------------" << endl;
    while (file.get(ch)) {
        cout <<char(tolower(ch));
    }
    cout <<  "-----------------------------------------------------------" << endl;
    cout << "To restore the data back to the original values " << endl;
    cout << "Copy \"ParkingData.csv.bak\" over \"ParkingData.csv\"" << endl;
}
int main() {
    runParking();
    ShowDatafile();
    return 0;
}