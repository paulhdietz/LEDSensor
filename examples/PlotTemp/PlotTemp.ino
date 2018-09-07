// PlotTemp - Shows the current temp of an LED by reporting
// the forward voltage drop - to see the result, use Serial Monitor
// or Serial Plotter at 250000 baud
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
  Serial.begin(250000);
}

void loop()
{
  LED.on();
  Serial.println(LED.read());
}


