//temphum (port:42004)
//Serial temperature/humidity sensor
//With optional luminosity sensor (using a photoresistor)
//https://github.com/madnerdorg/temphum

// Based on Example testing sketch
// Written by ladyada, public domain

#include "DHT.h"

const String usb_name = "temphum:42004";
const bool hasPhotoResistor = false;
const int DHTPIN = 2;     // what digital pin we're connected to
const int LUMPIN = A0;    //Photoresistor pin

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

//Serial string buffer
String readString;
bool serial_check = false;

// Serial

//When application asked if this is the correct arduino
void serialCheck() {
  if (readString == usb_name) {
    Serial.print("OK");
    serial_check = true;
    delay(1000);
  }

  if (readString == "/info") {
    Serial.println(usb_name);
    serial_check = true;
    delay(1000);
  }
}

//Convert characters sent by serial to string
void serialManager() {
  //Get Serial as a string
  while (Serial.available()) {
    delay(3); // Wait for data

    //Convert to String
    if (Serial.available() > 0) {
      char c = Serial.read();
      readString += c;
    }
  }
}


void setup() {
  Serial.begin(115200);
  //Serial.println("DHTxx test!");
  dht.begin();
}

void loop() {
  delay(100);
  serialManager();

  //If string received
  if (readString.length() > 0) {
    serialCheck();
    readString = "";
  }

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  int lum = analogRead(LUMPIN);
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);

  if (serial_check) {
    if (isnan(h) || isnan(t)) {
      if (hasPhotoResistor) {
        Serial.println("NaN;NaN;NaN");
      } else {
        Serial.println("NaN;NaN");
      }
    } else {
      Serial.print(h);
      Serial.print(";");

      if (hasPhotoResistor) {
        Serial.print(t);
        Serial.print(";");
        Serial.println(lum);
      } else {
        Serial.println(t);
      }

    }
  }
  
}
