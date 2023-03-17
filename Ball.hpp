//
//  Ball.hpp
//  FinalProject2
//
//  Created by 王钰 on 17/03/2023.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "ofMain.h"

class Ball
{
public:
    Ball();
    Ball(int _x, int _y, int _radius, ofColor _color);
    ~Ball();
    void draw();
    void update();
    void checkEdge();
    void interact(int distance);
    
    ofVec2f pos;
    float radius;
    ofColor color;
};

#endif /* Ball_hpp */
