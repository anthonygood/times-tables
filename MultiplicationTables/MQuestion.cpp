//
//  MQuestion.cpp
//  MultiplicationTables
//
//  Created by Anthony Good on 24/05/2016.
//  Copyright © 2016 Anthony Good. All rights reserved.
//

#include "MQuestion.hpp"
#include <stdlib.h>

MQuestion::MQuestion(int min, int max)
{
    int seed = time(NULL);
    factor1 = get_rand(seed, max);
    factor2 = get_rand(seed, max);
    return;
}

int MQuestion::get_rand(int seed, int max)
{
    return rand() % max + 1;
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
