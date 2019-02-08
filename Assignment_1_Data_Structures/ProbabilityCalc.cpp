//
//  ProbabilityCalc.cpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#include "ProbabilityCalc.hpp"
#include <iostream>
#include <string>
using namespace std;

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
// ASSUMING EVEN PAIRS
void ProbabilityCalc::ReadPairedOccurrences(string const &str)
{
    //str.substr (3,5)
    //tempStr = str.substr(index, length)
    string tempStr;
    char first;
    char second;
    for (int i(0); i < str.length(); i+=PAIR_LEN)
    {
        tempStr = str.substr(i,PAIR_LEN);
        first = tempStr.at(0);
        second = tempStr.at(1);
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
    
    // using switch for mild speed boost
}


ostream& operator << (ostream& out, const ProbabilityCalc &pc)
{
    stringstream ss;
    ss << "Nucleotide  Probability\n"
    <<"A: " << pc.numA    << "    " << pc.numA/pc.totalNucleos
    << "\nC: " << pc.numC << "    " << pc.numC/pc.totalNucleos
    << "\nT: " << pc.numT << "    " << pc.numT/pc.totalNucleos
    << "\nG: " << pc.numG << "    " << pc.numG/pc.totalNucleos
    <<"\nAA: " << pc.numAA <<"    " << pc.numAA/pc.totalPairs
    <<"\nAC: " << pc.numAC <<"    " << pc.numAC/pc.totalPairs
    <<"\nAT: " << pc.numAT <<"    " << pc.numAT/pc.totalPairs
    <<"\nAG: " << pc.numAG <<"    " << pc.numAG/pc.totalPairs
    <<"\nCA: " << pc.numCA <<"    " << pc.numCA/pc.totalPairs
    <<"\nCC: " << pc.numCC <<"    " << pc.numCC/pc.totalPairs
    <<"\nCT: " << pc.numCT <<"    " << pc.numCT/pc.totalPairs
    <<"\nCG: " << pc.numCG <<"    " << pc.numCG/pc.totalPairs
    <<"\nTA: " << pc.numTA <<"    " << pc.numTA/pc.totalPairs
    <<"\nTC: " << pc.numTC <<"    " << pc.numTC/pc.totalPairs
    <<"\nTT: " << pc.numTT <<"    " << pc.numTT/pc.totalPairs
    <<"\nTG: " << pc.numTG <<"    " << pc.numTG/pc.totalPairs
    <<"\nGA: " << pc.numGA <<"    " << pc.numGA/pc.totalPairs
    <<"\nGC: " << pc.numGC <<"    " << pc.numGC/pc.totalPairs
    <<"\nGT: " << pc.numGT <<"    " << pc.numGT/pc.totalPairs
    <<"\nGG: " << pc.numGG <<"    " << pc.numGG/pc.totalPairs << "\n";
    string ssString = ss.str();
    out << ssString;
    
    return out;
}


