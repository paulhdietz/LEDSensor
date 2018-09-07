// ReadLight - Shows the current current light level detected
// by an LED - to see the result, use Serial Monitor
// or Serial Plotter at 250000 baud
//
// Testing the LEDSensor library

#include <LEDSensor.h>

// Connections:
//
// LED cathode to pin 3
// LED anode to pin 4


LEDLightSensor LED43(4, 3);

void setup()
{
  Serial.begin(250000);
}

void loop()
{
  Serial.println(LED43.read());
}


