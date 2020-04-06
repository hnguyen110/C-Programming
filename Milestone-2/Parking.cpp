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

using namespace std;

namespace sdds {
    Parking::Parking() {
        fileName = nullptr;
        parkingMenu = nullptr;
        vehicleSelection = nullptr;
    }

    Parking::Parking(const char *inputFileName) {
        if (inputFileName != nullptr && strlen(inputFileName) > 0) {
            fileName = new char[strlen(inputFileName) + 1];
            strcpy(fileName, inputFileName);
        }
        else {
            fileName = nullptr;
        }
        parkingMenu = nullptr;
        vehicleSelection = nullptr;

        // Loading the data file
        if (loadFileData()) {
            createParkingMenu();
            createVehicleSelectionSubMenu();
            // Later on this function need to load in the data from the file
        } else {
            cout << "Error in data file" << endl;
        }
    }

    Parking::~Parking() {
        saveDataToFile();
        setEmpty();
    }

    void Parking::createParkingMenu() {
        if (parkingMenu != nullptr) {
            setParkingMenuToNull();
        }
        parkingMenu = new Menu("Parking Menu, select an action:");
        parkingMenu->add("Park Vehicle");
        parkingMenu->add("Return Vehicle");
        parkingMenu->add("List Parked Vehicles");
        parkingMenu->add("Close Parking (End of day)");
        parkingMenu->add("Exit Program");
    }

    void Parking::createVehicleSelectionSubMenu() {
        if (vehicleSelection != nullptr) {
            setVehicleSelectionToNull();
        }
        vehicleSelection = new Menu("Select type of the vehicle:", 1);
        vehicleSelection->add("Car");
        vehicleSelection->add("Motorcycle");
        vehicleSelection->add("Cancel");
    }

    bool Parking::isEmpty() const{
        bool state = false;
        if (fileName == nullptr) {
            if (parkingMenu == nullptr) {
                if (vehicleSelection == nullptr) {
                    state = true;
                }
            }
        }
        return state;
    }

    void Parking::parkingStatus() {
        cout << "****** Seneca Valet Parking ******" << endl;
    }

    void Parking::parkVehicle() {
        int result = vehicleSelection->run();
        if (result == 1) {
            cout << "Parking Car" << endl;
        } else if (result == 2) {
            cout << "Parking Motorcycle" << endl;
        } else if (result == 3) {
            cout << "Cancelled parking" << endl;
        } else {
            // Do nothing
        }
    }

    void Parking::returnVehicle() {
        cout << "Returning Vehicle" << endl;
    }

    bool Parking::closeParking() {
        cout << "Closing Parking" << endl;
        return true;
    }


    bool Parking::exitParkingApp() {
        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        return confirmAction();
    }

    bool Parking::loadFileData() {
        bool state = false;
        if (!isEmpty()) {
            cout << "loading data from " << fileName << endl;
            state = true;
        }
        return state;
    }

    void Parking::saveDataToFile() {
        if (!isEmpty()) {
            cout << "Exiting program!" << endl;
            cout << "Saving data into " << fileName << endl;
        }
    }

    bool Parking::runParkingMenu() {
        int state = false;
        int result = parkingMenu->run();
        if (result == 1) {
            parkVehicle();
        } else if (result == 2) {
            returnVehicle();
        } else if (result == 3) {
            cout << "Listing Parked Vehicles" << endl;
        } else if (result == 4) {
            closeParking();
            state = true;
        } else if (result == 5) {
            exitParkingApp();
            state = true;
        } else {
            // Do nothing because the input checking is done in run function already
        }
        return state;
    }

    bool Parking::confirmAction() {
        bool state = false;
        bool repeat = true;
        char action[255];

        do {
            cin >> action;
            if (strlen(action) == 1) {
                if (action[0] == 'Y' || action[0] == 'y') {
                    state = true;
                    repeat = false;
                } else if (action[0] == 'N' || action[0] == 'n') {
                    state = false;
                    repeat = false;
                } else {
                    cout << "Invalid response, Only (Y)es or (N)o are acceptable, retry: ";
                }
            } else {
                cout << "Invalid response, Only (Y)es or (N)o are acceptable, retry: ";
            }
//            cin.ignore(1000, '\n');
        } while(repeat);

        return state;
    }

    void Parking::setFileNameToNull() {
        delete[] fileName;
        fileName = nullptr;
    }

    void Parking::setParkingMenuToNull() {
//        parkingMenu->setEmpty();
        delete parkingMenu;
        parkingMenu = nullptr;
    }

    void Parking::setVehicleSelectionToNull() {
//        vehicleSelection->setEmpty();
        delete vehicleSelection;
        vehicleSelection = nullptr;
    }

    void Parking::setEmpty() {
        setFileNameToNull();
        setParkingMenuToNull();
        setVehicleSelectionToNull();
    }

    int Parking::run() {
        int state = 0;
        if (!isEmpty()) {
            bool exitAppState;
            do {
                parkingStatus();
                exitAppState = runParkingMenu();
            } while (!exitAppState);
        } else {
            state = 1;
        }
        return state;
    }
}