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
    time_t time_taken() const;
    
private:
    int factor1;
    int factor2;
    time_t created_at;
    time_t answered_at;
    int get_rand(int max);
    int user_answer;
};
