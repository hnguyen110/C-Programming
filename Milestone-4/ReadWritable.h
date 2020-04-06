/* ------------------------------------------------------
Name of Student: Hien Dao The Nguyen
Student Number: 103 152 195
Student Email: hnguyen110@myseneca.ca
OOP244 NII
-----------------------------------------------------------

Citation and Sources...
Final Project Milestone 3
Module: Menu
Filename: ReadWritable.h
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

#ifndef MILESTONE_3_READWRITABLE_H
#define MILESTONE_3_READWRITABLE_H

#include <iostream>

namespace sdds {
    class ReadWritable {
        bool commaSeparatedValue;

    public:
        ReadWritable();
        virtual ~ReadWritable();
        bool isCsv() const;
        void setCsv(bool);

        virtual std::istream& read(std::istream&) = 0;
        virtual std::ostream& write(std::ostream&) const= 0;
    };
    std::istream&operator>>(std::istream&, ReadWritable&);
    std::ostream&operator<<(std::ostream&, const ReadWritable&);
}


#endif //MILESTONE_3_READWRITABLE_H
