#define TRIG_PIN 9
#define ECHO_PIN 10
#define GREEN_LED 3
#define ORANGE_LED 4
#define RED_LED 6

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(ORANGE_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    Serial.begin(9600);
}

long getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
  
    long duration = pulseIn(ECHO_PIN, HIGH);
    long distance = duration * 0.034 / 2; // Convert time to distance in cm
    return distance;
}

void loop() {
    long distance = getDistance();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 30) {  // Far
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(ORANGE_LED, LOW);
        digitalWrite(RED_LED, LOW);
    } else if (distance > 16 && distance <= 30) {  // Medium
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(ORANGE_LED, HIGH);
        digitalWrite(RED_LED, LOW);
    } else if(distance >= 5 && distance <=15) {  // Very Close
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(ORANGE_LED, LOW);
        digitalWrite(RED_LED, HIGH);
    }

    delay(200);
}
