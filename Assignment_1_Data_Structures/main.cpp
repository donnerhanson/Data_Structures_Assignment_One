//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : main.cpp
// Assignment  : Assignment 1
// Version     : 1.2
// Instructor  : Rene German
// Description : main
//================================================================

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <cmath>
#include <ostream>
#include <string>
#include <time.h>

#include "GaussianDist.hpp"
#include "ProbabilityCalc.hpp"
#include "StringUtility.hpp"
#include "StudentInfo.hpp"
#include "VarianceCalc.hpp"




using namespace std;


const string ASK_NEW_FILE = "Enter next file path....\n";
const string NUM_CMD_ARGS_FAIL = "Not enough command line arguements...\n";

const int TOTAL_LINES_TO_PRINT = 1000;

bool IsBlank(ifstream& inFile)
{
    return inFile.peek() == ifstream::traits_type::eof();
}

// stack overflow - find first not white space
// if after iterating through string and not found
// true else false
bool NotWS(const string &str)
{
    return str.find_first_not_of(' ') != std::string::npos;
}

double generateRandomDouble()
{
    double randNum = ((double)rand() / (double)RAND_MAX);
    return randNum;
}

int main(int argc, const char * argv[])
{
    // if user wants to continue: prompted at end
    bool persist = true;
    bool isSecondFile = false ;
    string modeOne = "ios::out";
    string modeTwo = "ios::app";
    // general string manipulations: spaces, count, skip....
    StringUtility strManip;
    
    string filename = argv[1];
    // seed random number
    srand(static_cast<unsigned int>(time(NULL)));
    cout << argc << "\n";
    cout << argv[1] << "\n";
    cout << isSecondFile << "\n";
    while(persist)
    {
        
        if (argc == 2 && isSecondFile == false)
        {
            
            // open output file to put results
            ofstream output("DonnerHanson.txt", ios::out);
            if (!output.is_open())
            {
                cout << "Failed to open output file\n";
            }
            ifstream inFile(filename, ios::in);
            string line;
            if(inFile.is_open() && !IsBlank(inFile))
            {
                StudentInfo* student = new StudentInfo();
                VarianceCalc* varianceCalc = new VarianceCalc();
                // PT 1: get sum of lengths, num of lines, and mean
                while (getline(inFile, line))
                {
                    // Assert that all values will be capitalized
                    strManip.Capitalize(line);
                    strManip.RemoveErroneousChars(line);
                    // if the line is not whitespace and
                    // is even lenght add to results
                    if(NotWS(line) && strManip.isEvenStrLen(line))
                    {
                        varianceCalc->addLine(line);
                    }
                    else if (!strManip.isEvenStrLen(line))
                    {
                        // track ommited lines
                        ++strManip;
                    }
                }
                //PT 2 Reset file to beginning and calculate Variance
                // set mean length to all the found lines (all Length/numlines)
                varianceCalc->setMean();
                inFile.clear();
                inFile.seekg(0, ios::beg);
                while (getline(inFile, line))
                {
                    strManip.Capitalize(line);
                    strManip.RemoveErroneousChars(line);
                    if(NotWS(line) && strManip.isEvenStrLen(line))
                    {
                        varianceCalc->CalculateVarianceNumerator(line);
                    }
                }
                varianceCalc->CalculateVarianceResult();
                varianceCalc->CalculateStandardDeviation();
                
                //PT 3 Reset file to beginning
                // Calculate probability of nulceotides (singles)
                ProbabilityCalc *pc = new ProbabilityCalc();
                inFile.clear();
                inFile.seekg(0, ios::beg);
                while (getline(inFile, line))
                {
                    strManip.Capitalize(line);
                    strManip.RemoveErroneousChars(line);
                    if(NotWS(line) && strManip.isEvenStrLen(line))
                    {
                        pc->ReadSingleOccurrences(line);
                    }
                }
                //PT 4 Reset pointer to file to beginning
                // Calculate probability of nulceotides (pairs)
                inFile.clear();
                inFile.seekg(0, ios::beg);
                while (getline(inFile, line))
                {
                    strManip.Capitalize(line);
                    strManip.RemoveErroneousChars(line);
                    if(NotWS(line) && strManip.isEvenStrLen(line))
                    {
                        pc->ReadPairedOccurrences(line);
                    }
                }
                //TESTS TO COUT
//                cout << *student;
//                cout << *varianceCalc;
//                cout << *pc;
//                cout << strManip;
                // print results to file
                output << *student;
                output << strManip;
                output << *varianceCalc;
                output << *pc;
                output << filename << "\n";
                // close open files
                output.close();
                inFile.close();
                // open file for append and do other calcs
                ofstream output("DonnerHanson.txt", ios::app);
                if (!output.is_open())
                {
                    cout << "Failed to open output file\n";
                }
                // sort probabilities and generate DNA strings
                pc->sortProbabilities();
                GaussianDist* gd = new GaussianDist(*varianceCalc);
                for (int i(0); i < TOTAL_LINES_TO_PRINT ; ++i)
                {
                    // set a and b in Gaussian with random nums
                    gd->setRandOne(generateRandomDouble());
                    gd->setRandTwo(generateRandomDouble());
                    gd->boxMuellerTransform();
                    gd->calcLenOfStr();
                    gd->createRandomizedString(*pc);
                    output << *gd;
                    gd->eraseString();
                }
                // delete dynamically allocated resources
                delete student;
                delete pc;
                delete varianceCalc;
                delete gd;
                // close appending file
                output.close();
            }
            else if (IsBlank(inFile))
            {
                cout << "File entered is blank!\n";
            }
            else
            {
                cout << "File not opened!\n";
            }
        }
        else if (isSecondFile == true)
        {
            // open output file to put results
            ofstream output("DonnerHanson.txt", ios::app);
            if (!output.is_open())
            {
                cout << "Failed to open output file\n";
            }
            ifstream inFile(filename, ios::in);
            string line;
            if(inFile.is_open() && !IsBlank(inFile))
            {
                StudentInfo* student = new StudentInfo();
                VarianceCalc* varianceCalc = new VarianceCalc();
                // PT 1: get sum of lengths, num of lines, and mean
                while (getline(inFile, line))
                {
                    // Assert that all values will be capitalized
                    strManip.Capitalize(line);
                    strManip.RemoveErroneousChars(line);
                    // if the line is not whitespace and
                    // is even lenght add to results
                    if(NotWS(line) && strManip.isEvenStrLen(line))
                    {
                        varianceCalc->addLine(line);
                    }
                    else if (!strManip.isEvenStrLen(line))
                    {
                        // track ommited lines
                        ++strManip;
                    }
                }
                //PT 2 Reset file to beginning and calculate Variance
                // set mean length to all the found lines (all Length/numlines)
                varianceCalc->setMean();
                inFile.clear();
                inFile.seekg(0, ios::beg);
                while (getline(inFile, line))
                {
                    strManip.Capitalize(line);
                    strManip.RemoveErroneousChars(line);
                    if(NotWS(line) && strManip.isEvenStrLen(line))
                    {
                        varianceCalc->CalculateVarianceNumerator(line);
                    }
                }
                varianceCalc->CalculateVarianceResult();
                varianceCalc->CalculateStandardDeviation();
                
                //PT 3 Reset file to beginning
                // Calculate probability of nulceotides (singles)
                ProbabilityCalc *pc = new ProbabilityCalc();
                inFile.clear();
                inFile.seekg(0, ios::beg);
                while (getline(inFile, line))
                {
                    strManip.Capitalize(line);
                    strManip.RemoveErroneousChars(line);
                    if(NotWS(line) && strManip.isEvenStrLen(line))
                    {
                        pc->ReadSingleOccurrences(line);
                    }
                }
                //PT 4 Reset pointer to file to beginning
                // Calculate probability of nulceotides (pairs)
                inFile.clear();
                inFile.seekg(0, ios::beg);
                while (getline(inFile, line))
                {
                    strManip.Capitalize(line);
                    strManip.RemoveErroneousChars(line);
                    if(NotWS(line) && strManip.isEvenStrLen(line))
                    {
                        pc->ReadPairedOccurrences(line);
                    }
                }
                //TESTS TO COUT
                //                cout << *student;
                //                cout << *varianceCalc;
                //                cout << *pc;
                //                cout << strManip;
                // print results to file
                output << *student;
                output << strManip;
                output << *varianceCalc;
                output << *pc;
                output << filename << "\n";
                // close open files
                output.close();
                inFile.close();
                // open file for append and do other calcs
                ofstream output("DonnerHanson.txt", ios::app);
                if (!output.is_open())
                {
                    cout << "Failed to open output file\n";
                }
                // sort probabilities and generate DNA strings
                pc->sortProbabilities();
                GaussianDist* gd = new GaussianDist(*varianceCalc);
                for (int i(0); i < TOTAL_LINES_TO_PRINT ; ++i)
                {
                    // set a and b in Gaussian with random nums
                    gd->setRandOne(generateRandomDouble());
                    gd->setRandTwo(generateRandomDouble());
                    gd->boxMuellerTransform();
                    gd->calcLenOfStr();
                    gd->createRandomizedString(*pc);
                    output << *gd;
                    gd->eraseString();
                }
                // delete dynamically allocated resources
                delete student;
                delete pc;
                delete varianceCalc;
                delete gd;
                // close appending file
                output.close();
            }
            else if (IsBlank(inFile))
            {
                cout << "File entered is blank!\n";
            }
            else
            {
                cout << "File not opened!\n";
            }
        }
        else
        {
            cout << NUM_CMD_ARGS_FAIL;
        }
        cout << ASK_CONTINUE;
        persist = strManip.CheckForYesNo();
        // Ask for a new filename
        string newFilename;
        if (persist)
        {
            cout << "Continuing....\n\n";
            cout << ASK_NEW_FILE;
            getline(cin, newFilename);
            isSecondFile = true;
        }
        filename = newFilename;
    }
    cout << "Program terminated....\n\n";
    return 0;
}
