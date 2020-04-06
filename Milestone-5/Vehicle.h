/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 5
Module: Vehicle
Filename: Vehicle.h
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

#ifndef MILESTONE_4_VEHICLE_H
#define MILESTONE_4_VEHICLE_H

#include <iostream>
#include <cstring>
#include <cctype>
#include "ReadWritable.h"

namespace sdds {
#define MAX_LICENSE_LENGTH 8

    class Vehicle : public ReadWritable{
        char* m_licensePlate;
        char* m_makeAndModel;
        char* vehicleInputData;
        int m_parkingSpotNumber;

    public:
        Vehicle&operator=(const Vehicle&) = delete;
        Vehicle(const Vehicle&) = delete;

        Vehicle();
        Vehicle(const char*, const char*);
        ~Vehicle() override;

        int getParkingSpot() const;
        void setParkingSpot(int);
        friend bool operator==(const Vehicle&, const Vehicle&);
        friend bool operator==(const Vehicle&, const char*);
        std::istream & read(std::istream &) override;
        std::ostream & write(std::ostream &) const override;

    protected:
        virtual void setEmpty();
        virtual void setToEmptyState();

        virtual bool isEmpty() const;
        char* getLicensePlate() const;
        void setLicensePlate(const char*);
        char* getMakeModel() const;
        void setMakeModel(const char*);
        char* getVehicleInputData() const;
    };

    bool validateVehicleData(const char*, const char*);
    bool validateReadStreamData(const char*, const char*, const char*);
    void toLowerCase(char*);
    void toUpperCase(char*);
    bool isDigit(char);
    bool isIdentical(const char*, const char*);
    bool isIntegerNumber(const char*);
}


#endif //MILESTONE_4_VEHICLE_H
