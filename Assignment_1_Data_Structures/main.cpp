//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : main.cpp
// Assignment  : Assignment 1
// Version     : 1
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

#include "Calculator.hpp"
#include "StringUtility.hpp"


using namespace std;


const string ASK_NEW_FILE = "Enter next file path....\n";
const string NUM_CMD_ARGS_FAIL = "Not enough command line arguements...\n";






/* relative probability is the amount of times x was found after
 y amount of attempts
 
 */


int main(int argc, const char * argv[])
{
    StringUtility a;
    bool persist = true;
    string filename = argv[1];
    while(persist)
    {
        
        if (argc == 2)
        {
            ifstream inFile(filename, ios::in);
            string line;
            if(inFile.is_open())
            {
                Calculator* calc  = new Calculator();
                // two parts
                // PT 1: get sum of lengths, num of lines, and mean
                while (getline(inFile, line))
                {
                    // Assert that all values will be capitalized
                    a.Capitalize(line);
                    a.RemoveErroneousChars(line);
                    // if the line is not whitespace add to results
                    if (line.length() != 0)
                    {
                        calc->addLine(line);
                    }
                }
                //PT 2 Reset and calculate Variance
                calc->setMean();
                cout << "Mean of all nucleotide string lengths in calc: " << calc->getMean() << "\n";
                inFile.clear();
                inFile.seekg(0, ios::beg);
                while (getline(inFile, line))
                {
                    a.Capitalize(line);
                    a.RemoveErroneousChars(line);
                    calc->CalculateVarianceNumerator(line);
                    
                }
                calc->CalculateVarianceResult();
                cout << "CLASS: Variance Result = " << calc->getVarianceResult() << "\n";
                
                inFile.close();
                delete calc;
            }
            else
            {
                cout << "File not opened!\n";
            }
            
            ofstream output("DonnerHanson.txt", ios::out);
            if (output.is_open())
            {
                output << "Success!\n";
            }
            output.close();
        }
        else
        {
            cout << NUM_CMD_ARGS_FAIL;
        }
        
        cout << ASK_CONTINUE;
        persist = a.CheckForYesNo();
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
