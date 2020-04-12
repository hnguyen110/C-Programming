/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: ParkingAppTester.cpp
Version 1.0
Author	Hien Dao The Nguyen
Revision History
-----------------------------------------------------------
Date      Reason
2020/04/12  Preliminary release
2020/04/12  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Parking.h"
using namespace std;
using namespace sdds;
void runParking() {
    Parking P("ParkingData.csv", 11);
    P.run();
}
void pause() {
    cout << "<------------------------" << endl << "Press Enter to continue...";
    cin.ignore(1000, '\n');
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
}
int main() {
    cout << "Pass 1: ------->" << endl;
    runParking();
    ShowDatafile();
    pause();
    cout << "Pass 2: ------->" << endl;
    runParking();
    ShowDatafile();
    pause();
    cout << "Pass 3: ------->" << endl;
    runParking();
    ShowDatafile();
    return 0;
}