//
//  StudentInfo.cpp
//  Assignment_1_Data_Structures
//
//  Created by Donner Hanson on 2/8/19.
//  Copyright © 2019 Donner Hanson. All rights reserved.
//


#include "StudentInfo.hpp"

ostream& operator << (ostream& out, const StudentInfo &si)
{
    out << "Name: " << si.name << "  " << "ID: " << si.studentID << "\n";
    return out;
}
