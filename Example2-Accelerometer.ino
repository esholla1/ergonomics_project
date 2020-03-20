/*
  Using the BNO080 IMU
  By: Nathan Seidle
  SparkFun Electronics
  Date: December 21st, 2017
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/14586

  This example shows how to output accelerometer values

  Hardware Connections:
  Attach the Qwiic Shield to your Arduino/Photon/ESP32 or other
  Plug the sensor onto the shield
  Serial.print it out at 9600 baud to serial monitor.
*/

#include <Wire.h> //Including library that is needed for serial communication

#include "SparkFun_BNO080_Arduino_Library.h" //Including the library so we can access all the functions in the BNO080 library
BNO080 myIMU; //Creating IMU object

void setup()
{
  Serial.begin(9600); //Enabling Serial to talk to our Arduino Mega 2560 Microcontroller
  Serial.println();
  Serial.println("BNO080 Read Example");

  Wire.begin(); // Begin the I2C Bus

  myIMU.begin();

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableAccelerometer(50); //Send data from Accelerometer and update every 50ms

  Serial.println(F("Accelerometer enabled"));
  Serial.println(F("Output in form x, y, z, in m/s^2"));
}

void loop()
{
  //Look for reports from the IMU
  if (myIMU.dataAvailable() == true)
  {
    float x = myIMU.getAccelX(); //Getting the angular velocity in the X axis
    float y = myIMU.getAccelY(); //Getting the angular velocity in the Y axis
    float z = myIMU.getAccelZ(); //Getting the angular velocity in the Z axis

    Serial.print(x, 2);
    Serial.print(F(","));
    Serial.print(y, 2);
    Serial.print(F(","));
    Serial.print(z, 2);
    Serial.print(F(","));

    Serial.println();
  }
}
