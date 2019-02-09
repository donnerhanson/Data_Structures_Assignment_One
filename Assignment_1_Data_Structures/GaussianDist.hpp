//
//  GaussianDist.hpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/8/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#ifndef GaussianDist_hpp
#define GaussianDist_hpp

#include <stdio.h>
#include <iostream>
#include <string>

#include "ProbabilityCalc.hpp"
#include "VarianceCalc.hpp"

using namespace std;
class GaussianDist
{
public:
    // The relative frequency of nucleotides will also follow the statistics calculated above. -- Assuming only frequency of single nucleotides
    friend ostream& operator << (ostream& out, const GaussianDist &gd);

    GaussianDist(VarianceCalc& varCalc) : gaussMean(varCalc.getMean()), gaussVariance(varCalc.getVarianceResult()), randOne(0), randTwo(0), standardGauss(0)
    {
        cout << "GAUSS MEAN: " << gaussMean << "\n";
        cout << "GAUSS VAR : " << gaussVariance << "\n";
    };
    void setRandOne(double num)
    {
        randOne = num;
    }
    void setRandTwo(double num)
    {
        randTwo = num;
    }
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
