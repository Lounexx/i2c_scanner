// Connexion afficheur LCD et affichage de ARDUINO Bonjour !
 
#include <Wire.h>
 
 
void setup()
{  
  Wire.begin();
  Serial.begin(9600);
  Serial.println("\nI2C Scanner");
}

 
void loop()
{
  byte error, address;
  int nDevices;
  Serial.println("Scanning...");
  nDevices = 0;
  for(address = 1; address < 127 ; address++){
    Wire.beginTransmission(address);
    error = Wire.endTransmission() ;
    if(error == 0){
      Serial.print("I2C device found at address 0x");
      if(address<16){
        Serial.print("0");
      }
      Serial.print(address,HEX);
      Serial.print(" !");
      nDevices++;
      }else if(error==4){
        Serial.print("Unknown at address 0x");
        if(address<16){
          Serial.print("0");
        }
       Serial.println(address,HEX);
      }
    }
    if(nDevices == 0){
     Serial.println("NO I2C DEVICE FOUND"); 
    }else {
      Serial.println("Done.");
    }
    delay(5000);
 
}
