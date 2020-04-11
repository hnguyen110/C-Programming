/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 5
Module: Vehicle
Filename: Vehicle.cpp
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
#include "Vehicle.h"

namespace sdds {
    Vehicle::Vehicle() {
        setToEmptyState();
    }

    Vehicle::Vehicle(const char* licensePlate, const char* makeAndModel) {
        if (validateVehicleData(licensePlate, makeAndModel)) {
            m_licensePlate = new char[strlen(licensePlate) + 1];
            strcpy(m_licensePlate, licensePlate);

            m_makeAndModel = new char[strlen(makeAndModel) + 1];
            strcpy(m_makeAndModel, makeAndModel);
            m_parkingSpotNumber = 0;
        } else {
            setToEmptyState();
        }
    }

    Vehicle::~Vehicle() {
        setEmpty();
        setToEmptyState();
    }

    int Vehicle::getParkingSpot() const {
        return m_parkingSpotNumber;
    }

    void Vehicle::setParkingSpot(int parkingNumber) {
        if (parkingNumber >= 0) {
            m_parkingSpotNumber = parkingNumber;
        } else {
            setEmpty();
        }
    }

    bool operator==(const Vehicle& firstVehicle, const Vehicle& secondVehicle) {
        bool state = false;
        if (isIdentical(firstVehicle.getLicensePlate(), secondVehicle.getLicensePlate())) {
            state = true;
        }
        return state;
    }

    bool operator==(const Vehicle& vehicle, const char* licensePlate) {
        bool state = false;
        if (isIdentical(vehicle.getLicensePlate(), licensePlate)) {
            state = true;
        }
        return state;
    }

    std::istream & Vehicle::read(std::istream& is) {
        if (ReadWritable::isCsv()) {
            char data[255];
//            is >> data;
            is.getline(data, sizeof(data));
            if (is.fail()) {
                is.clear();
                is.ignore(1000, '\n');
                setEmpty();
                return is;
            } else {
                vehicleInputData = new char[strlen(data) + 1];
                strcpy(vehicleInputData, data);
                setVehicleData();
            }
        } else {
            // Set the license plate from the keyboard
            char licensePlate[255];
            std::cout << "Enter Licence Plate Number: ";
//            is >> licensePlate;
            is.getline(licensePlate, sizeof(licensePlate));
            if (is.fail()) {
                is.clear();
                is.ignore(1000, '\n');
                setEmpty();
                return is;
            } else {
                int licensePlateLen = strlen(licensePlate);
                while (licensePlateLen > MAX_LICENSE_LENGTH || licensePlateLen == 0) {
                    std::cout << "Invalid Licence Plate, try again: ";
//                    is >> licensePlate;
                    is.getline(licensePlate, sizeof(licensePlate));
                    if (is.fail()) {
                        is.clear();
                        is.ignore(1000, '\n');
                        setEmpty();
                        return is;
                    }
                    licensePlateLen = strlen(licensePlate);
                }
                toUpperCase(licensePlate);
                setLicensePlate(licensePlate);
            }

            // Set the make and model from the keyboard
            char makeAndModel[255];
            std::cout << "Enter Make and Model: ";
//            is >> makeAndModel;
            is.getline(makeAndModel, sizeof(makeAndModel));
            if (is.fail()) {
                is.clear();
                is.ignore(1000, '\n');
                setEmpty();
                return is;
            } else {
                int makeAndModelLen = strlen(makeAndModel);
                while (makeAndModelLen < 2 || makeAndModelLen > 60) {
                    std::cout << "Invalid Make and model, try again: ";
//                    is >> makeAndModel;
                    is.getline(makeAndModel, sizeof(makeAndModel));
                    if (is.fail()) {
                        is.clear();
                        is.ignore(1000, '\n');
                        setEmpty();
                        return is;
                    }
                    makeAndModelLen = strlen(makeAndModel);
                }
                setMakeModel(makeAndModel);
            }
        }
        return is;
    }

    std::ostream & Vehicle::write(std::ostream& os) const {
        if (isEmpty()) {
            os << "Invalid Vehicle Object" << std::endl;
        } else {
            if (isCsv()) {
                os << m_parkingSpotNumber << ',' << m_licensePlate << ',' << m_makeAndModel << ',';
            } else {
                os << "Parking Spot Number: ";
                if (m_parkingSpotNumber == 0) {
                    os << "N/A";
                } else {
                    os << m_parkingSpotNumber;
                }
                os << std::endl;

                os << "Licence Plate: " << m_licensePlate << std::endl;

                os << "Make and Model: " << m_makeAndModel << std::endl;
            }
        }
        return os;
    }

    void Vehicle::setEmpty() {
        delete[] m_licensePlate;
        delete[] m_makeAndModel;
        delete[] vehicleInputData;
        setToEmptyState();
    }

    void Vehicle::setToEmptyState() {
        m_licensePlate = nullptr;
        m_makeAndModel = nullptr;
        vehicleInputData = nullptr;
        m_parkingSpotNumber = 0;
    }

    bool Vehicle::isEmpty() const {
        bool state = false;
        if (m_licensePlate == nullptr) {
            if (m_makeAndModel == nullptr) {
                if (m_parkingSpotNumber == 0) {
                    state = true;
                }
            }
        }
        return state;
    }

