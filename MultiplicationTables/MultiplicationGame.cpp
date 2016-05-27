//
//  MultiplicationGame.cpp
//  MultiplicationTables
//
//  Created by Anthony Good on 24/05/2016.
//  Copyright © 2016 Anthony Good. All rights reserved.
//

#include "MultiplicationGame.hpp"
#include <sstream>


MTableGame::MTableGame(int lower, int upper, int count)
{
    min = lower;
    max = upper;
    question_count = count;
    std::vector<MQuestion> questions_and_answers;

    return;
}

int MTableGame::get_question_count() const { return question_count; }
//std::vector<MQuestion> MTableGame::get_questions_and_answers() { return questions_and_answers; }

MQuestion MTableGame::new_question()
{
    MQuestion question = MQuestion(min, max);
    questions_and_answers.push_back(question);
    return question;
}

bool MTableGame::answer_last_question(int answer)
{
    int last_index = static_cast<unsigned int>(questions_and_answers.size()) - 1;
    bool correct_or_incorrect = answer_question_at(last_index, answer);
    return correct_or_incorrect;
}

bool MTableGame::answer_question_at(int index, int answer)
{
    return questions_and_answers.at(index).answer(answer);
}

void MTableGame::review(std::ostream& output)
{
    for(int i = 0; i < questions_and_answers.size(); i++)
    {
        MQuestion q = questions_and_answers.at(i);
        output << q.to_string() << q.get_user_answer() << " ";
        feedback(output, q.get_user_answer());
    }
}

bool MTableGame::feedback(std::ostream& output, bool correct_or_incorrect)
{
    std::string message;
    
    if(correct_or_incorrect) { message = "Correct.\n";   }
    else                     { message = "Incorrect.\n"; }
    
    output << message;
    
    return correct_or_incorrect;
    
}

