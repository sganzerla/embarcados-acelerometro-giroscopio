#include <Wire.h>
 
const uint8_t MPU_addr=0x68; // I2C address of the MPU-6050
 
struct STREG {
uint8_t reg_13;
uint8_t reg_14;
uint8_t reg_15;
uint8_t reg_16;
} stRegs;
 
void readSelfTestRegisters(byte addr, STREG &RegsIn,bool Debug);
void check_I2c(byte addr);
 
void setup() {
Wire.begin();
Serial.begin(115200);
 
Wire.beginTransmission(MPU_addr);
Wire.write(0x6B); // PWR_MGMT_1 register
Wire.write(0); // set to zero (wakes up the MPU-6050)
Wire.endTransmission(true);
}
 
void loop() {
 
// Read Factory Trim Settings
readSelfTestRegisters(MPU_addr, stRegs,true);
delay(5000); // Wait 5 seconds and scan again
}
 
void check_I2c(byte addr){
// We are using the return value of
// the Write.endTransmisstion to see if
// a device did acknowledge to the address.
byte error;
Wire.beginTransmission(addr);
error = Wire.endTransmission();
Serial.println(" ");
if (error == 0)
{
Serial.print(" Device Found at 0x");
Serial.println(addr,HEX);
}
else
{
Serial.print(" No Device Found at 0x");
Serial.println(addr,HEX);
}
}
 
void readSelfTestRegisters(byte addr, STREG &RegsIn,bool Debug){
// This function reads the self test registers and stores them in RegsIn
// If Debug is true then it sends the contents of the registers to the serial port
 
Wire.beginTransmission(addr);
Wire.write(0x0D); // starting with register 0x0D (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(addr,4,true); // request a total of 4 registers
RegsIn.reg_13=Wire.read();
RegsIn.reg_14=Wire.read();
RegsIn.reg_15=Wire.read();
RegsIn.reg_16=Wire.read();
 
if(Debug){
Serial.print("Register 13 = "); Serial.print(RegsIn.reg_13,BIN);
Serial.print(" | Register 14 = "); Serial.print(RegsIn.reg_14,BIN);
Serial.print(" | Register 15 = "); Serial.print(RegsIn.reg_15,BIN);
Serial.print(" | Register 16 = "); Serial.println(RegsIn.reg_16,BIN);
}
}