//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : StringUtility.cpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : Definitions for functions that allow for string
//               manipulation for easier processing.
//================================================================

#include "StringUtility.hpp"
#include <algorithm>
#include <iosfwd>
#include <sstream>


string StringUtility::Capitalize(string &str)
{
    // use algorithm to uppercase all input
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

bool StringUtility::isEvenStrLen(const string& str)
{
    if ((str.length()%2) == 0)
        return true;
    return false;
}

//Pass string by reference (no copy constructed) and removes unwanted chars
string StringUtility::RemoveErroneousChars(string& str)
{
    string temp;
    
    for (int i(0); i < str.length(); ++i)
    {
        // if a correct letter add to temp string
        if(str.at(i) == 'A' || str.at(i) == 'C' ||
           str.at(i) == 'T' || str.at(i) == 'G')
            temp+=str.at(i);
    }
    // the referenced str now is updated program wide
    str = temp;
    return str;
}

ostream& operator << (ostream& out, const StringUtility &su)
{
    stringstream ss;
    ss << "Lines omitted from process: " << su.linesOmitted << "\n";
    string ssString = ss.str();
    out << ssString;
    return out;
}

