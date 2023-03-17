# Coding-2-Final-Project: Engine

Video: https://youtu.be/K9YVOPnNaD0
![IMAGE.png](https://github.com/Yvonne202202/Coding-2-Final-Project/blob/f9d2a6a9ef5a525490000f14a150036c350b7f4e/IMAGE.png)

## Project brief
In this project, I combined OpenFrameworks and Arduino to control the image and sound through an ultrasonic sensor. In the part of sound, I used ofxMaxim library and combined the sound and signal processing techniques learned last semester. For the visual part, I generate two balls using class inheritance.

## Class Inheritance
I first defined the parent class Ball. The parent class has properties such as the color, radius, and position of the ball.
```
  Ball::Ball(int _x, int _y, int _radius, ofColor _color){
    radius = _radius;
    pos.set(_x, _y);
    color = _color;
```
I created the subclasses RandomBall and NoiseBall. To make the ball in RandomBall have a random trajectory, I define a new attribute step in the subclass to generate its trajectory. And I gave a new property range to NoiseBall to control the sound of the ball.
```
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

```
```
  range = ofMap(distance,0,255,0.5,5);

```
## Serial Communication Part
* I used Arduino to read the data from the ultrasonic sensor and sent the data to OpenFrameworks using serial communication.
```
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  Serial.write(distance);
```
* Receives serial signal at OpenFrameworks.
```
 distance = serial.readByte();
```
*  I control the appearance of the two balls by the distance.
```
 void RandomBall::interact(int distance)
{
    step = ofMap(distance,0,255,3,20);
    radius = ofMap(distance,0,255,4,15);
}
```
```
 void NoiseBall::interact(int distance)
{
    range = ofMap(distance,0,255,0.5,1.5);
    radius = ofMap(distance,0,255,5,200);
}
```

## Sound Part
* ofxMaxim library is used.

* To make the sound more distinctive, the method sinewave() in maxiOsc is used. I made the sound like an engine through constant debugging.
```
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
```
## The challenges of development projects
In the sound part I would have liked to use ticker() to advance the clock, but after trying it I don't think it works as well as it does now.


