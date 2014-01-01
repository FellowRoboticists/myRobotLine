// -*- c -*-
// myRobotLine Arduino sketch
//
// Copyright (c) 2012 Michael Margolis
// Copyright (c) 2013 Dave Sieh
//
// See LICENSE.txt for details.

#include <LEDBlinker.h>
#include <SoftServo.h>
#include <RobotMotor.h>

// Analog Pins
#define LEFT_IR_SENSOR_PIN 0
#define RIGHT_IR_SENSOR_PIN 1
#define CENTER_IR_SENSOR_PIN 2

// Digital Pins
#define SWEEP_SERVO_PIN 9
#define LED_PIN 13

LEDBlinker blinker(LED_PIN);
SoftServo sweepServo(SWEEP_SERVO_PIN);

int speed = MIN_SPEED;

void setup() {
  Serial.begin(9600);
  blinker.begin();
  blinker.blinkNumber(8); // For Leonardo
  sweepServo.begin();

  lineSenseBegin();

  Serial.println("Ready");
}

void loop() {
  int drift = lineSense();
  lineFollow(drift, speed);
}

/***********************************************************
 Line Sensor code
***********************************************************/
int damping = 5; // 1 is most sensitive, range 1 to 1023

void lineSenseBegin() {
  // Nothing yet
}

// returns drift - 0 if over line, minus value if left, plus if right
int lineSense() {
  int leftVal = analogRead(LEFT_IR_SENSOR_PIN);
  int centerVal = analogRead(CENTER_IR_SENSOR_PIN);
  int rightVal = analogRead(RIGHT_IR_SENSOR_PIN);
  
  int leftSense = centerVal - leftVal;
  int rightSense = rightVal - centerVal;
  
  int drift = rightSense - leftSense; // rightVal - leftVal;
  
  Serial.print("L,C,R=");
  Serial.print(leftVal);
  Serial.print(",");
  Serial.print(centerVal);
  Serial.print(",");
  Serial.println(rightVal);
  
  Serial.print("LS,RS=");
  Serial.print(leftSense);
  Serial.print(",");
  Serial.println(rightSense);
  
  Serial.print("Drift=");
  Serial.println(drift);
  
  return drift;
}

int lineFollow(int drift, int speed) {
  int leftSpeed = constrain(speed - (drift / damping), 0, 100);
  int rightSpeed = constrain(speed + (drift / damping), 0, 100);
  
  motorForward(MOTOR_LEFT, rightSpeed);
  motorForward(MOTOR_RIGHT, leftSpeed);
}

