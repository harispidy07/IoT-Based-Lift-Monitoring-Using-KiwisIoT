#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <DHT.h>

// Ultrasonic sensor
#define TRIG_PIN D5
#define ECHO_PIN D6

// DHT11 sensor
#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// WiFi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

KiwisIoT kiwisiot(ssid, pass, topic);

// Demonstration thresholds
const float OCCUPANCY_LIMIT = 100.0;
const float TEMP_LIMIT = 35.0;

float distance;
float temperature;
float humidity;

void setup() {

  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dht.begin();

  kiwisiot.begin();

  Serial.println("Lift Monitoring Started");
}

void loop() {

  kiwisiot.run();

  // Measure distance
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    Serial.println("Ultrasonic Sensor Error");
    delay(1000);
    return;
  }

  distance = duration * 0.0343 / 2;

  // Read DHT11
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 Sensor Error");
    delay(2000);
    return;
  }

  String occupancyStatus;
  String systemStatus;

  if (distance < OCCUPANCY_LIMIT) {
    occupancyStatus = "CABIN OCCUPIED";
  } else {
    occupancyStatus = "CABIN EMPTY";
  }

  if (temperature >= TEMP_LIMIT) {
    systemStatus = "TEMPERATURE ALERT";
  } else {
    systemStatus = "NORMAL";
  }

  // Send data to KiwisIoT
  kiwisiot.send("0", String(distance, 2));
  kiwisiot.send("1", occupancyStatus);
  kiwisiot.send("2", String(temperature, 1));
  kiwisiot.send("3", String(humidity, 1));
  kiwisiot.send("4", systemStatus);

  Serial.println("-------------------------");

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Occupancy: ");
  Serial.println(occupancyStatus);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("System Status: ");
  Serial.println(systemStatus);

  Serial.println("-------------------------");

  delay(2000);
}