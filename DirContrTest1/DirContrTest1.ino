#include <Grove_I2C_Motor_Driver.h>
#include <Wire.h>
#define i2c_add 0x0f

byte i, j, dir;

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
  Motor.speed(MOTOR1, 100); // Init move forward full speed 
  Motor.speed(MOTOR2, -100);
}

void loop() {
  
  for(dir=0, i=2, j=1; i<5; i++, j <<= 1) { // Tests each pin (2-5)
    if(digitalRead(i) == HIGH) // Some sort of bit shift logic
      dir += j;
  }
  
  switch (dir) { // A bit shameful

    case 0: //No line detected - Stop both motors
     Motor.speed(MOTOR1, 100);
     Motor.speed(MOTOR2, -100);
    break;
    
    case 1: // Line on the right - Adjust to the right
     Motor.speed(MOTOR1, 100);
     Motor.speed(MOTOR2, -75);
    break;
    
    case 2: // Line in the middle - Keep going
     Motor.speed(MOTOR1, 100); 
     Motor.speed(MOTOR2, -100);
    break;
    
    case 3: // Line on both right and mid - Turn right
     delay(230);
     Motor.speed(MOTOR1, 0); 
     Motor.speed(MOTOR2, 0);
     Motor.speed(MOTOR1, 100);
     Motor.speed(MOTOR2, 50);
     delay(500);
    break;
    
    case 4: // Line on the left - Adjust to the left
     Motor.speed(MOTOR1, 75); 
     Motor.speed(MOTOR2, -100);
    break;
    
    case 5: // Line on both right and left - Everything's fine..
     Motor.speed(MOTOR1, 100); 
     Motor.speed(MOTOR2, -100);
    break;
    
    case 6: // Line on both left and mid - Turn left
     delay(230);
     Motor.speed(MOTOR1, 0); 
     Motor.speed(MOTOR2, 0);
     Motor.speed(MOTOR1, -50);
     Motor.speed(MOTOR2, -100);
     delay(500);
    break;
    
    case 7: // Line on left, right and mid - Merry Christmas
     Motor.speed(MOTOR1, 100); 
     Motor.speed(MOTOR2, -100);
    break;
  }
  
  delay(10); // Operate with a 10ms delay
}
