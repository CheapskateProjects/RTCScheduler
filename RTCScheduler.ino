/*
  RTCScheduler

  This project uses RTC to schedule turning on the Arduino based on alarm schedule. 

  After the Arduino has turned on it performs its given task and turns itself off to wait for the next schedule

  created   Dec 2017
  by CheapskateProjects

  ---------------------------
  The MIT License (MIT)

  Copyright (c) 2017 CheapskateProjects

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <DS3231.h>
#include <Wire.h>

DS3231 Clock;

void setup() {
	// Start the serial port
	Serial.begin(9600);

	// Start the I2C interface
	Wire.begin();

  // Alarm is not enabled! Should set alarm
  if(!Clock.checkAlarmEnabled(1))
  {
    Clock.setClockMode(false);
    // 0b1111 // each second
    // 0b1110 // Once per minute (when second matches)
    // 0b1100 // Once per hour (when minute and second matches)
    // 0b1000 // Once per day (when hour, minute and second matches)
    // 0b0000 // Once per month when date, hour, minute and second matches. Once per week if day of the week and A1Dy=true
    // Set alarm to happen every minute (change to your wanted interval)
    Clock.setA1Time(1, 1, 1, 0, 0b1110, false, false, false);
    Clock.turnOnAlarm(1);
  }

  /*
   * TODO implement logic here
   */
   // Just a delay to see that it on
   delay(10000);
  /*
   * </Logic>
   */

  // Reset alarm to turn off the device
  Clock.checkIfAlarm(1);
}

void loop()
{
  // Nothing to loop
}
