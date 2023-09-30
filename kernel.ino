/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

The range readings are in units of mm. */

#include <Wire.h>
#include <VL53L0X.h>
#include <math.h>

VL53L0X sensorT;
VL53L0X sensorL;
VL53L0X sensorR;
VL53L0X sensorD;

void setup()
{
  Serial.begin(9600);
  Wire.begin();

  sensorT.setTimeout(500);
  if (!sensorT.init())
  {
    Serial.println("Failed to detect and initialize sensorT!");
    while (1) {}
  }
  sensorL.setTimeout(500);
  if (!sensorL.init())
  {
    Serial.println("Failed to detect and initialize sensorL!");
    while (1) {}
  }
  sensorR.setTimeout(500);
  if (!sensorR.init())
  {
    Serial.println("Failed to detect and initialize sensorR!");
    while (1) {}
  }
  sensorD.setTimeout(500);
  if (!sensorD.init())
  {
    Serial.println("Failed to detect and initialize sensorD!");
    while (1) {}
  }

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensorT.setAddress(0xE0);
  sensorL.setAddress(0xE1);
  sensorR.setAddress(0xE2);
  sensorD.setAddress(0xE3);
  sensorT.startContinuous();
  sensorL.startContinuous();
  sensorR.startContinuous();
  sensorD.startContinuous();
}

void loop()
{
  if (atan(abs(sensorT.readRangeContinuousMillimeters() - sensorD.readRangeContinuousMillimeters())) > 1.0)
    //alert the user
  if (atan(abs(sensorL.readRangeContinuousMillimeters() - sensorR.readRangeContinuousMillimeters())) > 1.0)
    //alert the user
}