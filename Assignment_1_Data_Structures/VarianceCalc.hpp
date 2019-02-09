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
