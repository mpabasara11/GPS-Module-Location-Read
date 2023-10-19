#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Define the software serial connection to the GPS module
SoftwareSerial gpsSerial(2, 3);  // RX, TX

// Create a TinyGPS object
TinyGPSPlus gps;



void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("GPS Data:");
}

void loop() {

while (gpsSerial.available() > 0)
{
  gps.encode(gpsSerial.read());

  if(gps.location.isUpdated())
  {
    Serial.print(" latitude = ");
        Serial.print(gps.location.lat(),6);
            Serial.print(" longitude = ");
        Serial.println(gps.location.lng(),6);
    
    }
  
  
  
  }
}
