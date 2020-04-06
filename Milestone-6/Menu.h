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

#ifndef MILESTONE_2_MENU_H
#define MILESTONE_2_MENU_H

#include <iostream>
#include <cstring>

namespace sdds
{
#define MAX_NO_OF_ITEMS 10

    class MenuItem
    {
        char* nameOfItem;
        friend class Menu;

        MenuItem();
        MenuItem(const char*);
        MenuItem& operator=(const char* newMenuName);
        // MenuItems can not be assigned or copied from other MenuItems
        MenuItem& operator=(const MenuItem& otherMenuItems) = delete;
        MenuItem(const MenuItem& otherMenuItems) = delete;
        ~MenuItem();
    };

    class Menu
    {
        char* title;
        int itemCounter;
        MenuItem* items[MAX_NO_OF_ITEMS];
        int indentationLevel;
        bool validationFlag;

    public:
        char* getTitle() const;
        int getItemCounter() const;
        int getIndentationLevel() const;

        Menu(const Menu& menu);
        Menu(const char* name, int customIndentationLevel = 0);
        operator bool() const;
        operator int() const;
        bool isEmpty() const;
        void setEmpty();
        void createIndentationLevel(int level) const;
        void display() const;
        int run() const;
        void add(const char*);
        bool operator!() const;
        Menu& operator=(const Menu&);
        Menu& operator=(const char*);
        Menu& operator<<(const char*);
        ~Menu();
    };
}


#endif //MILESTONE_2_MENU_H
