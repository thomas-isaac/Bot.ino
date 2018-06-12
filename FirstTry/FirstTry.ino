#include <Grove_I2C_Motor_Driver.h>
#include <Wire.h>
#define i2c_add 0x0F




void setup() {
  Motor.begin(i2c_add);
}

void loop() {
 int _speed1 = 100; // wheels won't rotate under 50 speed
 int _speed2 = -100; 
 Motor.speed(MOTOR1, _speed1);
 Motor.speed(MOTOR2, _speed2);
 delay(1389);
 Motor.stop(MOTOR1);
 Motor.stop(MOTOR2);
 exit(0);

}
