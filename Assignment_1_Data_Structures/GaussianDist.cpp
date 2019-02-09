//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : GaussianDist.cpp
// Assignment  : Assignment 1
// Version     : 1.2
// Instructor  : Rene German
// Description : Functions For Calculating Gaussian Distribution
//               of nucleotides calculated by ProbabilityCalc and
//               VarianceCalc
//================================================================

#include "GaussianDist.hpp"
#include "ProbabilityCalc.hpp"
#include <cmath>
#include <string>

using namespace std;

const double NEG_TWO = -2.0;
const double POS_TWO = 2.0;
void GaussianDist::calcLenOfStr()
{
    newStrLen = static_cast<int>(sqrt(gaussVariance) * standardGauss + gaussMean);
}

void GaussianDist::boxMuellerTransform()
{
    standardGauss = sqrt(NEG_TWO * log(randOne)) * cos(POS_TWO * M_PI * randTwo);
}

double GaussianDist::generateRandomDouble()
{
    double randNum = ((double)rand() / (double)RAND_MAX);
    return randNum;
}

void GaussianDist::createRandomizedString(ProbabilityCalc &pc)
{
    double randNum;
    
//    double aVal = pc.getNumA()/pc.getTotalNucleos();
//    double cVal = pc.getNumC()/pc.getTotalNucleos();
//    double tVal = pc.getNumT()/pc.getTotalNucleos();
//    double gVal = pc.getNumG()/pc.getTotalNucleos();
//
    // in probability calc and nucleoProb
    string highChar(1,pc.getHighest()), secondChar(1,pc.getSecond()), thirdChar(1,pc.getThird()), lowChar(1,pc.getLowest());
    double highNum(pc.getHighNum()), secondNum(pc.getSecondNum()), thirdNum(pc.getThirdNum()), lowNum(pc.getLowNum());
    
    

    for (int i(0); i < newStrLen; ++i)
    {
        randNum = generateRandomDouble();
        if (randNum < lowNum)
            outPut.append(lowChar);
        if (randNum < lowNum + thirdNum)
        outPut.append(thirdChar);
        if (randNum < lowNum + thirdNum + secondNum)
        outPut.append(secondChar);
        else
        outPut.append(highChar);
    }
}

ostream& operator << (ostream& out, const GaussianDist &gd)
{
    out << gd.outPut << "\n";
    return out;
}
