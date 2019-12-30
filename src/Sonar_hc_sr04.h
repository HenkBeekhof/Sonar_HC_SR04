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

#ifndef Sonar_hc_sr04_h
#define Sonar_hc_sr04_h

// Distance x = t[s] * 340[m/s] / 2 = t[s] * 170 [m/s]  
// when t in us: x = 170/1000000 * t [m]  = 170/10000 * t [cm] = t / 59 [cm]
#define CM_FACTOR 59

class Sonar_hc_sr04 {
  public:
    Sonar_hc_sr04(byte trigPin, byte echoPin);
    unsigned int Read(byte factor = CM_FACTOR);

  private:
    byte trig;
    byte echo;
    
    unsigned long Timing();
};

#endif
