# Library for module HC-SR04, an ultrasonic sonar distance sensor

Functions
* Define the trig and echo pins by calling the constructor
* Read the current distance in centimeters

This small library was created to have an optimized version related to:
1) Reliability: Some libraries use function 'micros()' which is the root cause of issues resulting in wrong readings
   Note: Two reads of micros() in the same routine sometimes results in a lower value of the second read, this is theoretically impossible
2) No unneccessary calculations or functions. Like x/factor/2. The .h file shows the math how the distance is calculated
   Two divisions is costly, also /2 is time consuming related to x>>1, which yields the same result. Better: use a single factor

