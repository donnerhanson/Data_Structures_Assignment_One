//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : NucleoProb.cpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : nucleoProb used to compare for bubble sort
//               algorithm
//================================================================

#include "NucleoProb.hpp"

bool operator < (const nucleoProb &lhs, const nucleoProb &rhs)
{
    return lhs.prob < rhs.prob;
}
