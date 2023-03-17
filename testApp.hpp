#ifndef testApp_hpp
#define testApp_hpp

#include <stdio.h>

#include "ofMain.h"
#include "Ball.hpp"
#include "RandomBall.hpp"
#include "NoiseBall.hpp"
#include "ofxMaxim.h"
class testApp : public ofBaseApp{
    
public:
    ~testApp();
    
    void setup();
    void drawBackground();
    void update();
    void draw();
    void audioOut( float * output, int bufferSize, int nChannels );

    void keyPressed(int key);

    ofSerial serial;
    int distance = 0;
    int smooth_distance = 0;

    RandomBall ball_0;
    NoiseBall ball_1;
    
    double phase;
    int myFreq;
    maxiOsc oscillator1;
    maxiOsc oscillator2;
    maxiClock myClock;
};

#endif
