/*
  Sonar_hc_sr04 - library for Arduino
  Copyright (c) 2019 Henk Beekhof.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "Sonar_hc_sr04.h"

// Constructor: Define the trig and echo pin location and set the direction
Sonar_hc_sr04::Sonar_hc_sr04(byte trigPin, byte echoPin) {
  trig = trigPin;
  echo = echoPin;
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

// Send a 10us pulse on the trig pin and measure the echo pin by using function 'pulseIn'
// Note: Using function 'micros()' does not work due to wrong behaviour of 'micros()' which is the root
// cause why some libraries give sometimes wrong readings as a result.
unsigned long Sonar_hc_sr04::Timing() {
  unsigned long duration;

  // Send a 10us pulse on the Trig pin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Measure the duration of the high pulse on the Echo pin in microseconds
  duration = pulseIn(echo, HIGH);
  
  return duration;
}

// Read the distance, result is the distance in centimeters
unsigned int Sonar_hc_sr04::Read(byte factor) {
  return (Timing() / factor);
}
