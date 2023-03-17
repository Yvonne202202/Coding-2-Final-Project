//
//  NoiseBall.cpp
//  FinalProject2
//
//  Created by 王钰 on 16/03/2023.
//
#include "NoiseBall.hpp"
void NoiseBall::update()
{
    color = ofColor(100,100,255);
    
    // update position
    float time = ofGetElapsedTimef();
//    pos.x = range * ofGetWidth() * ofNoise(time*0.3);
//    pos.y = range * ofGetHeight() * ofNoise(time*0.6);
    
    checkEdge();
}

void NoiseBall::interact(int distance)
{
    range = ofMap(distance,0,255,0.5,1.5);
    radius = ofMap(distance,0,255,5,200);
}

