/*
  Ultrasonic.cpp - Library for HC-SR04 Ultrasonic Ranging Module.
*/

#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class Ultrasonic
{
  public:
    Ultrasonic(const int trig_pin, const int echo_pin);
    const unsigned long measure_duration();
    const float microseconds_to_cm();
    
    static int TTL;

  private:
    static const float MICROSECONDS_PER_CM = 29.155;
    static const float MOUNTING_GAP = 0.2;
    int _trig_pin;
    int _echo_pin;
    long _duration;
};

#endif
