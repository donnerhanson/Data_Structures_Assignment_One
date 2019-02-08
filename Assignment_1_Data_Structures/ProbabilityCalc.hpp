//
//  ProbabilityCalc.hpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#ifndef ProbabilityCalc_hpp
#define ProbabilityCalc_hpp

#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;
class ProbabilityCalc
{
    friend ostream& operator << (ostream& out, const ProbabilityCalc &pc);
public:
    ProbabilityCalc() : numA(0), numC(0), numT(0),
    numG(0),numAA(0),numAC(0),numAT(0),numAG(0),numCA(0),
    numCC(0),numCT(0),numCG(0),numTA(0),numTC(0),numTT(0),
    numTG(0),numGA(0),numGC(0),numGT(0),numGG(0), totalNucleos(0), totalPairs(0) {};
    
    void ReadSingleOccurrences(string const &str);
    void ReadPairedOccurrences(string const &str);
    
    
    double getNumA(){return numA;}
    double getNumC(){return numC;}
    double getNumT(){return numT;}
    double getNumG(){return numG;}
    
private:
    double numA, numC, numT, numG, numAA,
    numAC, numAT, numAG, numCA, numCC,
    numCT, numCG, numTA, numTC, numTT, numTG,
    numGA, numGC, numGT, numGG;
    double totalNucleos, totalPairs;
    double singleProb, pairProb;
};

ostream& operator << (ostream& out, const ProbabilityCalc &pc);

#endif /* ProbabilityCalc_hpp */
