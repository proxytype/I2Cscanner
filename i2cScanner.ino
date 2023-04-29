// I2C address scanner program
#include <Wire.h>

#define MAX_ADDRESS 127

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Device Scanners");
}

void loop()
{
  byte error, address;
  int devices;

  Serial.println("Scanning...");

  devices = 0;
  for(address = 1; address < MAX_ADDRESS; address++ )
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");

      Serial.print(address,HEX);
      Serial.println("  !");

      devices++;
    }
    else if (error==4)
    {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");

      Serial.println(address,HEX);
    } else {
      Serial.print("I2C device not found in address 0x");
      Serial.println(address,HEX);
    }
  }

  if (devices == 0)
    Serial.println("No I2C devices found in range");
  else
    Serial.println("done");

  delay(5000); // wait 5 seconds for next scan
}