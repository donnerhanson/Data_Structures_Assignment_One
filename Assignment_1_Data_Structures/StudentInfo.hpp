//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : StudentInfo.h
// Assignment  : Assignment 1
// Version     : 1.2
// Instructor  : Rene German
// Description : Student Information for assignment output
//================================================================

#ifndef StudentInfo_hpp
#define StudentInfo_hpp

#include <iostream>
#include <stdio.h>
using namespace std;

class StudentInfo
{
    friend ostream& operator << (ostream& out, const StudentInfo &si);
public:
    StudentInfo(string name = "Donner Hanson", string studentID = "1276484") : name(name), studentID(studentID){};
private:
    string name;
    string studentID;
};

ostream& operator << (ostream& out, const StudentInfo &si);

#endif /* StudentInfo_hpp */
