//
//  NucleoProb.cpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/8/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#include "NucleoProb.hpp"
bool operator < (const nucleoProb &lhs, const nucleoProb &rhs)
{
    return lhs.prob < rhs.prob;
}
