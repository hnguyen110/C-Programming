/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.cpp
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

//         Loading the data file
        if (loadFileData()) {
            createParkingMenu();
            createVehicleSelectionSubMenu();
            // Later on this function need to load in the data from the file
        } else {
            cout << "Error in data file" << endl;
        }
    }

    Parking::Parking(const char* inputDataFile, int inputNumberOfSpots) {
        setToEmptyState();
        if (inputDataFile != nullptr && strlen(inputDataFile) != 0) {
            if (inputNumberOfSpots >= 10 && inputNumberOfSpots <= MAXIMUM_PARKING_SPOT) {
                fileName = new char[strlen(inputDataFile) + 1];
                strcpy(fileName, inputDataFile);
                numberOfSpots = inputNumberOfSpots;
            }
        }

//         Loading the data file
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
        cout << "*****  Available spots: ";
        cout.width(4);
        cout.setf(ios::left);
        cout << numberOfSpots;
        cout.unsetf(ios::left);
        cout << " *****" << endl;
    }

    void Parking::parkVehicle() {
        int availablePosition = getEmptyPosition();
        if (availablePosition == -1) {
            cout << "Parking is full" << endl;
        } else {
            int result = vehicleSelection->run();
            if (result == 3) {
                cout << "Parking Cancelled" << endl;
            } else {
                if (result == 1) {
                    vehicles[availablePosition] = new Car();
                    vehicles[availablePosition]->setCsv(false);
                    cin >> *vehicles[availablePosition];
                    cout << "Parking Car" << endl;
                } else if (result == 2) {
                    vehicles[availablePosition] = new Motorcycle();
                    vehicles[availablePosition]->setCsv(false);
                    cin >> *vehicles[availablePosition];
                    cout << "Parking Motorcycle" << endl;
                }

                // Check if the vehicle has the same license plate or not
                if (isDuplicateLicensePlate(availablePosition)) {
                    cout << "Can not park; License plate already in the system!" << endl;
//                    vehicles[availablePosition]->setEmpty();
                    delete vehicles[availablePosition];
                    vehicles[availablePosition] = nullptr;
                } else {
                    cout << "Parking Ticket" << endl;
                    --numberOfSpots;
                    ++parkedVehicleNumber;
                    vehicles[availablePosition]->setParkingSpot(availablePosition + 1);
                    cout << *vehicles[availablePosition];
                }
            }
        }
    }

    void Parking::returnVehicle() {
        cout << "Returning Vehicle" << endl;
        cout << "Enter Licence Plate Number: ";
        char licensePlateNo[255];
        cin.getline(licensePlateNo, sizeof(licensePlateNo));
        int licensePlateLength = strlen(licensePlateNo);
        while (licensePlateLength < 1 || licensePlateLength > 8) {
            cout << "Invalid Licence Plate, try again: ";
            cin.getline(licensePlateNo, sizeof(licensePlateNo));
            licensePlateLength = strlen(licensePlateNo);
        }

        int postion = searchLicensePlateNo(licensePlateNo);
        if (postion == -1) {
            cout << "License plate " << licensePlateNo << " Not found" << endl;
        } else {
            cout << "Returning: " << endl;
            cout << *vehicles[postion];
            ++numberOfSpots;
            --parkedVehicleNumber;
//            vehicles[postion]->setEmpty();
            delete vehicles[postion];
            vehicles[postion] = nullptr;
        }
    }

    void Parking::listParkedVehicle() {
        for (int counter = 0; counter < MAXIMUM_PARKING_SPOT; ++counter) {
            if (vehicles[counter] != nullptr) {
                cout << *vehicles[counter];
                cout << "-------------------------------" << endl;
            }
        }
    }

    bool Parking::closeParking() {
        bool state = false;
        if (isEmpty()) {
            cout << "Closing Parking" << endl;
        } else {
            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: ";
            if (confirmAction()) {
                cout << "Closing Parking" << endl;
                for (int counter = 0; counter < MAXIMUM_PARKING_SPOT; ++counter) {
                    if (vehicles[counter] != nullptr) {
                        cout << "Towing request" << endl;
                        cout << "*********************" << endl;
                        cout << *vehicles[counter];
                        cout << endl;
//                        vehicles[counter]->setEmpty();
                        delete vehicles[counter];
                        vehicles[counter] = nullptr;
                    }
                }
                state = true;
            }
        }
        return state;
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
            int emptyPosition;
            int currentIndex = 0;
            char dataStream[100][255];
            ifstream parkingDataFile(fileName);
            if (parkingDataFile.is_open()) {
                while(parkingDataFile.good()) {
                    parkingDataFile.getline(dataStream[currentIndex], sizeof(dataStream[currentIndex]), '\n');
                    ++currentIndex;
                }
            }

            --currentIndex;

            if (currentIndex > MAXIMUM_PARKING_SPOT) {
                currentIndex = MAXIMUM_PARKING_SPOT;
            }

            for (int counter = 0; counter < currentIndex; ++counter) {
                emptyPosition = getEmptyPosition();
                if (tolower(dataStream[counter][0]) == 'c') {
                    vehicles[emptyPosition] = new Car();
                } else if (tolower(dataStream[counter][0]) == 'm') {
                    vehicles[emptyPosition] = new Motorcycle();
                }

                shiftString(2, dataStream[counter]);

                vehicles[emptyPosition]->setCsv(true);
                vehicles[emptyPosition]->setVehicleInputData(dataStream[counter]);
                vehicles[emptyPosition]->setVehicleData();
                vehicles[emptyPosition]->setCsv(false);
                --numberOfSpots;
                ++parkedVehicleNumber;
            }
            state = true;
        }
        return state;
    }

    void Parking::saveDataToFile() {
        if (!isEmpty()) {
            cout << "Exiting program!" << endl;
            cout << "Saving data into " << fileName << endl;
            ofstream parkingDataFile(fileName);
            if (parkingDataFile.is_open()) {
                for (int counter = 0; counter < MAXIMUM_PARKING_SPOT; ++counter) {
                    if (parkingDataFile.good()) {
                        if (vehicles[counter] != nullptr) {
                            vehicles[counter]->setCsv(true);
                            parkingDataFile << *vehicles[counter];
                        }
                    }
                }
            }
        }
    }

    void Parking::shiftString(int unit, char originalStr[]) {
        char tempString[255] = "";
        int originalStrLength = strlen(originalStr);
        for (int counter = unit; counter < originalStrLength; ++counter) {
            tempString[counter - unit] = originalStr[counter];
        }
        strcpy(originalStr, tempString);
    }

    bool Parking::isDuplicateLicensePlate(int parkingPosition) {
        bool state = false;
        for (int counter = 0; counter < MAXIMUM_PARKING_SPOT; ++counter) {
            if (parkingPosition != counter) {
                if (vehicles[parkingPosition] == vehicles[counter]) {
                    state = true;
                }
            }
        }
        return state;
    }

    int Parking::searchLicensePlateNo(const char* licensePlateNo) {
        for (int counter = 0; counter < MAXIMUM_PARKING_SPOT; ++counter) {
            if (vehicles[counter] != nullptr) {
                if (*vehicles[counter] == licensePlateNo) {
                    return counter;
                }
            }
        }
        return -1;
    }

    int Parking::getEmptyPosition() {
        for (int counter = 0; counter < MAXIMUM_PARKING_SPOT; ++counter) {
            if (numberOfSpots != 0) {
                if (vehicles[counter] == nullptr) {
                    return counter;
                }
            }
        }
        return -1;
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
            listParkedVehicle();
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

    void Parking::setVehicleArrayToNull() {
        for (int counter = 0; counter < MAXIMUM_PARKING_SPOT; ++counter) {
            if (vehicles[counter] != nullptr) {
//                vehicles[counter]->setEmpty();
                delete vehicles[counter];
                vehicles[counter] = nullptr;
            }
        }
    }

    void Parking::setToEmptyState() {
        fileName = nullptr;
        parkingMenu = nullptr;
        vehicleSelection = nullptr;
        for (int counter = 0; counter < MAXIMUM_PARKING_SPOT; ++counter) {
            vehicles[counter] = nullptr;
        }
        numberOfSpots = 0;
        parkedVehicleNumber = 0;
    }

    void Parking::setEmpty() {
        setFileNameToNull();
        setParkingMenuToNull();
        setVehicleSelectionToNull();
        setVehicleArrayToNull();
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