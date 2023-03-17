#ifndef RandomBall_hpp
#define RandomBall_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Ball.hpp"

class RandomBall : public Ball
{
    
public:
    void update();
    void interact(int distance);
    
    int step = 0;
};

#endif /* RandomBall_hpp */
