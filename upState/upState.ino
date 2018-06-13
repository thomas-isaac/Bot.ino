#include <Grove_I2C_Motor_Driver.h>
#include <Wire.h>
#define i2c_add 0x0f

byte i,j;
int speed1 = 0;
int speed2 = 0;

int signalPin2 = 2;
int signalPin3 = 3;
int signalPin4 = 4;

void setup() {
  pinMode(signalPin2, INPUT); // Init each pin with INPUT mode
  pinMode(signalPin3, INPUT); // (default mode)
  pinMode(signalPin4, INPUT);
  
  Motor.begin(i2c_add);
}

void loop() {
  
  for(i=2; i<5; i++) { // Read each pin INPUT (2-5)
    if(digitalRead(i) == HIGH)
      upState();
  }
  
  if(speed1 < 0 && speed2 < 0)
    speed1 = speed2 = 0;
  else if(speed1 < 0 && speed2 > 0)
    speed1 = speed2;
  else if(speed1 > 0 && speed2 < 0)
    speed2 = speed1;

  Motor.speed(MOTOR1, speed1);
  Motor.speed(MOTOR2, speed2);
  
  delay(1);
}

void upState() {
  switch (i) {
    case 2:
     upSpeed(-10, 10);
    break;
    
    case 3:
     upSpeed(10, 10);
    break;
    
    case 4:
     upSpeed(10, -10);
    break;
  }
}

void upSpeed(int M1, int M2) {
 speed1 += M1;
 
 if(speed1 >= 100)
   speed1 = 100;
 else if(speed1 <= -100)
   speed1 = -100;
   
 speed2 += M2;
 
  if(speed2 >= 100)
   speed2 = 100;
 else if(speed2 <= -100)
   speed2 = -100;
}
