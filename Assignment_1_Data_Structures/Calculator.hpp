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

#include "Utility.hpp"

class Calculator
{
public:
    Calculator(ifstream &inFile)
    {
        ;
    }
private:
    double numLines;
    double sumLineLengths;
    double mean;
};

#endif /* Calculator_hpp */
