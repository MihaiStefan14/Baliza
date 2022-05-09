
#include <VirtualWire.h> 
#include <SoftwareSerial.h>
const int led_pin = 4; 
int Buzzer = 8; // The buzzer simulates the car's horn
int LED = 13; // The LED simulates the car's lamp
int note = 1950;  // Set the time the buzzer's note 
const int BTRX = 10;
const int BTTX = 11;
SoftwareSerial SerialBT(BTRX, BTTX);
void setup()  
{  
  pinMode(LED, OUTPUT); // Set up the LED pin to be an output
   pinMode(Buzzer, OUTPUT); // Set up the buzzer pin to be an output
   SerialBT.begin(9600);
   SerialBT.println("Bluetooth cod");
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
   digitalWrite(led_pin, HIGH); 
   SerialBT.println("S O S");
  
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
