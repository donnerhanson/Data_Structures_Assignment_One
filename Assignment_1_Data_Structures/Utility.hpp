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

class Utility
{
public:
    Utility(){};
    string Capitalize(string &str);
    bool CheckForYesNo();
private:
};



#endif /* Utility_hpp */
