//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : StudentInfo.cpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : Student Information for assignment output
//================================================================

#include <ostream>

#include "StudentInfo.hpp"

ostream& operator << (ostream& out, const StudentInfo &si)
{
    out << "Name: " << si.name << "  " << "ID: " << si.studentID << "\n";
    return out;
}
