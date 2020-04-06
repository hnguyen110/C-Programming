/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 3
Module: Menu
Filename: ReadWritable.cpp
Version 1.0
Author	Hien Dao The Nguyen
Revision History
-----------------------------------------------------------
Date      Reason
2020/03/23  Preliminary release
2020/03/23  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include "ReadWritable.h"

namespace sdds {
    ReadWritable::ReadWritable() {
        commaSeparatedValue = false;
    }

    ReadWritable::~ReadWritable() {

    }

    bool ReadWritable::isCsv() const {
        return commaSeparatedValue;
    }

    void ReadWritable::setCsv(bool value) {
        commaSeparatedValue = value;
    }

    std::istream&operator>>(std::istream& is, ReadWritable& readObj) {
        readObj.read(is);
        return is;
    }

    std::ostream&operator<<(std::ostream& os, const ReadWritable& writeObj) {
        writeObj.write(os);
        return os;
    }
}