//
//  Utility.cpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#include "StringUtility.hpp"
#include <algorithm>
#include <iostream>


string StringUtility::Capitalize(string &str)
{
    // use algorithm to uppercase all input
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

bool StringUtility::CheckForYesNo()
{
    string input = " ";
    char answer;
    try // if user presses newline without input terminate program
    {
        // clear in stream
        cin.sync();
        getline(cin, input);
        Capitalize(input);
        answer = input.at(0);
        while (answer != 'Y' && answer != 'N')
        {
            
            cin.sync();
            cout << ASK_CONTINUE;
            getline(cin, input);
            Capitalize(input);
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

//Pass string by reference (no copy constructed) and removes unwanted chars
string StringUtility::RemoveErroneousChars(string& str)
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

