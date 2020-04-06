/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
Version 1.0
Author	Hien Dao The Nguyen
Revision History
-----------------------------------------------------------
Date      Reason
2020/03/13  Preliminary release
2020/03/13  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include "Parking.h"
#include <iostream>
using namespace sdds;
int main() {
    Parking P("ParkingData.csv"), bad1(nullptr),bad2("");
    bad1.run();
    bad2.run();
    P.run();
    std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << std::endl;
    P.run();
    return 0;
}