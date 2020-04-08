/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 5
Module: Car
Filename: Car.h
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

#ifndef MILESTONE_5_CAR_H
#define MILESTONE_5_CAR_H

#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle {
        bool carWashState;

    public:
        Car&operator=(const Car&) = delete;
        Car(const Car&) = delete;

        Car();
        Car(const char*, const char*);
        ~Car();

        void setCarWashState(bool);
        bool getCarWashState() const;
        void setVehicleData() override;
        std::istream & read(std::istream &) override;
        std::ostream & write(std::ostream &) const override;

        bool isEmpty() const override;
        void setEmpty() override;
        void setToEmptyState() override;
        bool getUserDecision();
    };
}


#endif //MILESTONE_5_CAR_H
