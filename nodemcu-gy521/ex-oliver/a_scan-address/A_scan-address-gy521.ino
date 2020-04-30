#include "Wire.h"

 // pino I2C SDA D2
 // pino I2C SCL D1

// PIN SDO = LOW
const int MPU_addr_A = 0x68; // I2C address of the MPU-6050

// PIN SDO = HIGH
const int MPU_addr_B = 0x69; // I2C address of the MPU-6050

void setup()
{
    Wire.begin();

    Serial.begin(115200);
}

void loop()
{
    byte error;
    
    Wire.beginTransmission(MPU_addr_A);
    error = Wire.endTransmission();

    if (error == 0)
    {
        Serial.println("Dispositivo 0x68 encontrado");
    }
    else
    {
        Serial.println("Dispositivo 0x68 não encontrado");
    }
     
    Wire.beginTransmission(MPU_addr_B);
    error = Wire.endTransmission();

    if (error == 0)
    {
        Serial.println("Dispositivo 0x69 encontrado");
    }
    else
    {
        Serial.println("Dispositivo 0x69 não encontrado");
    }

    delay(5000); // Wait 5 seconds and scan again
}