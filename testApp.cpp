//
//  testApp.cpp
//  FinalProject2
//
//  Created by 王钰 on 16/03/2023.
//

#include "testApp.hpp"

testApp::~testApp(){
    
}

void testApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(200);
    
    serial.setup(0, 115200);
    ball_0 = RandomBall();
    ball_1 = NoiseBall();
    
    phase = 0;
    ofSoundStreamSetup(2, 0);
}

void testApp::update(){
    while (serial.available() > 0) {
        distance = serial.readByte();
        cout<<distance<<endl;
        smooth_distance = ofLerp(smooth_distance,distance,0.1);
    }
    
    //int distance = int(ofMap(ofGetMouseX(),0,ofGetWidth(),0,255));
    int distance = 255 - smooth_distance;
    
    ball_0.update();
    ball_0.interact(distance);
    
    
    ball_1.update();
    ball_1.interact(distance);
    
    myFreq = distance;
}

void testApp::draw(){
    drawBackground();
    ball_0.draw();
    ball_1.draw();
}

void testApp::drawBackground(){
    ofSetColor(0,0,0,30);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

void testApp::keyPressed(int key){
    
}

void testApp::audioOut( float * output, int bufferSize, int nChannels ) {
  for(int i = 0; i < bufferSize * nChannels; i += 2) {
    float sample = sin(phase); // generating a sine wave sample
//      myClock.ticker();
//      if(myClock.tick)
//      {
//          myFreq += 1;
//      }
    output[i] = oscillator1.coswave(myFreq*0.5*oscillator2.sinewave(0.03))* 0.8; // writing to the left channel
    output[i+1] = output[i]; // writing to the right channel
    phase += 0.001 * myFreq;
  }
}
