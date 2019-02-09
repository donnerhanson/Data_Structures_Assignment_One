//
//  Calculator.cpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#include "VarianceCalc.hpp"

#include <cmath>
#include <iostream>
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

