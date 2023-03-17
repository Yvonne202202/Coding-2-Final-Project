//
//  Ball.cpp
//  FinalProject2
//
//  Created by 王钰 on 16/03/2023.
//

#include "Ball.hpp"
#include "ofMain.h"
Ball::Ball(){
    radius = ofRandom(5,10);
    pos.set(3*ofGetWidth()/4, 4*ofGetHeight()/7);
}

Ball::Ball(int _x, int _y, int _radius, ofColor _color){
    radius = _radius;
    pos.set(_x, _y);
    color = _color;
}

Ball::~Ball(){
    
}

void Ball::update(){
    checkEdge();
}

void Ball::draw(){
    ofSetColor(color);
    ofDrawCircle(pos, radius);
}

void Ball::checkEdge(){
    if(pos.x < 0){
        pos.x = ofGetWidth();
    }else if(pos.x > ofGetWidth()){
        pos.x = 0;
    }
    if(pos.y < 0){
        pos.y = ofGetHeight();
    }else if(pos.y > ofGetHeight()){
        pos.y = 0;
    }
}

void Ball::interact(int distance){
    
}
