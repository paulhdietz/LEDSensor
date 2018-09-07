// NightLight - Automatic night light uses one LED
// to sense when it is dark and turns on that LED
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
}

void loop()
{
    // Test the LED to see if it is discharged after 6ms
    // Note: testing turns off the LED
    if(!LED43.test(6)) {
      // Turn on the LED if dark
      LED43.on();
    }
    delay(10);
}


