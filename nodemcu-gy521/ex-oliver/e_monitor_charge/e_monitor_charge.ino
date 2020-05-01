#include "MPU6050.h"

ADC_MODE(ADC_VCC);

const uint8_t MPU_addr = 0x68; // I2C address of the MPU-6050

const float calibVCC = 0.00118467153; // Calibration based on measurement

MPU6050 testUnit(MPU_addr);

const uint8_t threshold = 20; // Adjust to change sensitivity to acceleration
const uint8_t duration = 10;  // Adjust to change duration of motion to trigger interrupt

void setup()
{
    Wire.begin();
    disableMotionInt();
    Serial.begin(115200);
    setup_wifi();

    Serial.println("I'm Awake!");
    Serial.print("Motion detect Status : ");
    Serial.println(testUnit.getMotionStatus(), BIN);

    float getVcc = ESP.getVcc() * calibVCC;
    Serial.print("Supply Voltage : ");
    Serial.print(getVcc, 4);
    Serial.println(" V ");
    Serial.println("Going to sleep. . .");
    enableMotionInt();
    ESP.deepSleep(0);
}

void loop()
{
}

void setup_wifi()
{

    delay(10);
    Serial.println();
    delay(500);
    Serial.print(".");
}

void disableMotionInt()
{
    // Ensure the accelerometer is running
    testUnit.setSleepEnabled(false);
    testUnit.setWakeCycleEnabled(false);
    testUnit.setStandbyXAccelEnabled(false);
    testUnit.setStandbyYAccelEnabled(false);
    testUnit.setStandbyZAccelEnabled(false);
}
void enableMotionInt()
{
    testUnit.initialize();
    testUnit.testConnection();

    // Ensure the accelerometer is running
    testUnit.setSleepEnabled(false);
    testUnit.setWakeCycleEnabled(false);
    testUnit.setStandbyXAccelEnabled(false);
    testUnit.setStandbyYAccelEnabled(false);
    testUnit.setStandbyZAccelEnabled(false);

    //Set the accelerometer HPF to reset settings
    testUnit.setDHPFMode(MPU6050_DHPF_RESET);

    //Set the accelerometer LPF to 256Hz Bandwidth
    testUnit.setDLPFMode(MPU6050_DLPF_BW_256);

    //Enable the motion interrupt
    testUnit.setIntEnabled(0b00000000);
    testUnit.setIntMotionEnabled(true);

    //Set the motion detection duration
    testUnit.setMotionDetectionDuration(duration); //Duration in ms

    //Set the motion detection threshold
    testUnit.setMotionDetectionThreshold(threshold); // Threshold in 2mg

    //1 ms delay
    delay(1);

    //Set the accelerometer HPF to HOLD settings
    testUnit.setDHPFMode(MPU6050_DHPF_HOLD);

    // Set the wakeup frequency
    testUnit.setWakeFrequency(MPU6050_WAKE_FREQ_5);
    testUnit.setStandbyXGyroEnabled(true);
    testUnit.setStandbyYGyroEnabled(true);
    testUnit.setStandbyZGyroEnabled(true);

    // Enable cycle mode
    testUnit.setWakeCycleEnabled(true);

    testUnit.setInterruptLatch(0);
    testUnit.setInterruptLatchClear(0);
    testUnit.setInterruptDrive(0);
    testUnit.setInterruptMode(1);
}