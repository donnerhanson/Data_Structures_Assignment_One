//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : StringUtility.hpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : Outline for functions that allow for string
//               manipulation for easier processing.
//================================================================

#ifndef Utility_hpp
#define Utility_hpp

#include <iosfwd>
#include <string>


using namespace std;

const string ASK_CONTINUE = "Would you like to continue?...(Y/N)\n";

class StringUtility
{
    friend ostream& operator << (ostream& out, const StringUtility &su);
public:
    StringUtility() : linesOmitted(0){};
    string Capitalize(string &str);
    bool isEvenStrLen(const string& str);
    string RemoveErroneousChars(string& str);
    
    void operator++()
    {
        linesOmitted+=1;
    }
private:
    int linesOmitted;
};
ostream& operator << (ostream& out, const StringUtility &su);



#endif /* Utility_hpp */
