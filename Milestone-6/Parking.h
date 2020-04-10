/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.h
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

#ifndef MILESTONE_2_PARKING_H
#define MILESTONE_2_PARKING_H

#include <fstream>
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

namespace sdds {
#define PARKING_MENU_LENGTH 5
#define VEHICLE_SELECTION_LENGTH 3
#define MAXIMUM_PARKING_SPOT 100

    class Parking {
        char* fileName;
        int numberOfSpots;
        int parkedVehicleNumber;
        Vehicle* vehicles[MAXIMUM_PARKING_SPOT];
        Menu* parkingMenu;
        Menu* vehicleSelection;

        // Copy and assignment are denied in the parking class
        Parking&operator=(const Parking& otherParkingMenu) = delete;
        Parking(const Parking& otherParkingMenu) = delete;

        void createParkingMenu();
        void createVehicleSelectionSubMenu();
        friend std::ostream& display(std::ostream& cout, const Menu& menu);
        bool isEmpty() const;
        void parkingStatus();
        void parkVehicle();
        void returnVehicle();
        void listParkedVehicle();
        bool closeParking();
        bool exitParkingApp();
        bool loadFileData();
        void saveDataToFile();

        // Other member functions
        void shiftString(int unit, char * originalStr);
        bool isDuplicateLicensePlate(int);
        int searchLicensePlateNo(const char*);
        int getEmptyPosition();
        bool runParkingMenu();
        bool confirmAction();
        void setFileNameToNull();
        void setParkingMenuToNull();
        void setVehicleSelectionToNull();
        void setVehicleArrayToNull();
        void setToEmptyState();
        void setEmpty();

    public:
        Parking();
        Parking(const char* inputFileName);
        Parking(const char* dataFile, int numberOfSpots);
        ~Parking();
        int run();
    };
}


#endif //MILESTONE_2_PARKING_H
