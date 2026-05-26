// Pin Definitions  
const int valve1 = 10;   // valve1 is connected to pin 10
const int valve2 = 9;    // valve2 is connected to pin 9
const int dryer  = 8;    // dryer is connected to pin 8

const int relay1 = 7;    // relay1 is connected to pin 7
const int relay2 = 6;    // relay2 is connected to pin 6
const int relay3 = 5;    // relay3 is connected to pin 5

int hasObstacle1;        // variable for sensor1
int hasObstacle2;        // variable for sensor2
int hasObstacle3;        // variable for sensor3

void setup() {
  // Sensor pins as input
  pinMode(valve1, INPUT);
  pinMode(valve2, INPUT);
  pinMode(dryer, INPUT);

  // Relay pins as output
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);

  // Keep all relays OFF initially (HIGH = OFF for active-low relay modules)
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);

  Serial.begin(9600); // start serial communication
}

void loop() {
  // Read sensors
  hasObstacle1 = digitalRead(valve1);
  hasObstacle2 = digitalRead(valve2);
  hasObstacle3 = digitalRead(dryer);

  // Sanitizer pump
  if (hasObstacle1 == LOW) {
    digitalWrite(relay1, LOW);  // turn ON relay1
    Serial.println("Sanitize your hand!");
    delay(1000);
  }

  // Water pump
  if (hasObstacle2 == LOW) {
    digitalWrite(relay2, LOW);  // turn ON relay2
    Serial.println("Wash your hand!");
    delay(3000);
  }

  // Dryer
  if (hasObstacle3 == LOW) {
    digitalWrite(relay3, LOW);  // turn ON relay3
    Serial.println("Dry your hand!");
    delay(5000);
  }

  // Turn OFF all relays after each cycle
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);

  delay(200);  // small delay before next loop
}
