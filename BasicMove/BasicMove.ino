#include <Grove_I2C_Motor_Driver.h>

//I2C adress of the Motor Driver
#define I2C_ADDRESS 0x0f

void setup() {
  Motor.begin(I2C_ADDRESS);
  Serial.begin(9600);
  unsigned char motor_id = "";
  int _speed = 0;
}

void loop() {
  void speed(motor_id, _speed);
  delay(1000);
  void stop(motor_id);
}
