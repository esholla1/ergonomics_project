

#include <Wire.h>

#include "SparkFun_BNO080_Arduino_Library.h"
BNO080 myIMU;

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("BNO080 Read Example");

  Wire.begin();

  if (myIMU.begin() == false)
  {
    Serial.println("BNO080 not detected at default I2C address. Check your jumpers and the hookup guide. Freezing...");
    while (1);
  }

  Wire.setClock(400000); //Increase I2C data rate to 400kHz

  myIMU.enableRotationVector(50); //Send data update every 50ms

  Serial.println(F("Rotation vector enabled"));
  Serial.println(F("Output in form i, j, k, real, accuracy"));
}

void loop()
{
  //Look for reports from the IMU
  if (myIMU.dataAvailable() == true)
  {
    float quatI = myIMU.getQuatI();
    float quatJ = myIMU.getQuatJ();
    float quatK = myIMU.getQuatK();
    float quatReal = myIMU.getQuatReal();
    float quatRadianAccuracy = myIMU.getQuatRadianAccuracy();

    Serial.print(quatI, 2); //Retrieves the i-axis quaternion from the IMU.
    Serial.print(F(","));
    Serial.print(quatJ, 2); //Retrieves the j-axis quaternion from the IMU.
    Serial.print(F(","));
    Serial.print(quatK, 2); //Retrieves the k-axis quaternion from the IMU.
    Serial.print(F(","));
    Serial.print(quatReal, 2); //Retrieves the real component of the quaternion from the IMU.
    Serial.print(F(","));
    Serial.print(quatRadianAccuracy, 2); //Retrieves the accuracy of the quaternion from the IMU.
    Serial.print(F(","));

    Serial.println();
  }
}
