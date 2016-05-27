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
    factor1 = get_rand(max);
    factor2 = get_rand(max);
    user_answer = 911;
    return;
}

int MQuestion::get_rand(int max) { return rand() % max + 1;  }
int MQuestion::get_user_answer() const     { return user_answer;       }
int MQuestion::product() const             { return factor1 * factor2; }

bool MQuestion::answer(int answer)
{
    user_answer = answer;
    return check(user_answer);
}

bool MQuestion::check(int answer) const { return product() == answer; }

std::string MQuestion::to_string() const
{
    std::string f1 = std::to_string(factor1);
    std::string f2 = std::to_string(factor2);
    return f1 + " x " + f2 + " = ";
}
