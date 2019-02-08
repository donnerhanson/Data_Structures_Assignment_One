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

#include "Utility.hpp"


using namespace std;


const string ASK_NEW_FILE = "Enter next file path....\n";
const string NUM_CMD_ARGS_FAIL = "Not enough command line arguements...\n";




//Pass string by reference (no copy constructed) and removes unwanted chars
string RemoveErroneousChars(string& str)
{
    string temp;
    
    for (int i(0); i < str.length(); ++i)
    {
        // if a correct letter add to temp string
        if(str.at(i) == 'A' || str.at(i) == 'C' ||
           str.at(i) == 'T' || str.at(i) == 'G')
            temp+=str.at(i);
    }
    // the referenced str now is updated program wide
    str = temp;
    return str;
}


/* relative probability is the amount of times x was found after
 y amount of attempts
 
 */


int main(int argc, const char * argv[])
{
    Utility a;
    bool persist = true;
    string filename = argv[1];
    while(persist)
    {
        
        if (argc == 2)
        {
            
            double numLines = 0;
            double sumLineLengths = 0;
            double mean = 0;
            ifstream inFile(filename, ios::in);
            string line;
            if(inFile.is_open())
            {
                // two parts
                // PT 1: get sum of lengths, num of lines, and mean
                while (getline(inFile, line))
                {
                    // Assert that all values will be capitalized
                    a.Capitalize(line);
                    cout << line << "\n";
                    RemoveErroneousChars(line);
                    // if the line is not whitespace add to results
                    if (line.length() != 0)
                    {
                        cout << line << "\n";
                        numLines++;
                        sumLineLengths += line.length();
                        cout << "length = " << line.length() << "\n";
                        cout << "Total length of all strings = " << sumLineLengths << "\n";
                    }
                }
                //PT 2 Reset and calculate Variance
                mean = sumLineLengths/numLines;
                cout << "Mean of all nucleotide string lengths " << mean << "\n";
                inFile.clear();
                inFile.seekg(0, ios::beg);
                double varianceNumeratorTotal = 0;
                double varianceLineLength = 0;
                double varianceToSquare;
                double varianceResult;
                while (getline(inFile, line))
                {
                    varianceToSquare = 0;
                    a.Capitalize(line);
                    RemoveErroneousChars(line);
                    // subtract the mean from data point
                    // i.e. length - mean
                    varianceLineLength = line.length();
                    varianceToSquare = varianceLineLength - mean;
                    // square the answer
                    varianceToSquare *= varianceToSquare;
                    varianceNumeratorTotal += varianceToSquare;
                    // then add each to variable
                    
                }
                // divide by all by mean
                varianceResult = varianceNumeratorTotal/numLines;
                // result is the variance
                cout << "Variance Result = " << varianceResult << "\n";
                
                inFile.close();
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
            //cout << "input file name " << newFilename << "\n";
        }
        filename = newFilename;
        //cout << "input file name " << filename << "\n";
    }

    cout << "Program terminated....\n\n";
    return 0;
}
