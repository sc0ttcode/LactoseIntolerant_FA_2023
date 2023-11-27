#include <Servo.h>

Servo s1;
Servo s2;
Servo s3;
Servo s4;
const int buttonPin = 3;
const int sickRowley = 5;
const int healthyRowley = 6;
int buttonVal;
int prevButtonVal;
int sickVal;
int prevSickVal;
int healthVal;
int prevHealthVal;

int pos = 0;           // variable to store the servo position
int cheeseMoment = 0;  //phase of action the project is in
bool cheeseSwitch = false;
bool sickSwitch = false;
bool healthSwitch = false;

unsigned long currTime = 0;
unsigned long prevTime = 0;
const long delayVal = 2000;
unsigned long timer;
bool direction = true;
int angle;

void setup() 
{
  s1.attach(12);  // attaches the servo on pin 9 to the servo object
  s1.write(0);
  s2.attach(11);
  s2.write(90);
  s3.attach(10);
  s3.write(0);
  s4.attach(9);
  s4.write(0);
  pinMode(buttonPin, INPUT);
  pinMode(sickRowley, INPUT);
  pinMode(healthyRowley, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  buttonVal = digitalRead(buttonPin);
  Serial.println(buttonVal);
  sickVal = digitalRead(sickRowley);
  Serial.println(sickVal);
  healthVal = digitalRead(healthyRowley);
  Serial.println(healthVal);
  currTime = millis();

  if(prevButtonVal != buttonVal) 
  {
    if(buttonVal == HIGH) 
    {
      //Serial.println("ON");
      cheeseSwitch = true;
      prevTime = currTime;
    } 
    else 
    {
      //Serial.println("OFF");
      cheeseSwitch = false;
      s1.write(0);
    }
  }
  if(prevHealthVal != healthVal)
  {
    if(healthVal == HIGH)
    {
      healthSwitch = true;
      prevTime = currTime;
    }
    else
    {
      healthSwitch = false;
    }
  }
  if(prevSickVal != sickVal)
  {
    if(sickVal == HIGH)
    {
      sickSwitch = true;
      prevTime = currTime;
    }
    else
    {
      sickSwitch = false;
    }
  }

  if (cheeseSwitch == true && cheeseMoment == 0) 
  {
    Serial.println("Stage 0");
    timer = currTime - prevTime;
    if (timer > delayVal) 
    {
      prevTime = currTime;
      direction = !direction;
    }

    if (direction) 
    {
      angle = map(timer, 0, delayVal, 0, 180);
      s1.write(angle);
    } else 
    {
      angle = map(timer, delayVal, 0, 0, 180);
      s1.write(angle);
    }
  }
  if(prevButtonVal != buttonVal && buttonVal == LOW && cheeseMoment == 0)
  {
    cheeseMoment = 1;
    Serial.println("Stage 1");
    cheeseSwitch = false;
  }

  if(cheeseMoment == 1)
  {
    Serial.println("stage 2");
    s1.write(0);
    cheeseMoment = 2;
  }
  if(cheeseSwitch == true && cheeseMoment == 2 && healthSwitch == true)
  {
    Serial.println("Stage 3");
    s2.write(90);
    s2.write(-30);
    cheeseMoment = 3;
  }
  if(cheeseSwitch == false && cheeseMoment == 3 && sickSwitch == true )
  {
    Serial.println("Stage 4");
    s2.write(90);
    cheeseMoment = 4;
  }
  if(cheeseMoment == 4)
  {
    delay(1000);
    s3.write(180);
    delay(3000);
    s4.write(180);
  }

  prevButtonVal = buttonVal;
}
