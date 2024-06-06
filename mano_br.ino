const int leftHandLEDs[] = {11, 10, 9, 8, 7};
const int rightHandLEDs[] = {6, 5, 4, 3, 2};

void setup() {
  for (int i = 2; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    int fingers = Serial.parseInt();
    
    // Enciende los LEDs de la mano izquierda según la cantidad de dedos
    for (int i = 0; i < 5; i++) {
      if (i < fingers && i < 5) {
        digitalWrite(leftHandLEDs[i], HIGH);
      } else {
        digitalWrite(leftHandLEDs[i], LOW);
      }
    }
    
    // Enciende los LEDs de la mano derecha según la cantidad de dedos
    for (int i = 0; i < 5; i++) {
      if (i < fingers - 5 && i >= 0) {
        digitalWrite(rightHandLEDs[i], HIGH);
      } else {
        digitalWrite(rightHandLEDs[i], LOW);
      }
    }
  }
}