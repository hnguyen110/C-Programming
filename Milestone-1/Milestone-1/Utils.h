/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author	Hien Dao The Nguyen
Revision History
-----------------------------------------------------------
Date      Reason
2020/03/11  Preliminary release
2020/03/11  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Menu.h"

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
	bool ValidateMenuData(const char* name);
	bool ValidateMenuName(const char* name);
	bool isSafeToBeCopied(const Menu& menu);
	bool isInt(char* input);
}

#endif // !SDDS_UTILS_H
