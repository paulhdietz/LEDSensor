/*
 
LEDSensor.h - This library provides functions to use an LED as a light
sensor, a temperature sensor, or as a wind sensor.

Copyright 2018, Paul H. Dietz

This library is free software; you can redistribute it and/or
modify it under the terms of the MIT License included in this
distribution as LICENSE.txt

*/

#ifndef LEDSensorLib
#define LEDSensorLib

#if (ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif



class LEDLightSensor {
  public:
    // Constructor
    LEDLightSensor(byte anode = 4, byte cathode = 3);

    // Methods
    unsigned long read();
    bool test(unsigned int time = 6);
    void on();

  private:
    byte _anode;
    byte _cathode;
};

class LEDTempSensor {
  public:
    // Constructor
    LEDTempSensor(byte measure = A0, byte power = A1);

    // Methods
    unsigned long read();
    void waitBlow(unsigned int minjump=150, byte numsamples=10);
    void on();
    void off();

  private:
    byte _measure;
    byte _power;
};


#endif
