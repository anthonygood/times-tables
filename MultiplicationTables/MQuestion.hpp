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
    bool answer(int Answer) const;
    
private:
    int factor1;
    int factor2;
    int product() const;
};
