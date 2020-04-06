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

#include "Utils.h"

namespace sdds
{
	// Check to see if the menu is safe to be copied to another menu or not
	bool isSafeToBeCopied(const Menu& menu)
	{
		bool state = false;
		if (menu.getTitle() != nullptr)
		{
			if (menu.getItemCounter() >= 0)
			{
				if (menu.getIndentationLevel() >= 0)
				{
					state = true;
				}
			}
		}
		return state;
	}

	bool ValidateMenuData(const char* name)
	{
		bool state = false;
		if (name != nullptr && name[0] != '\0')
		{
			state = true;
		}
		return state;
	}

	bool ValidateMenuName(const char* name)
	{
		bool state = false;
		if (name != nullptr && name[0] != '\0')
		{
			state = true;
		}
		return state;
	}

	bool isInt(char* input)
	{
		char validChar[11] = "1234567890";
		bool state = false;
		int counter = 0;
		if (input != nullptr && input[0] != '\0')
		{
			int inputLength = strlen(input);
			for (int i = 0; i < inputLength; ++i)
			{
				for (int j = 0; j < 11; ++j)
				{
					if (input[i] == validChar[j])
					{
						++counter;
					}
				}
			}
			if (counter != 0)
			{
				state = true;
			}
		}

		return state;
	}
}