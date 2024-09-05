#include <ESP8266WiFi.h>
#include <Wire.h>
#include <DS1307.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "myiot-dd441-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "fKRkmBvfkxrOX6mgXEySNK0e9NXBUAKhYHuDKH71"
#define WIFI_SSID "OnePlus"
#define WIFI_PASSWORD "1234567890"

#define WifiLed D4

const int latchPin = D7;
const int clockPin = D8;
const int dataPin = D6;

byte ledState = 0;

void updateLEDs() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, ledState);
  digitalWrite(latchPin, HIGH);
}

void controlLED(int ledNumber, int state) {
  if (state) {
    ledState |= (1 << ledNumber);
  } else {
    ledState &= ~(1 << ledNumber);
  }
  updateLEDs();
}

#define s0 D0
#define s1 D3
#define s2 D4
#define s3 D5
#define SIG_pin A0

int Light1_val, Light2_val;
DS1307 rtc;
uint8_t sec, min, hour, day, month;
uint16_t year;

int firemin, firehour, fireday;

void setup() {
  Serial.begin(9600);
  rtc.begin();
  // rtc.set(0, 47, 12, 23, 8, 2024); //sec, min, hour, day, month, year
  // rtc.stop();
  rtc.start();
  rtc.get(&sec, &min, &hour, &day, &month, &year);

  pinMode(SIG_pin, INPUT);
  pinMode(WifiLed, OUTPUT);

  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);}
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(WifiLed, HIGH);
    delay(500);
    digitalWrite(WifiLed, LOW);
    delay(500);
  }
  controlLED(0, Firebase.getString("Light0").toInt());
  controlLED(1, Firebase.getString("Light1").toInt());
  controlLED(2, Firebase.getString("Light2").toInt());
  controlLED(3, Firebase.getString("Light3").toInt());
  controlLED(4, Firebase.getString("Light4").toInt());
  controlLED(5, Firebase.getString("Light5").toInt());

  for (int i = 0; i < 6; i++) {
    Firebase.setInt("LDR" + String(i),   readMux(i));
    delay(60);
  }
  
  delay(50);
  rtc.get(&sec, &min, &hour, &day, &month, &year);
  Serial.println(int(hour));
  Serial.println(int(min));
  if (Firebase.getString("StimeHour").toInt() == int(hour) && Firebase.getString("Stimemin").toInt() == int(min)) {
    for (int i = 0; i < 6; i++) {
      Firebase.setString("Light" + String(i), "1");
    }
    Firebase.setString("SDay", "1");
  }
  if (Firebase.getString("EtimeHour").toInt() == int(hour) && Firebase.getString("Etimemin").toInt() == int(min)) {
    for (int i = 0; i < 6; i++) {
      Firebase.setString("Light" + String(i), "0");
    }
    Firebase.setString("EDay", "1");
  }

}

float readMux(int channel) {
  int controlPin[] = {s0, s1, s2, s3};
  int muxChannel[16][4] = {
    {0, 0, 0, 0}, //channel 0
    {1, 0, 0, 0}, //channel 1
    {0, 1, 0, 0}, //channel 2
    {1, 1, 0, 0}, //channel 3
    {0, 0, 1, 0}, //channel 4
    {1, 0, 1, 0}, //channel 5
    {0, 1, 1, 0}, //channel 6
    {1, 1, 1, 0}, //channel 7
    {0, 0, 0, 1}, //channel 8
    {1, 0, 0, 1}, //channel 9
    {0, 1, 0, 1}, //channel 10
    {1, 1, 0, 1}, //channel 11
    {0, 0, 1, 1}, //channel 12
    {1, 0, 1, 1}, //channel 13
    {0, 1, 1, 1}, //channel 14
    {1, 1, 1, 1} //channel 15
  };
  for (int i = 0; i < 4; i ++) {
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }
  int val = analogRead(SIG_pin);
  return val;
}
