// MPU6050 & Servo
// http://www.giuseppecaccavale.it/
// Giuseppe Caccavale

#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#define MPU 0x68 // I2C address of the MPU-6050

Servo ServoX, ServoY;
double AcX, AcY, AcZ;
int Pitch, Roll;

void setup()
{
    Serial.begin(115200);
    ServoX.attach(D5);
    ServoY.attach(D6);
    init_MPU(); // Inizializzazione MPU6050
}

void loop()
{
    FunctionsMPU(); // Acquisisco assi AcX, AcY, AcZ.

    Roll = FunctionsPitchRoll(AcX, AcY, AcZ);  //Calcolo angolo Roll
    Pitch = FunctionsPitchRoll(AcY, AcX, AcZ); //Calcolo angolo Pitch

    int ServoRoll = map(Roll, -90, 90, 0, 179);
    int ServoPitch = map(Pitch, -90, 90, 179, 0);

    ServoX.write(ServoRoll);
    ServoY.write(ServoPitch);

    Serial.print("Pitch: ");
    Serial.print(Pitch);
    Serial.print("\t");
    Serial.print("Roll: ");
    Serial.print(Roll);
    Serial.print("\n");
}

void init_MPU()
{
    Wire.begin();
    Wire.beginTransmission(MPU);
    Wire.write(0x6B); // PWR_MGMT_1 register
    Wire.write(0);    // set to zero (wakes up the MPU-6050)
    Wire.endTransmission(true);
    delay(1000);
}

//Funzione per il calcolo degli angoli Pitch e Roll
double FunctionsPitchRoll(double A, double B, double C)
{
    double DatoA, DatoB, Value;
    DatoA = A;
    DatoB = (B * B) + (C * C);
    DatoB = sqrt(DatoB);

    Value = atan2(DatoA, DatoB);
    Value = Value * 180 / 3.14;

    return (int)Value;
}

//Funzione per l'acquisizione degli assi X,Y,Z del MPU6050
void FunctionsMPU()
{
    Wire.beginTransmission(MPU);
    Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H)
    Wire.endTransmission(false);
    Wire.requestFrom(MPU, 6, true);       // request a total of 14 registers
    AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
    AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
    AcZ = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
}