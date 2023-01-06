int ledPinOn = 3; // waterflow status led
int relais = 4; // relais output optocoupler == waterpump
int taster = 2; // input pushbutton
int i = 0; // iterationvariable for automatic mode
int j = 0; // iterationvariable for manual mode
int poti = A1;
int potiRaw = 0;
int timeConst = 0;
int trigger = A0; // select the trigger pin
int echo = A2;    // select the echo pin
int ledPin1  = 5; // definition of level leds 1-10
int ledPin2  = 6;
int ledPin3  = 7;
int ledPin4  = 8;
int ledPin5  = 9;
int ledPin6  = 10;
int ledPin7  = 11;
int ledPin8  = 12;
int ledPin9  = A4;
int ledPin10 = A5;
long duration = 0;
long distance = 0;

void refreshLevel(){ // call function to refresh water level display

  digitalWrite(trigger, LOW); //Trigger pin LOW
  delay(10); //wait 5ms
  digitalWrite(trigger, HIGH); //send soundwave
  delay(10); //wait 10ms
  digitalWrite(trigger, LOW);//turn off sound
  duration = pulseIn(echo, HIGH); //measure time 
  distance = (duration/2) * 0.03432; //magic math
  Serial.println(distance);

  if (distance < 2 or distance > 100)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, HIGH);
  }

  if (distance < 3)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, HIGH);
  }
    if (distance > 3 and distance < 6)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, HIGH);
    digitalWrite(ledPin10, LOW);
  }

    if (distance > 6 and distance < 9)
  {
   digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
  }
    if (distance > 9 and distance < 12)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
  }
    if (distance > 12 and distance < 15)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
  }
    if (distance > 15 and distance < 18)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
  }
    if (distance > 18 and distance < 21)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
  }
    if (distance > 21 and distance < 24)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
  }
    if (distance > 24 and distance < 27)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
  }
    if (distance > 27 and distance < 30)
  {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
  }
    if (distance > 30)
  {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
    digitalWrite(ledPin9, LOW);
    digitalWrite(ledPin10, LOW);
  }
}

void setup() {
  pinMode(ledPinOn, OUTPUT);
  pinMode(relais, OUTPUT);
  pinMode(taster, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
}

void loop() 
{
  potiRaw = analogRead(poti);
  timeConst = map(potiRaw, 0, 713, 0, 20000 );
  refreshLevel();
  // Serial.print(potiRaw);
  // Serial.print("\t");
  // Serial.print(timeConst);
  // Serial.println();

  i = 0;
  j = 0;
  if (digitalRead(taster) == 0 and distance < 30) // initial button push and check of sufficient water level
  {
    delay(150); // output delay part 1
    if (digitalRead(taster) == 1) // check pushbutton off
    {
      delay(150);
      if (digitalRead(taster) == 0) // check doublepush
      {
        digitalWrite(ledPinOn, HIGH);
        digitalWrite(relais, HIGH);
        delay(300); //delay for while loop in case pushbutton still pressed
        while (digitalRead(ledPinOn) == 1 and digitalRead(relais) == 1 and i < timeConst and distance < 30) // turn off button push or water level low
        {
          refreshLevel();
          if (digitalRead(taster) == 0 or distance > 30) // turn off condition pushbutton or waterlevel low
          {
            digitalWrite(ledPinOn, LOW);
            digitalWrite(relais, LOW);
            delay(1000); // debouncing of trigger
          }
          delay(1);
          i++; // iterations increment
        }
      }
    }
    delay(350); // turn on delay
    if (digitalRead(taster) == 0)
    {
      while (digitalRead(taster) == 0 and j < 10000 and distance < 30) // manual mode button push and check of sufficient water level
      {
      refreshLevel();
      digitalWrite(ledPinOn, HIGH);
      digitalWrite(relais, HIGH);
      delay(1);
      j++;
      }
      while (digitalRead(taster) == 0)
      {
        refreshLevel();        
        digitalWrite(ledPinOn, LOW);
        digitalWrite(relais, LOW);
      }
      delay(200);
    }
  }
  else // turn off water pump in idle
  {
    digitalWrite(ledPinOn, LOW);
    digitalWrite(relais, LOW);
  }
}
