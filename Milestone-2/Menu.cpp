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

#include "Utils.h"
#include "Menu.h"

using namespace std;

namespace sdds
{
    char* Menu::getTitle() const
    {
        return title;
    }

    int Menu::getItemCounter() const
    {
        return itemCounter;
    }

    int Menu::getIndentationLevel() const
    {
        return indentationLevel;
    }

    MenuItem::MenuItem()
    {
        nameOfItem = nullptr;
    }

    MenuItem::MenuItem(const char* name)
    {
        if (ValidateMenuData(name))
        {
            int nameLength = strlen(name);
            nameOfItem = new char[nameLength + 1];
            strcpy(nameOfItem, name);
        }
        else
        {
            delete[] nameOfItem;
            nameOfItem = nullptr;
        }
    }

    Menu::Menu(const Menu& menu) {
        if (ValidateMenuName(menu.title)) {
            title = new char[strlen(menu.title) + 1];
            strcpy(title, menu.title);
        } else {
            title = nullptr;
        }
        for (int counter = 0; counter < menu.itemCounter; ++counter) {
            items[counter] = new MenuItem(menu.items[counter]->nameOfItem);
        }
        itemCounter = menu.itemCounter;
        indentationLevel = menu.indentationLevel;
        validationFlag = menu.validationFlag;
    }

    Menu::Menu(const char* name, int customIndentationLevel)
    {
        if (ValidateMenuName(name))
        {
            int menuTitleLength = strlen(name);
            title = new char[menuTitleLength + 1];
            strcpy(title, name);
        }
        else
        {
            delete[] title;
            title = nullptr;
        }
        for (int counter = 0; counter < MAX_NO_OF_ITEMS; ++counter)
        {
            items[counter] = nullptr;
        }
        indentationLevel = customIndentationLevel;
        itemCounter = 0;
        validationFlag = true;
    };

    Menu::operator bool() const
    {
        return !isEmpty();
    }

    Menu::operator int() const
    {
        return run();
    }

    bool Menu::isEmpty() const
    {
        bool state = false;
        if (title == nullptr)
        {
            if (itemCounter == 0)
            {
                if (indentationLevel == 0)
                {
                    for (int counter = 0; counter < 10; ++counter)
                    {
                        if (items[counter] == nullptr)
                        {
                            state = true;
                        }
                        else
                        {
                            return state;
                        }
                    }
                }
            }
        }
        return state;
    }

    void Menu::setEmpty()
    {
        delete[] title;
        title = nullptr;
        for (int counter = 0; counter < itemCounter; ++counter)
        {
            delete items[counter];
            items[counter] = nullptr;
        }
        itemCounter = 0;
        indentationLevel = 0;
        validationFlag = true;
    }

    void Menu::createIndentationLevel(int level) const
    {
        for (int counter = 0; counter < level; ++counter)
        {
            cout << "    ";
        }
    }

    void Menu::display() const
    {
        // Print out the menu
        if (isEmpty())
        {
            cout << "Invalid Menu!" << endl;
        }
        else
        {
            createIndentationLevel(indentationLevel);
            cout << title << endl;
            if (items == nullptr || itemCounter == 0)
            {
                cout << "No Items to display!" << endl;
            }
            else
            {
                int counter;
                for (counter = 0; counter < itemCounter; ++counter)
                {
                    createIndentationLevel(indentationLevel);
                    cout << counter + 1 << "- " << items[counter]->nameOfItem << endl;
                }
                createIndentationLevel(indentationLevel);
                cout << "> ";
            }
        }
    }

    int Menu::run() const
    {
        display();
        if (itemCounter != 0)
        {
            char userOption[255];
            int option;
            int state = 0;
            cin >> userOption;

            if (itemCounter == 0)
            {
                option = 0;
            }
            else
            {
                do
                {
                    if (!isInt(userOption))
                    {
                        cout << "Invalid Integer, try again: ";
                        cin >> userOption;
                    }
                    else
                    {
                        option = atoi(userOption);
                        if (option == itemCounter)
                        {
                            --option;
                            state = 1;
                        }
                        else
                        {
                            if (!(option >= 1 && option <= itemCounter))
                            {
                                cout << "Invalid selection, try again: ";
                                cin >> userOption;
                            }
                            else
                            {
                                --option;
                                state = 1;
                            }
                        }
                    }

                } while (state == 0);
            }
            cin.ignore(1000, '\n');
            return option + 1;
        }
        else
        {
            return 0;
        }
    }

    void Menu::add(const char* newItems)
    {
        if (ValidateMenuData(newItems))
        {
            if (validationFlag)
            {
                if (itemCounter < MAX_NO_OF_ITEMS)
                {
                    items[itemCounter++] = new MenuItem(newItems);
                }
            }
        }
        else
        {
            setEmpty();
            validationFlag = false;
        }
    }

    bool Menu::operator!() const
    {
        return isEmpty();
    }

    Menu& Menu::operator=(const Menu& menu)
    {

        if (isSafeToBeCopied(menu))
        {
            delete[] title;
            title = nullptr;
            for (int counter = 0; counter < itemCounter; ++counter)
            {
                delete items[counter];
                items[counter] = nullptr;
            }
            // Assign the new data to the current object
            int newTitleLength = strlen(menu.getTitle());
            title = new char[newTitleLength + 1];
            strcpy(title, menu.getTitle());

            itemCounter = menu.getItemCounter();

            if (itemCounter > 0)
            {
                for (int counter = 0; counter < itemCounter; ++counter)
                {
                    items[counter] = new MenuItem(menu.items[counter]->nameOfItem);
                }
            }
            indentationLevel = menu.getIndentationLevel();
        }
        else
        {
            setEmpty();
        }
        return *this;
    }

    Menu& Menu::operator=(const char* newMenuName)
    {
        // Delete the old menu title
        if (title != nullptr)
        {
            delete[] title;
            title = nullptr;
        }

        // Check if the new title is valid or not
        if (ValidateMenuName(newMenuName))
        {
            int newTitleLength = strlen(newMenuName);
            title = new char[newTitleLength + 1];
            strcpy(title, newMenuName);
        }
        return *this;
    }

    MenuItem& MenuItem::operator=(const char* itemName)
    {
        if (ValidateMenuName(itemName))
        {
            delete[] nameOfItem;
            nameOfItem = nullptr;
            int itemNameLength = strlen(itemName);
            nameOfItem = new char[itemNameLength + 1];
            strcpy(nameOfItem, itemName);
        }
        return *this;
    }

    Menu& Menu::operator<<(const char* newItems)
    {
        add(newItems);
        return *this;
    }

    Menu::~Menu()
    {
        delete[] title;
        title = nullptr;
        for (int counter = 0; counter < itemCounter; ++counter)
        {
            delete items[counter];
            items[counter] = nullptr;
        }
    }

    MenuItem::~MenuItem()
    {
        delete[] nameOfItem;
        nameOfItem = nullptr;
    }
}