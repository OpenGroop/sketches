/*
 * STHP v1.4
 * 
 * ADAFRUIT FEATHER PROTO BOARD 32U4 (3.3v)
 * TEMPERATURE/HUMIDITY    DHT22
 * LIGHT INTENSITY (5mm LDR)  
 * 
 */

#include "DHT.h"

#define DHTPIN 12  // DIGITAL
#define LDRPIN 5  // ANALOG
#define DHTTYPE DHT22

const String DEVICE_CODE = "sthp";

const String DEVICE_ID   = "7"; // 9 IS NEXT!! THIS MUST BE DIFFERENT FOR EVERY DEVICE.
const String REVISION_ID = "v1.7";

const String DEVICE   = "device_id";
const String HUMIDITY = "humidity";
const String LDR      = "ldr";
const String REVISION = "revision";
const String TEMP_C   = "temp_c";
const String TEMP_F   = "temp_f";

DHT dht(DHTPIN, DHTTYPE);

void setup() {
//  analogReference(EXTERNAL);
  pinMode(LED_BUILTIN, OUTPUT);
  dht.begin();
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  while(!Serial) {}

  float humidity = dht.readHumidity();
  float tempC    = dht.readTemperature();
  float tempF    = dht.readTemperature(true);
  int ldr        = analogRead(LDRPIN);

  Serial.println("{'" + DEVICE   + "':'" + DEVICE_CODE + "_" + DEVICE_ID   + "','" +
                        REVISION + "':'" + DEVICE_CODE + "_" + REVISION_ID + "','" +
                        HUMIDITY + "':'" + humidity + "','" +
                        LDR      + "':'" + ldr      + "','" +              
                        TEMP_C   + "':'" + tempC    + "','" +
                        TEMP_F   + "':'" + tempF    + "'}");
   
//  for(int i =0; i < 59; i++) {
//    while(!Serial) {}
//    digitalWrite(LED_BUILTIN, HIGH);  
//    delay(500);
//    digitalWrite(LED_BUILTIN, LOW);
//    delay(500);  
//    }

  delay(59000);

}
