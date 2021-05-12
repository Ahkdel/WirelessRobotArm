// For the Nano

// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module
// Tested on Arduino Mega, Duemilanova, Uno, Due, Teensy, ESP-12

#include <Wire.h>
#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

RH_ASK driver (2000, 8, 2, 9, false);
// RH_ASK (uint16_t speed=2000, uint8_t rxPin=11, uint8_t txPin=12, uint8_t pttPin=10, bool pttInverted=false)
// RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
// RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
// RH_ASK driver(2000, PD14, PD13, 0); STM32F4 Discovery: see tx and rx on Orange and Red LEDS

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
int originX, originY, originZ;

typedef enum {
  NOTHING = 0,
  OPENING = 1,
  CLOSING = 2
} gripStatus;

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(9600);	  // Debugging only
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
    Serial.println("init failed");
#else
	; 
#endif
  if (!accel.begin()) {
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }
  originX = accel.getX();
  originY = accel.getY();
  originZ = accel.getZ();
  Serial.print("originX = "); Serial.println(originX);
  Serial.print("originY = "); Serial.println(originY);
  Serial.print("originZ = "); Serial.println(originZ);

  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
}

void loop()
{
    int x, y, z;
    int opening, closing, nothing;
    gripStatus grip;
    
    x = accel.getX() - originX;
    y = accel.getY() - originY;
    z = accel.getZ() - originZ;
    
    Serial.print("X = "); Serial.println(x);
    Serial.print("Y = "); Serial.println(y);
    Serial.print("Z = "); Serial.println(z);
    
    grip = NOTHING;
    opening = analogRead(A1);
    closing = analogRead(A2);
    Serial.print("A1 >--> "); Serial.println(opening);
    Serial.print("A2 >--> "); Serial.println(closing);
    if (opening < 500) {
      if (closing < 500) 
        grip = NOTHING;
      else 
        grip = CLOSING;
    }
    else
      grip = OPENING;

    Serial.print("Grip = "); Serial.println(grip);

    char gripString[2];
    char xString[5], yString[5], zString[5];
    
    sprintf(gripString, "%d", grip);
    sprintf(xString,    "%d", x);
    sprintf(yString,    "%d", y);
    sprintf(zString,    "%d", z);

    String msgString;
    msgString += gripString; msgString += ",";
    msgString += xString;    msgString += ",";
    msgString += yString;    msgString += ",";
    msgString += zString;
    
    const char *msg = msgString.c_str();
    Serial.print("Message = "); Serial.println(msg);
    
    //const char msg[] = ;
    driver.send((uint8_t *)msg, strlen(msg));
    digitalWrite(LED_BUILTIN, LOW);
    driver.waitPacketSent();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
}
