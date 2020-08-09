#include "EmonLib.h"
// Include Emon Library
EnergyMonitor emon1;
// Create an instance
void setup()
{
  Serial.begin(9600);

  //emon1.current(0, 111.1);             // Current: input pin, calibration.
  emon1.current(0, 153);             // Current: input pin, calibration.
}

void loop()
{
  double Irms = emon1.calcIrms(1676);  // Calculate Irms only
  Serial.print(Irms*120);           // Apparent power
  Serial.print(" ");
  Serial.println(Irms);             // Irms
}



/*
 * 
 * 
 * 
 * 

notes on calibration: 111.1 is "the mains volt required to drive the secondary voltage to 1v DC"
https://community.openenergymonitor.org/t/calibration-and-parameters-in-emonlib/6855

the calcIrms magic number of 1676 comes from here: https://community.openenergymonitor.org/t/sampling-rate-of-emonlib/4383

The 100A sensor I'm using is SCT013 100A:50ma which is a 2000:1 ratio CT.
https://learn.openenergymonitor.org/electricity-monitoring/ct-sensors/yhdc-sct-013-000-ct-sensor-report

my burden is 33 ohm, a kludge of 3 22-ohm resistors, in series, two in parallel

secondary current = primary current (11.2A) / ratio (2000) = 0.0056
input pin voltage = secondary current (0.0056) * 33 = 369.6

...
current constant = 100 / .05 = 2000



11,2 I'm seeing 8


 */
