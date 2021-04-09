// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module
// Tested on Arduino Mega, Duemilanova, Uno, Due, Teensy, ESP-12
// For the Nano

#include <RH_ASK.h>
#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Not actually used but needed to compile
#endif

RH_ASK driver;
// RH_ASK driver(2000, 4, 5, 0); // ESP8266 or ESP32: do not use pin 11 or 2
// RH_ASK driver(2000, 3, 4, 0); // ATTiny, RX on D3 (pin 2 on attiny85) TX on D4 (pin 3 on attiny85), 
// RH_ASK driver(2000, PD14, PD13, 0); STM32F4 Discovery: see tx and rx on Orange and Red LEDS

int counter = 1;
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
    pinMode (2, OUTPUT);
}

void loop()
{
    const char *msg1 = "message1";
    const char *msg2 = "message2";
    const char *msg3 = "message3";
    const char *msg4 = "message4";
    const char *msg5 = "message5";
    const char *msg6 = "message6";
    const char *msg7 = "message7";
    const char *msg8 = "message8";
    if (digitalRead(2) == HIGH) counter++;
    switch (counter) {
      case 1:
        driver.send((uint8_t *)msg1, strlen(msg1));
        break;
      case 2:
        driver.send((uint8_t *)msg2, strlen(msg2));
        break;
      case 3:
        driver.send((uint8_t *)msg3, strlen(msg3));
        break;
      case 4:
        driver.send((uint8_t *)msg4, strlen(msg4));
        break;
      case 5:
        driver.send((uint8_t *)msg5, strlen(msg5));
        break;
      case 6:
        driver.send((uint8_t *)msg6, strlen(msg6));
        break;
      case 7:
        driver.send((uint8_t *)msg7, strlen(msg7));
        break;
      case 8:
        driver.send((uint8_t *)msg8, strlen(msg8));
        break;
    }
    digitalWrite(LED_BUILTIN, LOW);
    driver.waitPacketSent();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
}
