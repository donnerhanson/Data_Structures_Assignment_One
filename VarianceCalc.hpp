//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : VarianceCalc.hpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : Functions outlines for calculation
//               of amount of lines, variance in line lengths, the
//               mean of lengths and the standard deviation
//================================================================

#ifndef Calculator_hpp
#define Calculator_hpp

#include <iosfwd>
#include <string>

#include "StringUtility.hpp"

class VarianceCalc
{
    friend ostream& operator << (ostream& out, const VarianceCalc &vc);
public:
    VarianceCalc() : numLines(0), sumLineLengths(0), mean(0), variance(0), varianceNumeratorTotal(0), varianceLineLength(0), varianceResult(0),standardDeviation(0) {};
    double getNumLines();
    double getSumLineLengths();
    double getMean();
    double getVarianceResult();
    
    void setMean();
    
    void addLine(const string &str);
    void CalculateVarianceNumerator(const string &str);
    void CalculateVarianceResult();
    void CalculateStandardDeviation();
    
    
private:
    double numLines;
    double sumLineLengths;
    double mean;
    double variance;
    double varianceNumeratorTotal;
    double varianceLineLength;
    double varianceResult;
    double standardDeviation;
};

ostream& operator << (ostream& out, const VarianceCalc &vc);

#endif /* Calculator_hpp */
