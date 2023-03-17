//
//  RandomBall.cpp
//  FinalProject2
//
//  Created by 王钰 on 16/03/2023.
//

#include "RandomBall.hpp"


void RandomBall::update()
{
    color = ofColor(120,ofRandom(120,255),ofRandom(155,255));
    
    // update position
    int randomNumber = int(ofRandom(0, 4));
    if(randomNumber == 0)
        pos.x += step;
    else if(randomNumber == 1)
        pos.x += step;
    else if(randomNumber == 2)
        pos.y -= step;
    else if(randomNumber == 3)
        pos.y -= step;
    checkEdge();
}

void RandomBall::interact(int distance)
{
    step = ofMap(distance,0,255,3,20);
    radius = ofMap(distance,0,255,4,15);
}
