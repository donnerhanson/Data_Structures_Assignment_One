//
//  NucleoProb.hpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/8/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//

#ifndef NucleoProb_hpp
#define NucleoProb_hpp

#include <stdio.h>
class nucleoProb{
public:
    nucleoProb(double prob,char nucleo) : prob(prob), nucleo(nucleo){}
    void setValues(double num,char letter)
    {
        prob = num;
        nucleo = letter;
    }
    double getProb()const{return prob;}
    char getNucleo()const{return nucleo;}
    friend bool operator < (const nucleoProb &lhs, const nucleoProb &rhs);
private:
    double prob;
    char nucleo;
};
bool operator < (const nucleoProb &lhs, const nucleoProb &rhs);

#endif /* NucleoProb_hpp */
