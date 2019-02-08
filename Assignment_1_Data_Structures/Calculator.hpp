//
//  Calculator.hpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#ifndef Calculator_hpp
#define Calculator_hpp

#include <stdio.h>
#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <cmath>
#include <ostream>
#include <string>

#include "StringUtility.hpp"

class Calculator
{
public:
    Calculator() : numLines(0), sumLineLengths(0), mean(0), variance(0), varianceNumeratorTotal(0) {};
    double getNumLines();
    double getSumLineLengths();
    double getMean();
    double getVarianceResult();
    
    void setMean();
    
    void CalculateVarianceNumerator(const string &str);
    void CalculateVarianceResult();
    void addLine(const string &str);
    
private:
    double numLines;
    double sumLineLengths;
    double mean;
    double variance;
    double varianceNumeratorTotal;
    double varianceLineLength;
    double varianceResult;
    

    
};

#endif /* Calculator_hpp */
