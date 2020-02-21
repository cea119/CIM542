int led = 13;
int led2 = 12;
int led3 = 11;
int switchPin = 4;
int stateButton = 0;
int previous = LOW;
long time = 0;
long debounce = 200;
int stateLED = LOW;
long prevMillis = 0;
int curTime = 0;
boolean turnOn = false;
boolean pressing = false;
int switchRead = 0;
int mode = 0;


int timeSequence[6] = {300, 200, 300, 200, 300, 200};
int timeSequenceLength = 6; //adjust based on number of items in array



void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  switchRead = digitalRead(switchPin);
  //Serial.println(switchRead);

  if (switchRead == 1) {
    pressing = true;
  }

  if (switchRead == 0 && pressing == true) {
    pressing = false;
    //do something
    //counter = counter + 1;
    mode++;
    Serial.println(mode);
  }

  if (mode == 0) {
    //Reset of Off Condition
    digitalWrite(led, LOW);
    Serial.println("Mode 0");

  }
  else if (mode == 1) {
    digitalWrite(led, HIGH);
    Serial.println("Mode 1");

  } else if (mode == 2) {
    //run Mode program
    Serial.println("Mode 2");

    
    if (millis() - prevMillis > timeSequence[curTime]) {
      prevMillis = millis();
      if (turnOn == true) {
        turnOn = false;
      } else {
        turnOn = true;
      }

      curTime++;

      if (curTime == timeSequenceLength) {
        curTime = 0;
      }

      if (turnOn == true) {
        digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
      } else {
        digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
      }


      Serial.print("timeSequence: ");
      Serial.print(timeSequence[curTime]);
      Serial.print(" ");
      Serial.print("curTime: ");
      Serial.print(curTime);
      Serial.print(" ");
      Serial.print("turnOn: ");
      Serial.println(turnOn);


      //delay(30);

    }

  } else {
    mode = 0;
  }

}
