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

#include "ProbabilityCalc.hpp"
#include "StringUtility.hpp"
#include "StudentInfo.hpp"
#include "VarianceCalc.hpp"




using namespace std;


const string ASK_NEW_FILE = "Enter next file path....\n";
const string NUM_CMD_ARGS_FAIL = "Not enough command line arguements...\n";






/* relative probability is the amount of times x was found after
 y amount of attempts
 
 MUST FIND FOR INDIVIDUAL NUCLEOTIDES AND PAIRS
 */

bool IsBlank(ifstream& inFile)
{
    return inFile.peek() == ifstream::traits_type::eof();
}

// stack overflow - find first not white space
//if after iterating through string and not found
// true else false
bool NotWS(const string &str)
{
    return str.find_first_not_of(' ') != std::string::npos;
}

int main(int argc, const char * argv[])
{
    StringUtility strManip;
    bool persist = true;
    string filename = argv[1];
    while(persist)
    {
        
        if (argc == 2)
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
                // two parts
                // PT 1: get sum of lengths, num of lines, and mean
                while (getline(inFile, line))
                {
                    // Assert that all values will be capitalized
                    strManip.Capitalize(line);
                    strManip.RemoveErroneousChars(line);
                    // if the line is not whitespace add to results
                    if(NotWS(line))
                    {
                        varianceCalc->addLine(line);
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
                    if(NotWS(line))
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
                    if(NotWS(line))
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
                    if(NotWS(line))
                    {
                        pc->ReadPairedOccurrences(line);
                    }
                }
                
                // print results to file
                output << *student;
                output << *varianceCalc;
                output << *pc;
                
                // delete dynamically allocated resources
                delete pc;
                delete varianceCalc;
                
                // close open files
                output.close();
                inFile.close();
                
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
            cout << "Continuing\n\n";
            cout << ASK_NEW_FILE;
            getline(cin, newFilename);
        }
        filename = newFilename;
    }
    
    cout << "Program terminated....\n\n";
    return 0;
}
