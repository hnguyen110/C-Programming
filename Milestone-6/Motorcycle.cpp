/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.cpp
Version 1.0
Author	Hien Dao The Nguyen
Revision History
-----------------------------------------------------------
Date      Reason
2020/04/01  Preliminary release
2020/04/01  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "Motorcycle.h"
namespace sdds {
    Motorcycle::Motorcycle() {
        setToEmptyState();
    };
    Motorcycle::Motorcycle(const char* licensePlate, const char* makeAndModel) : Vehicle(licensePlate, makeAndModel) {
        sideCarState = false;
    };
    Motorcycle::~Motorcycle() {

    };

    void Motorcycle::setSideCarState(bool state) {
        sideCarState = state;
    };
    bool Motorcycle::getSideCarState() const {
        return sideCarState;
    }

    std::istream & Motorcycle::read(std::istream &is) {
        if (isCsv()) {
            Vehicle::read(is);
            if (getVehicleInputData() != nullptr) {
                char* inputData = new char[strlen(getVehicleInputData()) + 1];
                strcpy(inputData, getVehicleInputData());
                char result[4][255];
                int counter = 0;
                int arrayIndex = 0;
                int sideCarResultLength = 0;
                int dataLen = strlen(inputData);
                for (int runner = 0; runner < dataLen; ++runner) {
                    if (inputData[runner] != ',') {
                        result[arrayIndex][counter] = inputData[runner];
                        ++counter;
                        if (arrayIndex == 3) {
                            ++sideCarResultLength;
                        }
                    } else {
                        result[arrayIndex][counter] = '\0';
                        ++arrayIndex;
                        counter = 0;
                        if (arrayIndex == 4) {
                            break;
                        }
                    }
                }

                if (sideCarResultLength == 1 && isDigit(result[3][0])) {
                    if (result[3][0] == '0') {
                        setSideCarState(false);
                    } else if (result[3][0] == '1') {
                        setSideCarState(true);
                    } else {
                        setEmpty();
                    }
                } else {
                    setEmpty();
                }

                delete[] inputData;
                inputData = nullptr;
            }
        } else {
            std::cout << "\nMotorcycle information entry" << std::endl;
            Vehicle::read(is);
            std::cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
            if (getUserDecision()) {
                setSideCarState(true);
            }
        }
        return is;
    };
    std::ostream & Motorcycle::write(std::ostream &os) const {
        if (isEmpty()) {
            os << "Invalid Motorcycle Object" << std::endl;
        } else {
            if (isCsv()) {
                os << "M,";
            } else {
                os << "Vehicle type: Motorcycle" << std::endl;
            }
            Vehicle::write(os);
            if (isCsv()) {
                os << sideCarState << std::endl;
            } else {
                if (sideCarState) {
                    os << "With Sidecar" << std::endl;
                }
            }
        }
        return os;
    };

    bool Motorcycle::isEmpty() const {
        bool state = false;
        if (Vehicle::isEmpty()) {
            if (!sideCarState) {
                state = true;
            }
        }
        return state;
    };
    void Motorcycle::setEmpty() {
        Vehicle::setEmpty();
        sideCarState = false;
    };
    void Motorcycle::setToEmptyState() {
        Vehicle::setToEmptyState();
        sideCarState = false;
    };
    bool Motorcycle::getUserDecision() {
        bool state = false;
        bool stop = false;
        char decision[255];
        while (!stop) {
            std::cin.getline(decision, sizeof(decision));
            if (strlen(decision) == 1) {
                if (decision[0] == 'Y' || decision[0] == 'y') {
                    state = true;
                    stop = true;
                } else if (decision[0] == 'N' || decision[0] == 'n') {
                    state = false;
                    stop = true;
                } else {
                    std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }
            } else {
                std::cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }
        return state;
    };
}