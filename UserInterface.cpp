//================================================================
// Author      : Donner Hanson
// Date        : 02/15/2019
// Email       : hanso127@mail.chapman.edu
// Course      : Data Structures and Algorithms
// Course #    : CPSC-350-2
// Project Name: Assignment 1 DNA
// File Name   : UserInterface.cpp
// Assignment  : Assignment 1
// Version     : 1.3
// Instructor  : Rene German
// Description : Function to check if the user would like to continue
//================================================================
#include <iostream>
#include <string>

#include "StringUtility.hpp"
#include "UserInterface.hpp"


using namespace std;

bool UserInterface::CheckForYesNo()
{
    string input = " ";
    char answer;
    try // if user presses newline without input terminate program
    {
        // clear in stream
        cin.sync();
        getline(cin, input);
        helper.Capitalize(input);
        answer = input.at(0);
        while (answer != 'Y' && answer != 'N')
        {
            
            cin.sync();
            cout << ASK_CONTINUE;
            getline(cin, input);
            helper.Capitalize(input);
            answer = input.at(0);
        }
        if(input.at(0) == 'Y')
        {
            cin.sync();
            return true;
        }
        else
        {
            cin.sync();
            return false;
        }
    }
    catch(...)
    {
        cin.sync();
        return false;
    }
}
