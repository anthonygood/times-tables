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

int QUESTIONS_COUNT = 3;
int MIN = 5;
int MAX = 12;

void play_game();
void ask_question(MQuestion);

MTableGame game = MTableGame(MIN, MAX, QUESTIONS_COUNT);

int main(int argc, const char * argv[]) {
    play_game();
    
    return 0;
}

void play_game()
{
    for(int i = 0; i < game.get_question_count(); i++)
    {
        
        std::cout << game.new_question().to_string();

        int  answer = game.get_answer(std::cin);
        
        bool correct_or_incorrect = game.answer_last_question(answer);

        std::cout << game.feedback(correct_or_incorrect);
    }
    
    std::cout << game.review();
    return;
}
