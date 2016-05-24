//
//  main.cpp
//  MultiplicationTables
//
//  Created by Anthony Good on 24/05/2016.
//  Copyright © 2016 Anthony Good. All rights reserved.
//

#include <iostream>
#include <string>
#include "MultiplicationGame.hpp"

int QUESTIONS_COUNT = 10;
int MIN = 5;
int MAX = 12;

void play_game();
void ask_question(MQuestion);
int  get_answer();
bool feedback(MQuestion, int);

MTableGame game = MTableGame(MIN, MAX, QUESTIONS_COUNT);

int main(int argc, const char * argv[]) {
    play_game();
    return 0;
}

void play_game()
{
    for(int i = 0; i < game.get_question_count(); i++)
    {
        // create question, then ask user
        MQuestion question = MQuestion(MIN, MAX);
        ask_question(question);

        int  answer  = get_answer();
        bool correct = feedback(question, answer);
    }
    return;
}

void ask_question(MQuestion question)
{
    std::cout << question.to_string();
    return;
}

int get_answer()
{
    std::string answer;
    std::getline(std::cin, answer);
    return std::stoi(answer);
}

bool feedback(MQuestion question, int answer)
{
    std::string message;
    bool correct_or_incorrect = question.answer(answer);
    if(correct_or_incorrect) { message = "Correct.\n";   }
    else                     { message = "Incorrect.\n"; }
    
    std::cout << message;
    
    return correct_or_incorrect;
    
}
