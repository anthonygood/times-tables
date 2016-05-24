//
//  MultiplicationGame.cpp
//  MultiplicationTables
//
//  Created by Anthony Good on 24/05/2016.
//  Copyright © 2016 Anthony Good. All rights reserved.
//

#include "MultiplicationGame.hpp"


MTableGame::MTableGame(int lower, int upper, int count)
{
    min = lower;
    max = upper;
    question_count = count;

    return;
}

int MTableGame::get_question_count() const { return question_count; }
