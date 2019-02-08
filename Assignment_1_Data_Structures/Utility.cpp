//
//  Utility.cpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#include "Utility.hpp"
#include <algorithm>
#include <iostream>


string Utility::Capitalize(string &str)
{
    // use algorithm to uppercase all input
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

bool Utility::CheckForYesNo()
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
