#include "receiver_header.h"

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
  base.attach(3);
  joint1.attach(4);
  joint2.attach(5);
  joint3.attach(6);
  gripper.attach(7);
  joint1.write(0);  delay(100);
  joint2.write(0);  delay(100);
  joint3.write(0);  delay(100);
  base.write(0);    delay(100);
//  setToZero(joint1);
//  setToZero(joint2);
//  setToZero(joint3);
//  setToZero(base);
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
    delay(1000);
    lcd.clear();
  }
}
