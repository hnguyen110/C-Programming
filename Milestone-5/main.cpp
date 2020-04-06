/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 3
Module: Menu
Filename: ms5_CarMotorcycleTester.cpp
Version 1.0
Author	Hien Dao The Nguyen
Revision History
-----------------------------------------------------------
Date      Reason
2020/03/23  Preliminary release
2020/03/23  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
using namespace std;
using namespace sdds;
void  MotorcycleTest(Vehicle*);
void  CarTest(Vehicle*);
int main() {
    cout << "Milestone 5, Car and Motorcycle: " << endl;
    CarTest(new Car);
    MotorcycleTest(new Motorcycle);
    return 0;
}
void  MotorcycleTest(Vehicle* V) {
    cout << "Motorcycle Test:" << endl << endl << "Invalid object printout: " <<endl;
    cout << *V << endl;
    cout << "Testing Console Entry, Enter the following: " << endl
         << "ab12<ENTER>" << endl
         << "Harley Davidson<ENTER>" << endl
         << "yes<ENTER>" << endl
         << "y<ENTER>" << endl;
    cin >> *V;
    V->setCsv(true);
    cout << endl << "Comma Separated Values: " << endl << *V << endl;
    V->setCsv(false);
    cout << "Console Printout: " << endl << *V << endl;
    cout << "Testing CSV Entry, Enter the following: " << endl
         << "12,AA22,Honda CD80,0<ENTER>" << endl;
    V->setCsv(true);
    cin >> *V;
    cout << endl << "Comma Separated Values: " << endl << *V << endl;
    V->setCsv(false);
    cout << endl << "Console Printout: " << endl << *V << endl;
    delete V;
}
void  CarTest(Vehicle* V) {
    cout << "Car Test:" << endl << endl << "Invalid object printout: " << endl;
    cout << *V << endl;
    cout << "Testing Console Entry, Enter the following: " << endl
         << "abc123<ENTER>" << endl
         << "Chevy Volt<ENTER>" << endl
         << "yes<ENTER>" << endl
         << "y<ENTER>" << endl;
    cin >> *V;
    V->setCsv(true);
    cout << endl << "Comma Separated Values: " << endl << *V << endl;
    V->setCsv(false);
    cout << "Console Printout: " << endl << *V << endl;
    cout << "Testing CSV Entry, Enter the following: " << endl
         << "12,GVAA123,Nissan Leaf,0<ENTER>" << endl;
    V->setCsv(true);
    cin >> *V;
    cout << endl << "Comma Separated Values: " << endl << *V << endl;
    V->setCsv(false);
    cout << endl << "Console Printout: " << endl << *V << endl;
    delete V;
}