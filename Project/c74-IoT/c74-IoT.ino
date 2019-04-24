#include "wio_tracker.h"
#include <Ultrasonic.h>
#include<stdio.h>
#define ULTRASONIC_PIN  (D20)
Ultrasonic UltrasonicRanger(ULTRASONIC_PIN);
WioTracker wio = WioTracker();

void setup() {
  wio.Power_On();
  SerialUSB.println("Power On!");
  SerialUSB.println("Registering to network");

  if (!wio.waitForNetworkRegister())
  {
    SerialUSB.println("Network error");
    return;
  } else {
    SerialUSB.println("Network registration complete");
  }
  wio.readAllRecUnreadSMS();
}

void loop() {
  long distance;
  distance = UltrasonicRanger.MeasureInCentimeters();
  char charBuf [50];
  String stringOne = "";
  stringOne += distance;
  stringOne.toCharArray(charBuf, 50);
  wio.sendSMS("2936", charBuf);
  delay(15000);
}
