# Coding-2-Final-Project: Engine

Video: https://youtu.be/K9YVOPnNaD0
![IMAGE.png](https://github.com/Yvonne202202/Coding-2-Final-Project/blob/f9d2a6a9ef5a525490000f14a150036c350b7f4e/IMAGE.png)

## Project brief
In this project, I combined OpenFrameworks and Arduino to control the image and sound through an ultrasonic sensor. In the part of sound, I used ofxMaxim library and combined the sound and signal processing techniques learned last semester. For the visual part, I generate two balls using class inheritance.

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
* The maxiClock system is also used. Run a test with a conditional statement to see if there is a clock tick. Call ticker() inside the play() function to advance the clock.
The song() function is created and the conditional statement and modulus % are used in it to produce a more interesting rhythm.
```
     function song()
     {
        var out = 0;
        myClock.ticker();
        if( myClock.tick && myClock.playHead%beatPlay===0)
        {
           loop.trigger();
        }
    
        if(myClock.tick && parseInt(loopPlay/64)===1){
      
           beat.trigger();
        }
        if(myClock.tick && myClock.playHead%chordPlay===4){
      
           chord.trigger();
        }
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
*  Sets up a maxiClock object called 'myClock'.The clock speed is set to 120 by using setTempo(). And the number of beats is set to 4 by setTicksPerBeat().
```
  myClock.setTempo(120);
  myClock.setTicksPerBeat(4);
```
* The maxiClock system is also used. Run a test with a conditional statement to see if there is a clock tick. Call ticker() inside the play() function to advance the clock.
The song() function is created and the conditional statement and modulus % are used in it to produce a more interesting rhythm.
```
     function song()
     {
        var out = 0;
        myClock.ticker();
        if( myClock.tick && myClock.playHead%beatPlay===0)
        {
           loop.trigger();
        }
    
        if(myClock.tick && parseInt(loopPlay/64)===1){
      
           beat.trigger();
        }
        if(myClock.tick && myClock.playHead%chordPlay===4){
      
           chord.trigger();
        }
      }
 ```

## 3D Graphics
Basic perspective projection is used. 
* The 3D model is a sphere of points with a ring number of 80.
* The x, y, and z coordinates are used to create the basic 3D graphics. 
```
   var dim = 80; // This is the number of rings
   // Each ring has as many points as there are rings8
   // This is the spacing for each ring
   var spacing = ((Math.PI * 5.5) / dim);
   //var spacing = 200
   //var spacing = Math.sin(dim)
   // This is the total number of points
   var numPoints = dim * dim;

   // This is how big the sphere is.
   var size = 500;
```
* CanvasRenderingContext2D.CreateRadialGradient() is used, and through in which access to the mouse parameters for interaction of graphics and the gradient effect.
```
      // Draw the point

      // Set the size based on scaling
        context.lineWidth = scale;
        var grd=context.createRadialGradient(mouseX,mouseY,80,mouseX,mouseY,300);
        grd.addColorStop(0,"#FF3399");
        grd.addColorStop(1,"#33FFFF");
        context.strokeStyle = grd
        context.fillStyle = grd
       // context.strokeStyle = "rgb(0,255,255)";
        context.beginPath();
        context.moveTo(x2d, y2d);
        context.lineTo(x2d + scale, y2d);
      
        context.stroke();

```
## The challenges of development projects
* The sound is sometimes distorted, which makes the mix often sound bad.
* Different browsers load different pages due to browser compatibility issues. My project was made in Safari, and the audio that had been uploaded could not load properly when I opened the link in Google Chrome.
* The sphere of points is so thin that it doesn't look obvious.

## Future plan
I would like to create sphere of points that move to follow the rhythm of the sound. Like changing shape to follow the beat.
