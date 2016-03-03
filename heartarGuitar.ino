int light =  11;
int sound = A0;
int touch = A1;
int ledPin =  2;
int ledPin2 =  3;
int ledPin3 =  4;
int buzzer =  5;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(light, INPUT);
  pinMode(sound, INPUT);
  pinMode(touch, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  pinMode(buzzer, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(light);
  int soundState = analogRead(sound);
  int touchState = analogRead(touch);

  Serial.println(soundState);
  Serial.println(touchState);

  if (soundState >= 1015) {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
 
    analogWrite(buzzer,50);
    delay(1000);
    analogWrite(buzzer,200);
    delay(200);
  }else {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);

    analogWrite(buzzer, LOW);
  }

  if (buttonState == LOW) {
    analogWrite(buzzer,50);
    delay(1000);
    analogWrite(buzzer,200);
    delay(200);
  } else {
    analogWrite(buzzer, LOW);
  }

if (touchState >= 100) {
    // turn LED on:
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);

  }
  else {
    // turn LED off:
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);

  }

}
