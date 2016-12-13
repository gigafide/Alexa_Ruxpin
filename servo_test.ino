//Import the servo library
#include <Servo.h>

//Declare three servos
Servo myServo1; //mouth
Servo myServo2; //eyes
Servo myServo3; //nose

//Set the inital servo position
int pos = 10;

void setup()
{
  myServo1.attach(9); //attach mouth to pin 9
  myServo2.attach(10); //attach eyes to pin 10
  myServo3.attach(11); //attach nose to pin 11
}

void loop()
{
  //Blink eyes
  eyeBlink();
  delay(1000);
  //talk 3 times
  talk();
  delay(1000);
  talk();
  delay(1000);
  talk();
  delay(1000);
  //Blink eyes
  eyeBlink();
  //talk 2 times
  talk();
  delay(1000);
  talk();
  delay(1000);
}

//create a blink function that cycles
//through servo positions
void eyeBlink()
{
  for(pos = 10; pos < 170; pos += 10)
  {
    myServo2.write(pos);
    delay(15);
  }
  for(pos = 170; pos >= 11; pos -= 10)
  {
    myServo2.write(pos);
    delay(15);
  }
}

//create a talk function that cycles
//through servo positions
void talk()
{
  for(pos = 10; pos < 170; pos += 10)
  {
    myServo1.write(pos);
    myServo3.write(pos);
    delay(15);
  }
  for(pos = 170; pos >= 11; pos -= 10)
  {
    myServo1.write(pos);
    myServo3.write(pos);
    delay(15);
  }
}
