#include <TinyGPS++.h>
#include <VirtualWire.h> 
#include <SoftwareSerial.h>
int Buzzer = 8; 
int LED = 13; 
int note = 1950;   
const int BTRX = 10;
const int BTTX = 11;
const int DO = 12; 

float sensor_volt; 
float Gaz; 
float ratio; 
float R0 = 0.91; 

TinyGPSPlus gps;

SoftwareSerial SerialBT(BTRX, BTTX);
void setup()  
{  
  pinMode(LED, OUTPUT); 
   pinMode(Buzzer, OUTPUT); 
   SerialBT.begin(9600);
   pinMode(DO, INPUT); 
}  

void flash(int duration)
{
digitalWrite(LED, HIGH);
delay(duration);
digitalWrite(LED, LOW);
delay(duration);

}
void loop()  
{  

  int sensorValue = analogRead(A0); 
  sensor_volt = ((float)sensorValue / 1024) * 5.0; 
  Gaz = (5.0 - sensor_volt) / sensor_volt;
  ratio = Gaz / R0; // ratio = RS/R0 
  
   SerialBT.println("S O S");
  SerialBT.print("voltaj=");
  SerialBT.println(sensor_volt);
  SerialBT.print("ratie=");
  SerialBT.println(Gaz);
  SerialBT.print("Rs/R0=");
  SerialBT.println(ratio);
  SerialBT.print("\n");

  for (int i=0; i<3; i++)
  {
    flash(200);
    tone(Buzzer, note, 200);
    delay(100); 
  }
  delay(1000);
  
  for (int i=0; i<3; i++)
  {
    flash(600);
    tone(Buzzer, note, 600);
    delay(100);
  }
  delay(1000);
   
  for (int i=0; i<3; i++)
  { flash(200);
    tone(Buzzer, note, 200);
    delay(100);
  }
  delay(1000);
}  
