/*
  Ultrasonic.cpp - Library for HC-SR04 Ultrasonic Ranging Module.
*/

#include "ultrasonic.h"

int Ultrasonic::TTL = 10;

Ultrasonic::Ultrasonic(const int trig_pin, const int echo_pin)
{
    _trig_pin = trig_pin;
    _echo_pin = echo_pin;
    pinMode(_trig_pin, OUTPUT);
    pinMode(_echo_pin, INPUT);
}

const unsigned long Ultrasonic::measure_duration()
{
    digitalWrite(_trig_pin, LOW);
    delayMicroseconds(2);
    
    digitalWrite(_trig_pin, HIGH);
    delayMicroseconds(TTL);
    digitalWrite(_trig_pin, LOW);
    
    _duration = pulseIn(_echo_pin, HIGH);
    return _duration;
}

const float Ultrasonic::microseconds_to_cm()
{
    long sensor_offset = MOUNTING_GAP * MICROSECONDS_PER_CM * 2;
    const float net_distance = max(0, _duration - sensor_offset);
    return min(400, net_distance / MICROSECONDS_PER_CM / 2);
}




