//
//  UserInterface.cpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//
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
