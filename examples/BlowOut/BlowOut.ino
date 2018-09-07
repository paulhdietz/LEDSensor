// BlowOut - blow on an LED to turn it off for 2 seconds
//
// LEDSensor library example

#include <LEDSensor.h>

// Connections:
//
// LED cathode to GND
// LED anode to A0 (the measurement pin)
// Resistor connects from A0 to A1 (the LED power pin)

LEDTempSensor LED(A0, A1);

void setup()
{
}

void loop()
{
  LED.waitBlow();   // Turns on LED and waits for blow
  LED.off();        // Turn off the LED
  delay(2000);
}


