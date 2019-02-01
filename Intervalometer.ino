#define BUTTON_PIN 8
#define FOCUS_PIN 3
#define SHUTTER_PIN 9

long focusMillis;
long shutterMillis;
long pauseMillis;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH);

  pinMode(FOCUS_PIN, OUTPUT);
  pinMode(SHUTTER_PIN, OUTPUT);
  digitalWrite(FOCUS_PIN, HIGH);
  digitalWrite(SHUTTER_PIN, HIGH);

  while(digitalRead(BUTTON_PIN)) {
    // do nothing
  }
  
  focusMillis = millis();

  while(!digitalRead(BUTTON_PIN)) {
    // do nothing
  }

  focusMillis = millis() - focusMillis;

  delay(100);
  
  while(digitalRead(BUTTON_PIN)) {
    // do nothing
  }

  shutterMillis = millis();

  while(!digitalRead(BUTTON_PIN)) {
    // do nothing
  }

  shutterMillis = millis() - shutterMillis;

  delay(100);

  while(digitalRead(BUTTON_PIN)) {
    // do nothing
  }

  pauseMillis = millis();

  while(!digitalRead(BUTTON_PIN)) {
    // do nothing
  }

  pauseMillis = millis() - pauseMillis;
}

void loop() {
  digitalWrite(FOCUS_PIN, LOW);
  delay(focusMillis);
  digitalWrite(SHUTTER_PIN, LOW);
  delay(shutterMillis);
  digitalWrite(FOCUS_PIN, HIGH);
  digitalWrite(SHUTTER_PIN, HIGH);
  delay(pauseMillis);
}
