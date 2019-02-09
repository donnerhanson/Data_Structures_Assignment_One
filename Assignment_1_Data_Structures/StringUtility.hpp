//
//  Utility.hpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#ifndef Utility_hpp
#define Utility_hpp

#include <stdio.h>
#include <string>

using namespace std;

const string ASK_CONTINUE = "Would you like to continue?...(Y/N)\n";

class StringUtility
{
    friend ostream& operator << (ostream& out, const StringUtility &su);
public:
    StringUtility() : linesOmitted(0){};
    string Capitalize(string &str);
    bool CheckForYesNo();
    bool isEvenStrLen(const string& str);
    string RemoveErroneousChars(string& str);
    
    void operator++()
    {
        linesOmitted+=1;
    }
private:
    int linesOmitted;
};
ostream& operator << (ostream& out, const StringUtility &su);



#endif /* Utility_hpp */
