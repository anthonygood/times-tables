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
int  get_answer();
bool feedback(bool);
void review();

void vector_log()
{
    std::vector<MQuestion> questions_and_answers;
    
    std::cout << "Begin.\n";
    
    questions_and_answers.push_back(MQuestion(1,7));
    
    std::cout << questions_and_answers.size() << std::endl;
    
    questions_and_answers.push_back(MQuestion(2,9));
    
    MQuestion rogue_question = MQuestion(4,8);
    
    questions_and_answers.push_back(rogue_question);
    
    std::cout << questions_and_answers.size() << std::endl;
    
    for(int i = 0; i < questions_and_answers.size(); i++)
    {
        std::cout << questions_and_answers[i].to_string() << std::endl;
    }
};

MTableGame game = MTableGame(MIN, MAX, QUESTIONS_COUNT);

int main(int argc, const char * argv[]) {
    play_game();
    
    return 0;
}

void play_game()
{
    for(int i = 0; i < game.get_question_count(); i++)
    {
        ask_question(game.new_question());

        int  answer = get_answer();
        
        game.answer_last_question(answer);
    }
    
    game.review(std::cout);
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
