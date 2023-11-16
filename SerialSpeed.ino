int IN1 = 26;
int IN2 = 27;
int ENA = 14;

void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void loop() {

  if (Serial.available()) {
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 255) {
      Serial.println("Recibido!");
      Serial.println(speed);

      analogWrite(ENA, speed);
    }

    if (speed == 500) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }

    if (speed == 600) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }

    if (speed == 700) {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }
  }

  delay(20);
}
