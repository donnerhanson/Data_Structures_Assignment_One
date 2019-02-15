//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : VarianceCalc.cpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : Functions that allow for calculation
//               of amount of lines, variance in line lengths, the
//               mean of lengths and the standard deviation
//================================================================

#include "VarianceCalc.hpp"

#include <cmath>
#include <sstream>

using namespace std;

double VarianceCalc::getNumLines()
{
    return numLines;
}
double VarianceCalc::getSumLineLengths()
{
    return sumLineLengths;
}
double VarianceCalc::getMean()
{
    return mean;
}

double VarianceCalc::getVarianceResult()
{
    return varianceResult;
}

void VarianceCalc::addLine(const string &str)
{
    numLines++;
    sumLineLengths+=str.length();
}

void VarianceCalc::setMean()
{
    mean = sumLineLengths/numLines;
}

void VarianceCalc::CalculateVarianceNumerator(const string &str)
{
    double varianceToSquare = 0;
    // subtract the mean from data point
    varianceLineLength = str.length();
    // i.e. length - mean
    varianceToSquare = varianceLineLength - mean;
    // square the answer
    varianceToSquare *= varianceToSquare;
    // then add each to variable
    varianceNumeratorTotal += varianceToSquare;
}

void VarianceCalc::CalculateVarianceResult()
{
    varianceResult = varianceNumeratorTotal/numLines;
}

void VarianceCalc::CalculateStandardDeviation()
{
    standardDeviation = sqrt(varianceResult);
}

ostream& operator << (ostream& out, const VarianceCalc &vc)
{
    stringstream ss;
    ss << "Sum of lengths: " << vc.sumLineLengths << "\nMean of lengths: " << vc.mean << "\nVariance of lengths: " << vc.varianceResult << "\nStandard of deviation: " << vc.standardDeviation << "\n";
    string ssString = ss.str();
    out << ssString;
    return out;
}

