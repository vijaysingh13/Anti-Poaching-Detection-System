
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TinyGPS.h>
TinyGPS gps;
WidgetMap myMap(V0);  // V0 for virtual pin of Map Widget
float lat , lon;
char auth[] = "5bLmz1qKpBXruD1TIERF-HSYHqUOnaLl";
char ssid[] ="Samsung GalaxyA21s";
char pass[] = "123456789";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
void loop()
{
  Blynk.run();
  getLocation();
}



void getLocation(){
  
  while(Serial.available()){
    int c=Serial.read();
    if(gps.encode(c)){
      gps.f_get_position(&lat,&lon);
    }
  }
  Serial.println(lat);
   Blynk.virtualWrite(V1, lat );
  Serial.println(lon);
   Blynk.virtualWrite(V2, lon);
   myMap.location(1,lat,lon,"My Location");
  
}
