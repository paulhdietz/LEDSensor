/*

LEDSensor.cpp - This library provides functions to use an LED as a light
sensor, a temperature sensor, or as a wind sensor.

Copyright 2018, Paul H. Dietz

This library is free software; you can redistribute it and/or
modify it under the terms of the MIT License included in this
distribution as LICENSE.txt

 */

#include "LEDSensor.h"


// LEDLightSensor class
//
// For measuring light with an LED

LEDLightSensor::LEDLightSensor(byte anode, byte cathode) {
  _anode = anode;
  _cathode = cathode;
}

// Public methods

// read - reads the discharge time to threshold on the LED
unsigned long LEDLightSensor::read() {
  unsigned long time;

  pinMode(_cathode, OUTPUT);    // Set cathode pin to output
  pinMode(_anode, OUTPUT);      // Set anode pin to output

  digitalWrite(_anode, LOW);    // Reverse bias the LED
  digitalWrite(_cathode, HIGH);

  delayMicroseconds(10);        // delay to charge capacitance

  time = micros();              // Grab the current time

  pinMode(_anode, INPUT);       // Let go of LED and allow it to discharge

  while (!digitalRead(_anode)); // wait for PLUS to go HIGH

  time = micros() - time;       // How long has it been?

  return time;

}

// test - test LED photo discharge after specified time
bool LEDLightSensor::test(unsigned int time) {

  pinMode(_cathode, OUTPUT);    // Set cathode pin to output
  pinMode(_anode, OUTPUT);      // Set anode pin to output

  digitalWrite(_anode, LOW);    // Reverse bias the LED
  digitalWrite(_cathode, HIGH);

  delayMicroseconds(10);       // delay to charge capacitance

  pinMode(_anode, INPUT);       // Let go of LED and allow it to discharge

  delay(time);                  // wait specified time for discharge

  return digitalRead(_anode);

}

// on - light the LED
void LEDLightSensor::on() {
  pinMode(_cathode, OUTPUT);    // Set cathode pin to output
  pinMode(_anode, OUTPUT);      // Set anode pin to output
  digitalWrite(_anode, HIGH);   // Reverse bias the LED
  digitalWrite(_cathode, LOW);
}



// LEDTempSensor class
//
// for measuring temperature and wind speed with an LED

LEDTempSensor::LEDTempSensor(byte measure, byte power) {
  _measure = measure;
  _power = power;
}

// Public methods

// read - reads forward voltage on the LED
unsigned long LEDTempSensor::read() {
  int cnt;
  unsigned long sum = 0;

  // Sum 256 adc readings (to reduce adc noise)
  for (cnt = 0; cnt < 256; cnt++) {
    sum = sum + analogRead(_measure);
  }

  return sum;
}

// on - turn on the LED
void LEDTempSensor::on() {
  pinMode(_power, OUTPUT);      // set power pin to output
  digitalWrite(_power, HIGH);   // turn on the LED
}

// off - turn off the LED
void LEDTempSensor::off() {
  pinMode(_power, OUTPUT);      // set power pin to output
  digitalWrite(_power, LOW);   // turn on the LED
}

// waitBlow - waits until LED detects blow...
void LEDTempSensor::waitBlow(unsigned int minjump, byte numsamples) {
  unsigned long sum;
  unsigned long sensedata[numsamples];
  int dataptr = 0;
  bool buffull = 0;

  on();                       // make sure the LED is on

  sum = read();
  
  // Compare current measurement to oldest if buffer full
  while (!buffull || (sum < (sensedata[dataptr] + minjump))) {
    // Buffer not yet full or no jump
    sensedata[dataptr] = sum;               // Store the latest data in the buffer
    dataptr++;                              // Update buffer pointer
    if (dataptr == numsamples) {            // Check if dataptr went past end
      dataptr = 0;                          // Reset the dataptr to beginning
      buffull = 1;                          // Mark that buffer is full
    }
    sum = read();
  }
}





