/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 4
Module: Menu
Filename: main.cpp
Version 1.0
Author	Hien Dao The Nguyen
Revision History
-----------------------------------------------------------
Date      Reason
2020/03/26  Preliminary release
2020/03/26  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include "Vehicle.h"
using namespace std;
using namespace sdds;
void TestValidations();
void TestOperatorEqualEqual(const Vehicle& A, const Vehicle& B);
void TestIO(Vehicle& V);
int main() {
    Vehicle V;
    Vehicle C("abcd", "C car");
    // you can comment each test to develop your Vehicle step by step:
    TestIO(V);
    TestOperatorEqualEqual(C, V);
    TestValidations();
    return 0;
}
void TestIO(Vehicle& V) {
    cout << "Invalid Vehicle Printing:" << endl;
    cout << V << endl;
    cout << "Reading vehicle from console: " << endl;
    cout << "Enter:" << endl << "abc<ENTER>" << endl << "abc<ENTER>" << endl;
    V.setCsv(false);
    cin >> V;
    cout << "Printing a Vehicle that is not parked:" << endl;
    cout << V << endl;
    V.setParkingSpot(12);
    cout << "Printing a Vehicle that is parked in the spot number 12:" << endl;
    cout << V << endl;
    cout << "Reading and Writing Comma Separated values: " << endl;
    cout << "Enter: " << endl;
    cout << "123,abcd,abcd,<ENTER>" << endl;
    V.setCsv(true);
    cin >> V;
    cin.ignore(1000, '\n');
    cout << V << endl;
}

void TestValidations() {
    Vehicle* V;
    cout << "Construction validations:" << endl;
    V = new Vehicle(nullptr, "abc");
    cout << *V;
    delete V;
    V = new Vehicle("123456789", "abc");
    cout << *V;
    delete V;
    V = new Vehicle("", "abc");
    cout << *V;
    delete V;
    V = new Vehicle("ABC", nullptr);
    cout << *V;
    delete V;
    V = new Vehicle("ABC", "");
    cout << *V;
    delete V;
    V = new Vehicle("ABC", "A");
    cout << *V;
    cout << "Input validations: " << endl;
    cout << "Enter: " << endl << "123456789<ENTER>" << endl << "abc<ENTER>" << endl << "abc<ENTER>" << endl;
    cin >> *V;
    cout << *V << endl;
    cout << "Enter: " << endl << "abc<ENTER>" << endl << "a<ENTER>" << endl << "ab<ENTER>" << endl;
    cin >> *V;
    cout << *V << endl;
    cout << "Testing setParkingSpot validation: " << endl <<  "Valid setting: " <<endl;
    V->setParkingSpot(20);
    cout << *V << endl;
    cout << "invalid setting: " << endl;
    V->setParkingSpot(-1);
    cout << *V << endl;
    delete V;
}
void TestOperatorEqualEqual(const Vehicle& A, const Vehicle& B) {
    cout << "opeator== (cstring):" << endl;
    if (A == "Abcd") {
        cout << "operator== with cstring works" << endl;
    }
    else {
        cout << "Bad Opertor==, fix your code" << endl;
    }
    cout << "opeator== (Vehicle):" << endl;
    if (A == B) {
        cout << "operator== with Vehicle works" << endl;
    }
    else {
        cout << "Bad Opertor==, fix your code" << endl;
    }
}