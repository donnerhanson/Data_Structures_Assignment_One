//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : NucleoProb.hpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : Class nucleoProb to store values similar to
//               a dictionary (for sorting values of probability)
//================================================================

#ifndef NucleoProb_hpp
#define NucleoProb_hpp

class nucleoProb{
public:
    nucleoProb(double prob,char nucleo) : prob(prob), nucleo(nucleo){}
    void setValues(double num,char letter)
    {
        prob = num;
        nucleo = letter;
    }
    double getProb()const{return prob;}
    char getNucleo()const{return nucleo;}
    friend bool operator < (const nucleoProb &lhs, const nucleoProb &rhs);
private:
    double prob;
    char nucleo;
};
bool operator < (const nucleoProb &lhs, const nucleoProb &rhs);

#endif /* NucleoProb_hpp */
