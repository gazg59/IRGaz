/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

//decode_results results;

void setup()
{
  Serial.begin(9600);
  //irrecv.enableIRIn(); // Start the receiver
  irrecv.begin(true); //blinking
}

void loop() {
  //if (irrecv.decode(results)) {
  //if (irrecv.available()) {
  if (irrecv.available(irNEC)) {
    //if (irrecv.decodeNEC())
      Serial.println(irrecv.read(), HEX);
    //irrecv.resume(); // Receive the next value
  }
  delay(100);
}