    char* Vehicle::getLicensePlate() const {
        return m_licensePlate;
    }

    void Vehicle::setLicensePlate(const char* licensePlate) {
        delete[] m_licensePlate;
        m_licensePlate = nullptr;
        m_licensePlate = new char[strlen(licensePlate) + 1];
        strcpy(m_licensePlate, licensePlate);
    }

    char* Vehicle::getMakeModel() const {
        return m_makeAndModel;
    }

    void Vehicle::setMakeModel(const char* makeAndModel) {
        delete[] m_makeAndModel;
        m_makeAndModel = nullptr;
        m_makeAndModel = new char[strlen(makeAndModel) + 1];
        strcpy(m_makeAndModel, makeAndModel);
    }

    char* Vehicle::getVehicleInputData() const {
        return vehicleInputData;
    }

    void Vehicle::setVehicleInputData(const char* inputData) {
        if (vehicleInputData != nullptr) {
            delete[] vehicleInputData;
            vehicleInputData = nullptr;
        }
        vehicleInputData = new char[strlen(inputData) + 1];
        strcpy(vehicleInputData, inputData);
    }

    void Vehicle::setVehicleData() {
        if (getVehicleInputData() != nullptr) {
            char data[255];
            char result[3][255];
            int counter = 0;
            int arrayIndex = 0;
            strcpy(data, vehicleInputData);
            int dataLen = strlen(data);
            for (int runner = 0; runner < dataLen; ++runner) {
                if (data[runner] != ',') {
                    result[arrayIndex][counter] = data[runner];
                    ++counter;
                } else {
                    result[arrayIndex][counter] = '\0';
                    ++arrayIndex;
                    counter = 0;
                    if (arrayIndex == 3) {
                        break;
                    }
                }
            }

            if (validateReadStreamData(result[0], result[1], result[2])) {
                setParkingSpot(std::stoi(result[0]));
                toUpperCase(result[1]);
                setLicensePlate(result[1]);
                setMakeModel(result[2]);
            } else {
                setEmpty();
            }
        } else {
            setEmpty();
        }
    }

    void Vehicle::appendNewDataToVehicleData(const char * additionalStr) {
        char tempData[255] = "";
        if (vehicleInputData != nullptr && strlen(vehicleInputData) != 0) {
            strcat(tempData, vehicleInputData);
        }
        if (additionalStr != nullptr) {
            strcat(tempData, additionalStr);
        }
        delete[] vehicleInputData;
        vehicleInputData = nullptr;
        vehicleInputData = new char[strlen(tempData) + 1];
        strcpy(vehicleInputData, tempData);
    }

    bool validateVehicleData(const char* licensePlate, const char* makeAndModel) {
        bool state = false;
        if (licensePlate != nullptr && strlen(licensePlate) != 0) {
            if (strlen(licensePlate) <= MAX_LICENSE_LENGTH) {
                if (makeAndModel != nullptr && strlen(makeAndModel) != 0) {
                    if (strlen(makeAndModel) >= 2 && strlen(makeAndModel) <= 60) {
                        state = true;
                    }
                }
            }
        }
        return state;
    }

    void toLowerCase(char* originalString) {
        int length = strlen(originalString);
        for (int counter = 0; counter < length; ++counter) {
            if (!isDigit(originalString[counter])) {
                originalString[counter] = tolower(originalString[counter]);
            }
        }
    }

    void toUpperCase(char* originalString) {
        int length = strlen(originalString);
        for (int counter = 0; counter < length; ++counter) {
            if (!isDigit(originalString[counter])) {
                originalString[counter] = toupper(originalString[counter]);
            }
        }
    }

    bool isDigit(char currentChar) {
        char naturalNumberString[11] = "0123456789";
        for (int counter = 0; counter < 10; ++counter) {
            if (currentChar == naturalNumberString[counter]) {
                return true;
            }
        }
        return false;
    }

    bool isIdentical(const char* firstString, const char* secondString) {
        int firstLen = strlen(firstString);
        int secondLen = strlen(secondString);
        if (firstLen == secondLen) {
            char firstCopy[255];
            char secondCopy[255];
            strcpy(firstCopy, firstString);
            strcpy(secondCopy, secondString);
            toLowerCase(firstCopy);
            toLowerCase(secondCopy);
            for (int counter = 0; counter < firstLen; ++counter) {
                if (firstCopy[counter] != secondCopy[counter]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool isIntegerNumber(const char* string) {
        int stringLen = strlen(string);
        for (int counter = 0; counter < stringLen; ++counter) {
            if (!isDigit(string[counter])) {
                return false;
            }
        }
        return true;
    }

    bool validateReadStreamData(const char* parkingSpotNumber, const char* licensePlate, const char* makeAndModel) {
        bool state = false;
        if (isIntegerNumber(parkingSpotNumber)) {
            if (validateVehicleData(licensePlate, makeAndModel)) {
                state = true;
            }
        }
        return state;
    }

    void getString(char inputString[], int maxLength) {
        int counter = 0;
        int userChar;
        while ((userChar = getchar()) != EOF && userChar != '\n') {
            if (counter < maxLength) {
                inputString[counter] = (char) userChar;
                ++counter;
            }
        }
        inputString[counter] = '\0';
    }
}
