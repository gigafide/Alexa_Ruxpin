#include <Servo.h>

//declare constants for audio input
int Musicread = 0;
int Music;

//LED pin is only for testing
const int ledPin = 13;

//declare constants for servos
Servo myServo1;
Servo myServo2;
Servo myServo3;
int pos = 10;
int pos2 = 20;
int pos3 = 10;

//declare constants for timer
long previousMillis = 0;
long interval = 15000; // timer is set to 15 second intervals


void setup(){
  pinMode(ledPin, OUTPUT); //Assign LED pin mode
  myServo1.attach(9); //Nose servo
  myServo2.attach(10); //Eyes servo
  myServo3.attach(11); //Mouth Servo
  myServo1.write(20); //Nose beginning servo position
  myServo2.write(10); //Eyes beginning servo position
  myServo3.write(10); //Mouth beginning servo position
  
}

void loop(){
  //Set timer for eyeblinks (every 15 seconds)
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval){
    previousMillis = currentMillis;
    eyeBlink();
  }
  
  //Read audio value from analog pin.
  //If the value equals 1, run the small movement talk script
  //If the value is greater than 1, rin the large movement talk script
  //Otherwise, set everything back to its original value.
  Music = analogRead(Musicread);
  delay(10);
  if (Music == 1){
    talk();
    digitalWrite(ledPin, HIGH);
    delay(10);
  } else if (Music > 1){
    talk2();
    digitalWrite(ledPin, HIGH);
    delay(10);
  } else {
    //myServo3.write(10);
    digitalWrite(ledPin, LOW);
    delay(10);
  }
}

//Small movement talk script (opens mouth a little)
void talk()
{
   for(pos = 10; pos < 90; pos += 5)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myServo1.write(pos);              // tell servo to go to position in variable 'pos' 
    myServo3.write(pos);
    delay(10);                       // waits 15ms for the servo to reach the position 
  }
  for(pos = 90; pos>=11; pos-= 5)     // goes from 180 degrees to 0 degrees 
  {                                
    myServo1.write(pos);              // tell servo to go to position in variable 'pos' 
    myServo3.write(pos);
    delay(10);                       // waits 15ms for the servo to reach the position 
  } 
}

//Large movement talk script (opens mouth a lot)
void talk2()
{
   for(pos = 10; pos < 140; pos += 10)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myServo1.write(pos);              // tell servo to go to position in variable 'pos' 
    myServo3.write(pos);
    delay(10);                       // waits 15ms for the servo to reach the position 
  }
  for(pos = 140; pos>=11; pos-= 10)     // goes from 180 degrees to 0 degrees 
  {                                
    myServo1.write(pos);              // tell servo to go to position in variable 'pos' 
    myServo3.write(pos);
    delay(10);                       // waits 15ms for the servo to reach the position 
  } 
}

//Eye blink script
void eyeBlink()
{
  for(pos3 = 10; pos3 < 150; pos3 += 10)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myServo2.write(pos3);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos3 = 150; pos3>=11 ; pos3-= 10)     // goes from 180 degrees to 0 degrees 
  {                                
    myServo2.write(pos3);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}
