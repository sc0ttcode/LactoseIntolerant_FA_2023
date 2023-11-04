const int buttonPin = 3;
const int ledPin = 13;
const int timeCyclePin = 12;
int buttonState = 0;
int previousButtonState = 0;
int cheeseMoment = 0;

void setup() 
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(timeCyclePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState != 0) 
  {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    if(cheeseMoment == 0)
    {
      cheeseMoment++;
      Serial.println(cheeseMoment);  
    }
          while(cheeseMoment == 1)
    {
      digitalWrite(timeCyclePin, HIGH);
      delay(500);
      digitalWrite(timeCyclePin, LOW);
      delay(500);
    }
} 
else 
{
    // turn LED off:
    digitalWrite(ledPin, LOW);
}
}

