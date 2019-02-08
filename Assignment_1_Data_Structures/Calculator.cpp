//
//  Calculator.cpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#include "Calculator.hpp"

double Calculator::getNumLines()
{
    return numLines;
}
double Calculator::getSumLineLengths()
{
    return sumLineLengths;
}
double Calculator::getMean()
{
    return mean;
}

void Calculator::setMean()
{
    mean = sumLineLengths/numLines;
}

double Calculator::getVarianceResult()
{
    return varianceResult;
}

void Calculator::addLine(const string &str)
{
    numLines++;
    sumLineLengths+=str.length();
}

void Calculator::CalculateVarianceNumerator(const string &str)
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
void Calculator::CalculateVarianceResult()
{
        varianceResult = varianceNumeratorTotal/numLines;
}


