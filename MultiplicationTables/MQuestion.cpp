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
    user_answer = -1;
    created_at = make_timestamp();
    return;
}

int MQuestion::get_rand(int max)           { return rand() % max + 1;    }
int MQuestion::get_user_answer()  const    { return user_answer;         }
int MQuestion::product()          const    { return factor1 * factor2;   }
bool MQuestion::check(int answer) const    { return product() == answer; }

bool MQuestion::answer(int answer)
{
    user_answer = answer;
    answered_at = make_timestamp();
    return check(user_answer);
}

std::string MQuestion::to_string() const
{
    std::string f1 = std::to_string(factor1);
    std::string f2 = std::to_string(factor2);
    return f1 + " x " + f2 + " = ";
}

float MQuestion::time_taken_f() const
{
    int   msec = time_taken_msec();
    float secs = float(msec) / 1000;

    return secs;
}

int MQuestion::time_taken_msec() const
{
    int sec_diff = static_cast<unsigned int>(answered_at.tv_sec - created_at.tv_sec);
    int sec_diff_in_msec = sec_diff * 1000;

    int usec_diff_in_msec = (answered_at.tv_usec - created_at.tv_usec) / 1000;
    
    return sec_diff_in_msec + usec_diff_in_msec; // milliseconds
}

timeval MQuestion::make_timestamp() const
{
    timeval tv;
    gettimeofday(&tv, 0);
    return tv;
}
