//
//  ProbabilityCalc.cpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//


#include <iomanip>
#include <iostream>
#include <string>

#include "NucleoProb.hpp"
#include "ProbabilityCalc.hpp"

using namespace std;

bool isEvenStrLen(const string& str)
{
    if ((str.length()%2) == 0)
        return true;
    return false;
}

const int PAIR_LEN = 2;

// Check each individual letter and increase total if valid
void ProbabilityCalc::ReadSingleOccurrences(string const &str)
{
    char letter;
    for (int i(0); i < str.length(); ++i)
    {
        letter = str.at(i);
        switch (letter)
        {
            case 'A':
                numA++;
                totalNucleos++;
                break;
            case 'C':
                numC++;
                totalNucleos++;
                break;
            case 'T':
                numT++;
                totalNucleos++;
                break;
            case 'G':
                numG++;
                totalNucleos++;
            default:
                break;
        }
        
    }
}

// copy string and test first 2 for string comp
// pop 2 front letters off
// repeat
// ASSUMING EVEN PAIRS - will run but will recieve erroneous results
void ProbabilityCalc::ReadPairedOccurrences(string const &str)
{
    //str.substr (3,5)
    //tempStr = str.substr(index, length)
    if(strUt.isEvenStrLen(str))
    {
        string tempStr;
        char first;
        char second;
        for (int i(0); i < str.length(); i+=PAIR_LEN)
        {
            tempStr = str.substr(i,PAIR_LEN);
            first = tempStr.at(0);
            second = tempStr.at(1);
            // using switch for mild optimization
            switch (first)
            {
                case 'A':
                    switch (second)
                {
                    case 'A':
                        ++numAA;
                        ++totalPairs;
                        break;
                    case 'C':
                        ++numAC;
                        ++totalPairs;
                        break;
                    case 'T':
                        ++numAT;
                        ++totalPairs;
                        break;
                    case 'G':
                        ++numAG;
                        ++totalPairs;
                        break;
                    default:
                        break;
                }
                    break;
                case 'C':
                    switch (second)
                {
                    case 'A':
                        ++numCA;
                        ++totalPairs;
                        break;
                    case 'C':
                        ++numCC;
                        ++totalPairs;
                        break;
                    case 'T':
                        ++numCT;
                        ++totalPairs;
                        break;
                    case 'G':
                        ++numCG;
                        ++totalPairs;
                        break;
                }
                case 'T':
                    switch (second)
                {
                    case 'A':
                        ++numTA;
                        ++totalPairs;
                        break;
                    case 'C':
                        ++numTC;
                        ++totalPairs;
                        break;
                    case 'T':
                        ++numTT;
                        ++totalPairs;
                        break;
                    case 'G':
                        ++numTG;
                        ++totalPairs;
                        break;
                    default:
                        break;
                }
                case 'G':
                    switch (second)
                {
                    case 'A':
                        ++numGA;
                        ++totalPairs;
                        break;
                    case 'C':
                        ++numGC;
                        ++totalPairs;
                        break;
                    case 'T':
                        ++numGT;
                        ++totalPairs;
                        break;
                    case 'G':
                        ++numGG;
                        ++totalPairs;
                        break;
                    default:
                        break;
                }
                default:
                    break;
            };
        }
    }
}

void ProbabilityCalc::sortProbabilities()
{
    // if a prob is highest highest char = A etc
     aProb.setValues(getNumA()/getTotalNucleos(), 'A');
     cProb.setValues(getNumC()/getTotalNucleos(), 'C');
     tProb.setValues(getNumT()/getTotalNucleos(), 'T');
     gProb.setValues(getNumG()/getTotalNucleos(), 'G');
    for (int i(0); i < 4; ++i){
    if (aProb < cProb)
        swap(aProb, cProb);
    if (tProb < gProb)
        swap(tProb, gProb);
    if (aProb < tProb)
        swap(aProb, tProb);
    if (cProb < gProb)
        swap(cProb, gProb);
    if (cProb < tProb)
        swap(cProb, tProb);}
    // sorted letters and numbers stored to nucleoProb private members
    highest = aProb.getNucleo(); second = cProb.getNucleo(); third = tProb.getNucleo(); lowest = gProb.getNucleo();
    highNum = aProb.getProb(); secondNum = cProb.getProb(); thirdNum = tProb.getProb(); lowNum = gProb.getProb();
}

ostream& operator << (ostream& out, const ProbabilityCalc &pc)
{
    stringstream ss;
    ss << "Nucleotide    Probability\n"
    << "A:  " << left << setw(6) << pc.numA << "    " << pc.numA/pc.totalNucleos
    << "\nC:  " << setw(6) << pc.numC << "    " << pc.numC/pc.totalNucleos
    << "\nT:  " << setw(6)  << pc.numT << "    " << pc.numT/pc.totalNucleos
    << "\nG:  " << setw(6)  << pc.numG << "    " << pc.numG/pc.totalNucleos
    << "\nAA: " << setw(6)  << pc.numAA <<"    " << pc.numAA/pc.totalPairs
    << "\nAC: " << setw(6)  << pc.numAC <<"    " << pc.numAC/pc.totalPairs
    << "\nAT: " << setw(6)  << pc.numAT <<"    " << pc.numAT/pc.totalPairs
    << "\nAG: " << setw(6)  << pc.numAG <<"    " << pc.numAG/pc.totalPairs
    << "\nCA: " << setw(6)  << pc.numCA <<"    " << pc.numCA/pc.totalPairs
    << "\nCC: " << setw(6)  << pc.numCC <<"    " << pc.numCC/pc.totalPairs
    << "\nCT: " << setw(6)  << pc.numCT <<"    " << pc.numCT/pc.totalPairs
    << "\nCG: " << setw(6)  << pc.numCG <<"    " << pc.numCG/pc.totalPairs
    << "\nTA: " << setw(6)  << pc.numTA <<"    " << pc.numTA/pc.totalPairs
    << "\nTC: " << setw(6)  << pc.numTC <<"    " << pc.numTC/pc.totalPairs
    << "\nTT: " << setw(6)  << pc.numTT <<"    " << pc.numTT/pc.totalPairs
    << "\nTG: " << setw(6)  << pc.numTG <<"    " << pc.numTG/pc.totalPairs
    << "\nGA: " << setw(6)  << pc.numGA <<"    " << pc.numGA/pc.totalPairs
    << "\nGC: " << setw(6)  << pc.numGC <<"    " << pc.numGC/pc.totalPairs
    << "\nGT: " << setw(6)  << pc.numGT <<"    " << pc.numGT/pc.totalPairs
    << "\nGG: " << setw(6)  << pc.numGG <<"    " << pc.numGG/pc.totalPairs << "\n";
    string ssString = ss.str();
    out << ssString;
    
    return out;
}


