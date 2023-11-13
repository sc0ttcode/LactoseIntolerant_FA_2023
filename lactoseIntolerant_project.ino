/* Sweep
 by BARRAGAN http://barraganstudio.com/
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo s1;  // create servo object to control a servo
// twelve servo objects can be created on most boards
const int buttonPin = 3;

int pos = 0;    // variable to store the servo position
int cheeseMoment = 0; //phase of action the project is in

void setup() 
{
  s1.attach(12);  // attaches the servo on pin 9 to the servo object
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(digitalRead(buttonPin) == HIGH && cheeseMoment == 0)
  {
    cheeseMoment == cheeseMoment++;
  while(digitalRead(buttonPin) == HIGH && cheeseMoment == 1)
  {
    Serial.println("working");
  for(int i = 0; i <= 180; i += 1)
  {
    s1.write(i);
    delay(15);
  }
  for(int i = 180; i >= 0; i -= 1)
  {
    s1.write(i);
    delay(15);
  }
  }
  }
    else
  {
    s1.write(0);
  }
}
