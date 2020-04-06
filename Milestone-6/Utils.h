/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 2
Module: Utils
Filename: Utils.h
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

#ifndef MILESTONE_2_UTILS_H
#define MILESTONE_2_UTILS_H

#include "Menu.h"

namespace sdds
{
    bool ValidateMenuData(const char* name);
    bool ValidateMenuName(const char* name);
    bool isSafeToBeCopied(const Menu&);
    bool isInt(char* input);
}


#endif //MILESTONE_2_UTILS_H