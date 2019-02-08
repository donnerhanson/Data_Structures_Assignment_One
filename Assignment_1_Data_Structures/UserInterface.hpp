//
//  UserInterface.hpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/7/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#ifndef UserInterface_hpp
#define UserInterface_hpp

#include <stdio.h>
#include <string>
#include "StringUtility.hpp"

class UserInterface{
public:
bool CheckForYesNo();
private:
    StringUtility helper;
};
#endif /* UserInterface_hpp */
