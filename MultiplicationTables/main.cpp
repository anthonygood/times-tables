//
//  main.cpp
//  MultiplicationTables
//
//  Created by Anthony Good on 24/05/2016.
//  Copyright © 2016 Anthony Good. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include "MultiplicationGame.hpp"

int QUESTIONS_COUNT = 5;
int MIN = 5;
int MAX = 12;

void test();

MTableGame game = MTableGame(MIN, MAX, QUESTIONS_COUNT);

int main(int argc, const char * argv[]) {
    test();
    
    return 0;
}

void test()
{
    for(int i = 0; i < game.get_question_count(); i++)
    {
        
        std::cout << game.new_question().to_string();

        int  answer = game.get_answer(std::cin);
        
        bool correct_or_incorrect = game.answer_last_question(answer);

        std::cout << game.feedback(correct_or_incorrect) << std::endl;
    }
    
    std::cout << game.review();
    return;
}
