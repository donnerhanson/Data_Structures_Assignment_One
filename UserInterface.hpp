//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : UserInterface.hpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : Function to check if the user would like to continue
//================================================================

#ifndef UserInterface_hpp
#define UserInterface_hpp

#include "StringUtility.hpp"

class UserInterface{
public:
    bool CheckForYesNo();
private:
    StringUtility helper;
};
#endif /* UserInterface_hpp */
