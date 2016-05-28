//
//  MultiplicationGame.cpp
//  MultiplicationTables
//
//  Created by Anthony Good on 24/05/2016.
//  Copyright © 2016 Anthony Good. All rights reserved.
//

#include "MultiplicationGame.hpp"
#include <sstream>
#include <iostream>


MTableGame::MTableGame(int lower, int upper, int count)
{
    min = lower;
    max = upper;
    question_count = count;
    std::vector<MQuestion> questions_and_answers;
    initialize_seed();

    return;
}

int MTableGame::get_question_count() const { return question_count; }

MQuestion MTableGame::new_question()
{
    MQuestion question = MQuestion(min, max);
    questions_and_answers.push_back(question);
    return question;
}

int MTableGame::get_answer(std::istream& input)
{
    std::string answer;
    std::getline(input, answer);
    if(answer.size()) { return std::stoi(answer); } // return if empty
                                                    // TODO protect against non-integer input
    else { return 0; }
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

std::string MTableGame::review()
{
    std::ostringstream output;

    output << "\n==========\n  Review\n==========\n";

    for(int i = 0; i < questions_and_answers.size(); i++)
    {
        MQuestion q = questions_and_answers.at(i);
        int user_answer = q.get_user_answer();

        output << q.to_string() << user_answer << " ";
        output << feedback(q.check(user_answer));

        output << " (" << q.time_taken_f() << "s)\n";
    }
    
    return output.str();
}

std::string MTableGame::feedback(bool correct_or_incorrect)
{
    std::string message;
    
    if(correct_or_incorrect) { message = "\u2713";  } // cross
    else                     { message = "\u274C";  } // tick
    
    return message;
    
}

void MTableGame::initialize_seed()
{
    int seed = static_cast<unsigned int>(time(NULL));
    srand(seed);
}

