/*
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>


RF24 radio(7, 8); // CE, CSN




// Motor pins (L298N)
#define ENA 3
#define INA 4
#define INB 5
#define INC 6
#define IND 9
#define ENB 10


Servo grabber;


int servoPin = A2;


const byte address[6] = "00007";
String buffer = "";


int speed = 150;


void setup() {


 Serial.begin(9600);
 radio.begin();
 radio.openReadingPipe(0, address);
 radio.setPALevel(RF24_PA_MIN);
 radio.startListening();


 pinMode(ENA, OUTPUT);
 pinMode(INA, OUTPUT);
 pinMode(INB, OUTPUT);


 pinMode(ENB, OUTPUT);
 pinMode(INC, OUTPUT);
 pinMode(IND, OUTPUT);


grabber.attach(servoPin);




grabber.write(35);


}


void loop() {
 if (radio.available()) {
   char text[32] = "";
   radio.read(&text, sizeof(text));
   buffer = String(text);
   //Serial.println(text);
 }




 if(buffer.equals("forward")){
Serial.println(buffer);


 analogWrite(ENA, 150);
 digitalWrite(INA, LOW);
 digitalWrite(INB, HIGH);


 analogWrite(ENB, 150);
 digitalWrite(INC, LOW);
 digitalWrite(IND, HIGH);


 }else if(buffer.equals("back")){
Serial.println(buffer);


 digitalWrite(INA, HIGH);
   digitalWrite(INB, LOW);




   digitalWrite(INC, HIGH);
   digitalWrite(IND, LOW);


 }else if(buffer.equals("left")){
Serial.println(buffer);


 digitalWrite(INA, HIGH);
   digitalWrite(INB, LOW);




   digitalWrite(INC, LOW);
   digitalWrite(IND, HIGH);


 }else if(buffer.equals("right")){
Serial.println(buffer);


 digitalWrite(INA, LOW);
   digitalWrite(INB, HIGH);




   digitalWrite(INC, HIGH);
   digitalWrite(IND, LOW);




 }else if(buffer.equals("nothing")){
Serial.println(buffer);


 digitalWrite(INA, LOW);
   digitalWrite(INB, LOW);




   digitalWrite(INC, LOW);
   digitalWrite(IND, LOW);


 }else if (buffer.equals("pressed")){
   //servo code underneath


grabber.write(35);
delay(100);




grabber.write(125);
delay(2000);
grabber.write(35);
return;


 }








}

