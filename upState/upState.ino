#include <Grove_I2C_Motor_Driver.h>
#include <Wire.h>
#define i2c_add 0x0f

byte i, j, k;

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
  
  for(j=0, i=2; i<5; i++, j++) { // Read each pin INPUT (2-5)
    if(digitalRead(i) == HIGH)
      j++;
      upState();
  }
  
  if(j == 0)
    j = k;
  else
    k = j;
  
  speed1 = speed1 / j;
  speed2 = speed2 / j;
  
  Motor.speed(MOTOR1, speed1);
  Motor.speed(MOTOR2, speed2);
  
  if(j != 0) {
  speed1 = 0;
  speed2 = 0;
  }
  
  delay(1);
}

void upState() {
  switch (i) {
    case 2:
     upSpeed(-100, 100);
    break;
    
    case 3:
     upSpeed(100, 100);
    break;
    
    case 4:
     upSpeed(100, -100);
    break;
  }
}

void upSpeed(int M1, int M2) {
 speed1 += M1;
 speed2 += M2;
}
