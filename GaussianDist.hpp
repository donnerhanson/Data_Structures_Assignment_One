//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : GaussianDist.hpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : Functions Outlines and Inlines For Calculating
//               Gaussian Distribution of nucleotides calculated by
//               ProbabilityCalc and VarianceCalc
//================================================================

#ifndef GaussianDist_hpp
#define GaussianDist_hpp

#include <iosfwd>
#include <string>

#include "ProbabilityCalc.hpp"
#include "VarianceCalc.hpp"

using namespace std;
class GaussianDist
{
public:
    // The relative frequency of nucleotides will also follow the statistics calculated above. -- Assuming only frequency of single nucleotides
    friend ostream& operator << (ostream& out, const GaussianDist &gd);
    
    GaussianDist(VarianceCalc& varCalc) : gaussMean(varCalc.getMean()), gaussVariance(varCalc.getVarianceResult()), randOne(0), randTwo(0), standardGauss(0){};
    void setRandOne(double num){randOne = num;}
    void setRandTwo(double num){randTwo = num;}
    void boxMuellerTransform();
    void calcLenOfStr();
    double getRandOne()const{return randOne;}
    double getRandTwo()const{return randTwo;}
    double getStandardGauss()const{return standardGauss;}
    int getNewStrLen()const{return newStrLen;}
    double generateRandomDouble();
    void createRandomizedString(ProbabilityCalc& pc);
    void eraseString(){outPut.clear();}
    
private:
    double gaussMean;
    double gaussVariance;
    double randOne, randTwo, standardGauss;
    int newStrLen;
    string outPut;
    
};
ostream& operator << (ostream& out, const GaussianDist &gd);

#endif /* GaussianDist_hpp */
