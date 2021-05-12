// ask_receiver.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to receive messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) receiver with an Rx-B1 module
// Tested on Arduino Mega, Duemilanova, Uno, Due, Teensy, ESP-12
// For the Uno

#include <string.h>
#include <LiquidCrystal.h>
#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

RH_ASK driver (2000, 2, 0, 1, false);
// RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
// RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
// RH_ASK driver(2000, PD14, PD13, 0); STM32F4 Discovery: see tx and rx on Orange and Red LEDS

//LiquidCrystal(rs, enable, d4, d5, d6, d7);
LiquidCrystal lcd (8, 9, 10, 11, 12, 13);

void setup()
{
#ifdef RH_HAVE_SERIAL
    Serial.begin(9600);	  // Debugging only
#endif
    if (!driver.init())
#ifdef RH_HAVE_SERIAL
    Serial.println("init failed");
#else;
#endif
  lcd.begin(16, 2);
  lcd.print("Message");
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);
  digitalWrite(LED_BUILTIN, LOW);
           
  if (driver.recv(buf, &buflen)) { // Non-blocking
    digitalWrite(LED_BUILTIN, HIGH);
    int i;
    // Message with a good checksum received, dump it.
    driver.printBuffer("Got:", buf, buflen);
    String message;
    for (i = 0; i < buflen; i++)
      message += (char)buf[i];
    Serial.print("message: ");
    Serial.println(message);
    
    lcd.setCursor(0,0);
    lcd.print(message);
    delay(200);
    //lcd.clear();
  }
}
