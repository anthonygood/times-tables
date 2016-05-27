//
//  MQuestion.cpp
//  MultiplicationTables
//
//  Created by Anthony Good on 24/05/2016.
//  Copyright © 2016 Anthony Good. All rights reserved.
//

#include "MQuestion.hpp"
#include <stdlib.h>
#include <iostream>

MQuestion::MQuestion(int min, int max)
{
    int seed = static_cast<unsigned int>(time(NULL));
    factor1 = get_rand(seed, max);
    factor2 = get_rand(seed, max);
    user_answer = 911;
    return;
}

int MQuestion::get_rand(int seed, int max) { return rand() % max + 1;  }
int MQuestion::get_user_answer() const     { return user_answer;       }
int MQuestion::product() const             { return factor1 * factor2; }

bool MQuestion::answer(int answer)
{
    user_answer = answer;
    return check(user_answer);
}

bool MQuestion::check(int answer) const { return user_answer == answer; }

std::string MQuestion::to_string() const
{
    std::string f1 = std::to_string(factor1);
    std::string f2 = std::to_string(factor2);
    return f1 + " x " + f2 + " = ";
}
