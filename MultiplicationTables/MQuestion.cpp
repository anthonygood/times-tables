//
//  MQuestion.cpp
//  MultiplicationTables
//
//  Created by Anthony Good on 24/05/2016.
//  Copyright © 2016 Anthony Good. All rights reserved.
//

#include "MQuestion.hpp"

MQuestion::MQuestion(int min, int max)
{
    factor1 = 1;
    factor2 = 2;
    return;
}

bool MQuestion::answer(int answer) const
{
    return answer == product();
}

int MQuestion::product() const
{
    return factor1 * factor2;
}

std::string MQuestion::to_string() const
{
    std::string f1 = std::to_string(factor1);
    std::string f2 = std::to_string(factor2);
    return f1 + " x " + f2 + " = ";
}
