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
#include <vector>

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
    MQuestion new_question();
    int get_question_count() const;
    bool answer_last_question(int answer);
    void review(std::ostream& output);
    bool feedback(std::ostream& output, bool correct_or_incorrect);
    int get_answer(std::istream& input);
//    std::vector<MQuestion> get_questions_and_answers();
    
private:
    int min;
    int max;
    int question_count;
    std::vector<MQuestion> questions_and_answers;
    bool answer_question_at(int index, int answer);
    
};
