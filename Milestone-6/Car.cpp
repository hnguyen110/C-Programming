/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 5
Module: Car
Filename: Car.cpp
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

#include "Car.h"

namespace sdds {
    Car::Car() {
        setToEmptyState();
    };
    Car::Car(const char* licensePlate, const char* makeAndModel) : Vehicle(licensePlate, makeAndModel) {
        carWashState = false;
    };
    Car::~Car() {
        setEmpty();
    };

    void Car::setCarWashState(bool state) {
        carWashState = state;
    };
    bool Car::getCarWashState() const {
        return carWashState;
    };
    void Car::setVehicleData() {
        // Set the fourth data with a function with set vehicle data
        // We need to add the validation of checking the vehicleInputData
        // If it is an empty string then set everything to nullptr
        Vehicle::setVehicleData();
        if (getVehicleInputData() != nullptr) {
            char* inputData = new char[strlen(getVehicleInputData()) + 1];
            strcpy(inputData, getVehicleInputData());
            char result[4][255];
            int counter = 0;
            int arrayIndex = 0;
            int carWashResultLength = 0;
            int dataLen = strlen(inputData);
            for (int runner = 0; runner < dataLen; ++runner) {
                if (inputData[runner] != ',') {
                    result[arrayIndex][counter] = inputData[runner];
                    ++counter;
                    if (arrayIndex == 3) {
                        ++carWashResultLength;
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

            if (result[3][0] == '0' && isDigit(result[3][0])) {
                setCarWashState(false);
//                    appendNewDataToVehicleData(",0");
            } else if (result[3][0] == '1') {
                setCarWashState(true);
//                    appendNewDataToVehicleData(",1");
            } else {
                setEmpty();
            }

            delete[] inputData;
            inputData = nullptr;
        }
    }

    std::istream & Car::read(std::istream &is) {
        if (isCsv()) {
            Vehicle::read(is);
            if (getVehicleInputData() != nullptr) {
                char* inputData = new char[strlen(getVehicleInputData()) + 1];
                strcpy(inputData, getVehicleInputData());
                char result[4][255];
                int counter = 0;
                int arrayIndex = 0;
                int carWashResultLength = 0;
                int dataLen = strlen(inputData);
                for (int runner = 0; runner < dataLen; ++runner) {
                    if (inputData[runner] != ',') {
                        result[arrayIndex][counter] = inputData[runner];
                        ++counter;
                        if (arrayIndex == 3) {
                            ++carWashResultLength;
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

                if (carWashResultLength == 1) {
                    if (result[3][0] == '0' && isDigit(result[3][0])) {
                        setCarWashState(false);
                        appendNewDataToVehicleData(",0");
                    } else if (result[3][0] == '1') {
                        setCarWashState(true);
                        appendNewDataToVehicleData(",1");
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
            std::cout << "\nCar information entry" << std::endl;
            Vehicle::read(is);
            std::cout << "Carwash while parked? (Y)es/(N)o: ";
            if (getUserDecision()) {
                setCarWashState(true);
            }
        }
        return is;
    };
    std::ostream & Car::write(std::ostream &os) const {
        if (isEmpty()) {
            os << "Invalid Car Object" << std::endl;
        } else {
            if (isCsv()) {
                os << "C,";
            } else {
                os << "Vehicle type: Car" << std::endl;
            }
            Vehicle::write(os);
            if (isCsv()) {
                os << carWashState << std::endl;
            } else {
                if (carWashState) {
                    os << "With Carwash" << std::endl;
                } else {
                    os << "Without Carwash" << std::endl;
                }
            }
        }
        return os;
    };

    bool Car::isEmpty() const {
        bool state = false;
         if (Vehicle::isEmpty()) {
             if (carWashState == false) {
                 state = true;
             }
         }
         return state;
    };
    void Car::setEmpty() {
        Vehicle::setEmpty();
        carWashState = false;
    };
    void Car::setToEmptyState() {
        Vehicle::setToEmptyState();
        carWashState = false;
    };

    bool Car::getUserDecision() {
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
    }
}
