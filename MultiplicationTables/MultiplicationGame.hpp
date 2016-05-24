//
//  MultiplicationGame.hpp
//  MultiplicationTables
//
//  Created by Anthony Good on 24/05/2016.
//  Copyright © 2016 Anthony Good. All rights reserved.
//

#ifndef MultiplicationGame_hpp
#define MultiplicationGame_hpp

#include <stdio.h>
#include "MQuestion.hpp"

#endif /* MultiplicationGame_hpp */

struct QuestionAndAnswer
{
    MQuestion question;
    int answer;
    bool correct;
};

class MTableGame
{

public:
    MTableGame(int min, int max, int question_count);
    MQuestion get_question() const;
    int get_question_count() const;
    
private:
    int min;
    int max;
    int question_count;
    QuestionAndAnswer questions_and_answers[];
    
};
