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

RH_ASK driver;
// RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
// RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
// RH_ASK driver(2000, PD14, PD13, 0); STM32F4 Discovery: see tx and rx on Orange and Red LEDS

//LiquidCrystal(rs, enable, d4, d5, d6, d7);
LiquidCrystal lcd (7, 6, 5, 4, 3, 2);
bool changed = false;
String stringflag = "";

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
  String msg1 =  "Hi, sweetheart!";
  
  String msg2 =  "I know these";
  String msg3 =  "days were";
  
  String msg4 =  "difficult...";

  String msg5 =  "But I want you";
  String msg6 =  "to know that";

  String msg7 =  "you are really";
  String msg8 =  "awesome! And...";

  String msg9 =  "I'm glad that";
  String msg10 = "I have met you!";

  String msg11 = "Everything will";
  String msg12 = "get better!";

  String msg13 = "I love you";
  String msg14 = "so much, honey!";
  
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
    if (stringflag != message) {
      lcd.clear();
      stringflag = message;
    }
    
    if (message == "message1") { 
      lcd.print(msg1);
    }
    else if (message == "message2") {
      lcd.print(msg2);
      lcd.setCursor(0,1);
      lcd.print(msg3);
    }
    else if (message == "message3"){
      lcd.print(msg4);
    }
    else if (message == "message4"){
      lcd.print(msg5);
      lcd.setCursor(0,1);
      lcd.print(msg6);
    }
    else if (message == "message5"){
      lcd.print(msg7);
      lcd.setCursor(0,1);
      lcd.print(msg8);
    }
    else if (message == "message6"){
      lcd.print(msg9);
      lcd.setCursor(0,1);
      lcd.print(msg10);
    }
    else if (message == "message7"){
      lcd.print(msg11);
      lcd.setCursor(0,1);
      lcd.print(msg12);
    }
    else if (message == "message8"){
      lcd.print(msg13);
      lcd.setCursor(0,1);
      lcd.print(msg14);
    }
    lcd.setCursor(0,0);
    delay(2000);
  }
}
