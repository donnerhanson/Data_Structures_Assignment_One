//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : ProbabilityCalc.hpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : Functions Outlines and Inlines For Calculating
//               Probability of nucleotides
//================================================================

#ifndef ProbabilityCalc_hpp
#define ProbabilityCalc_hpp

#include <string>
#include <sstream>

#include "NucleoProb.hpp"
#include "StringUtility.hpp"

using namespace std;
class ProbabilityCalc
{
    friend ostream& operator << (ostream& out, const ProbabilityCalc &pc);
public:
    ProbabilityCalc() : numA(0), numC(0), numT(0),
    numG(0),numAA(0),numAC(0),numAT(0),numAG(0),numCA(0),
    numCC(0),numCT(0),numCG(0),numTA(0),numTC(0),numTT(0),
    numTG(0),numGA(0),numGC(0),numGT(0),numGG(0), totalNucleos(0), totalPairs(0), aProb(0,0), cProb(0,0), tProb(0,0), gProb(0,0) {};
    
    void ReadSingleOccurrences(string const &str);
    void ReadPairedOccurrences(string const &str);
    
    
    double getNumA()const{return numA;}
    double getNumC()const{return numC;}
    double getNumT()const{return numT;}
    double getNumG()const{return numG;}
    double getTotalNucleos()const{return totalNucleos;}
    void sortProbabilities();
    char getHighest(){return highest;}
    char getSecond(){return second;}
    char getThird(){return third;}
    char getLowest(){return lowest;}
    double getHighNum(){return highNum;}
    double getSecondNum(){return secondNum;}
    double getThirdNum(){return thirdNum;}
    double getLowNum(){return lowNum;}
    
private:
    double numA, numC, numT, numG, numAA,
    numAC, numAT, numAG, numCA, numCC,
    numCT, numCG, numTA, numTC, numTT, numTG,
    numGA, numGC, numGT, numGG;
    double totalNucleos, totalPairs;
    double singleProb, pairProb;
    nucleoProb aProb, cProb, tProb, gProb;
    char highest, second, third, lowest;
    double highNum, secondNum, thirdNum, lowNum;
    StringUtility strUt;
};

ostream& operator << (ostream& out, const ProbabilityCalc &pc);

#endif /* ProbabilityCalc_hpp */
