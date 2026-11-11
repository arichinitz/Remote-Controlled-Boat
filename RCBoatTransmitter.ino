/*
 Adapted Transmitter Code – Full 2D Joystick Control
*/


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00007";


#define VRX A0
#define VRY A1
#define SW 2


void setup() {
 pinMode(SW, INPUT_PULLUP);


 radio.begin();
 radio.openWritingPipe(address);
 radio.setPALevel(RF24_PA_MIN);
 radio.stopListening();
}


void loop() {


 int xValue = analogRead(VRX);
 int yValue = analogRead(VRY);
 bool buttonPressed = (digitalRead(SW) == LOW);


 const char* text = "";


 // Deadzone to prevent jitter
 bool up    = (yValue > 600);
 bool down  = (yValue < 400);
 bool left = (xValue > 600);
 bool right  = (xValue < 400);


 if (buttonPressed) {
   text = "pressed";
   delay(1000);
 }
 else if (up && left) {
   text = "forward-left";
 }
 else if (up && right) {
   text = "forward-right";
 }
 else if (down && left) {
   text = "back-left";
 }
 else if (down && right) {
   text = "back-right";
 }
 else if (up) {
   text = "forward";
 }
 else if (down) {
   text = "back";
 }
 else if (left) {
   text = "left";
 }
 else if (right) {
   text = "right";
 }
 else {
   text = "nothing"; // centered → send nothing
 }


 radio.write(text, strlen(text) + 1);


 delay(100);
}

