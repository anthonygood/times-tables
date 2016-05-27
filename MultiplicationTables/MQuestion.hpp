//
//  MQuestion.hpp
//  MultiplicationTables
//
//  Created by Anthony Good on 24/05/2016.
//  Copyright © 2016 Anthony Good. All rights reserved.
//

#ifndef MQuestion_hpp
#define MQuestion_hpp

#include <stdio.h>
#include <string>
#include <sys/time.h>

#endif /* MQuestion_hpp */

class MQuestion
{
public:
    MQuestion(int min, int max);
    std::string to_string() const;
    bool answer(int answer);
    bool check(int answer) const;
    int product() const;
    int get_user_answer() const;
    float time_taken_f() const;
    
private:
    int factor1;
    int factor2;
    int user_answer;
    timeval created_at;
    timeval answered_at;
    int get_rand(int max);
    timeval make_timestamp() const;
    int time_taken_msec() const;
};
