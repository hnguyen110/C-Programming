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


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Utils.h"
#include "Menu.h"
using namespace std;
using namespace sdds;
int showSelection(int n);
void prompt(const char* message);
void pause();
void testMenus(Menu m, Menu sub1, const Menu& sub2);
void TT(const char* title);
int main() {
   TT("M1T1: constructors");
   Menu mainMenu("** Main Menu **");
   Menu subMenu1("** Sub Menu One **", 1);
   Menu subMenu2("** Sub Menu **", 2);
   Menu tempMenu("** Temp **");
   Menu invMenu("** To test Invalid Menu **");

   TT("M1T2: operator<< adding MenuItems");
   tempMenu << "One" << "Two" << "three";


   TT("M1T3: Menu::run()");
   prompt("Do the following: \nabc <ENTER>\n0 <ENTER>\n4 <ENTER>\n3 <ENTER>");
   cout << tempMenu.run() << " selected!" << endl;
   pause();

   TT("M1T4: Menu deep assignment with no items");
   tempMenu = subMenu2;

   TT("M1T5: Reseting Menu title and running an empty menu with no Items");
   tempMenu = "** New Title **"; //<<---- Assignment
   cout << tempMenu.run() << " returned by the Menu with no Items." << endl;
   pause();

   TT("M1T6: Menu::add() and operator<<");
   mainMenu.add("Option one");
   mainMenu.add("Option Two");
   mainMenu.add("Sub Options");
   mainMenu.add("Option four");
   mainMenu.add("Exit");
   subMenu1 << "Selection one" << "Sub Selections two" << "Selection three" << "Selection four";
   subMenu2 << "The first" << "The second" << "The third";

   TT("M1T7: Deep assignment");
   prompt("Do the following: \n1 <ENTER>");
   tempMenu = subMenu2;
   cout << tempMenu.run() << " selected!" << endl;
   pause();


   TT("M1T7: Deep copying, passing const refrence and indentation display");
   testMenus(mainMenu, subMenu1, subMenu2);

   TT("M1T8: operator bool()");
   if (mainMenu) {
      cout << "The mainMenu is valid and usable." << endl;
   }

   TT("M1T9: Invalid Menu and its usage");
   mainMenu.add(nullptr);
   if (!mainMenu) {
      cout << "The mainMenu is invalid(empty) and not usable." << endl;
   }
   mainMenu.run();
   mainMenu.display();
   TT("M1T10: Assigning Menu to an empty Menu");
   subMenu1 = mainMenu;
   subMenu1.run();
   subMenu1.display();
   TT("M1T11: Adding invalid string to render Menu invalid");
   invMenu << nullptr << "This should not be added" << "This shouldn't be added either";
   invMenu.run();
   invMenu.display();
   return 0;
}
int showSelection(int n) {
   cout << "You selected " << n << "." << endl;
   return n;
}

void prompt(const char* message) {
   cout << message << endl;
}
void pause() {
   cout << "Press enter to continue..." << endl;
   cin.ignore(1000, '\n');
}
void testMenus(Menu m, Menu sub1, const Menu& sub2) {
   int selection;
   prompt("Do the following:\n2 <ENTER>\n3 <ENTER>");
   while ((selection = m.run()) != 5) {
      showSelection(selection);
      if (selection == 3) {
         prompt("Do the following:\n2 <ENTER>");
         if (showSelection(sub1) == 2) {
            prompt("Do the following:\n3 <ENTER>\n5 <ENTER>");
            showSelection(sub2);
         }
      }
   }
}
void TT(const char* title) {
   cout << "******************************************************************" << endl;
   cout << title << endl;
   cout << "==================>" << endl;
}