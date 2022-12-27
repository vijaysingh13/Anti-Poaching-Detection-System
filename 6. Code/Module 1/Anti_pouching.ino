#define BLYNK_PRINT DebugSerial
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

char auth[] = "XOJg_UHTwCRrdgclgPjSFsvb4zov0cp4";


int x = A1;
int relay = 5;
int Fire_pin= 7;
int buzzer = 6;
int val;
//int relay;

void setup()
{
  // Debug console
  DebugSerial.begin(9600);
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  pinMode(x,INPUT);
  pinMode(Fire_pin,INPUT);
  pinMode(buzzer,OUTPUT);
   pinMode(relay,OUTPUT);
}

void loop()
{
  Blynk.run();
  fire_status();
  acceleration();
  
   
}

void acceleration() {
  int val = analogRead(x);
  Blynk.virtualWrite(V7, val);
  if (val < 287) {
    Blynk.virtualWrite(V8, "Accel");
   digitalWrite(buzzer, HIGH);
  } else {
    Blynk.virtualWrite(V8, ".........");
    digitalWrite(buzzer, LOW);
  }
}

void fire_status(){
  if(digitalRead(Fire_pin)){
    Blynk.virtualWrite(V3, "Fire is detected");
  }else{
    Blynk.virtualWrite(V3, "..........");
  }
}

 


BLYNK_WRITE(V5) {
  int val = param.asInt();
  if (val) {
    Blynk.virtualWrite(V5, "ON");
    digitalWrite(relay, HIGH);
  } else {
    Blynk.virtualWrite(V5, ".....");
    digitalWrite(relay, LOW);
  }
}
