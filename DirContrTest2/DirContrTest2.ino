#include <Grove_I2C_Motor_Driver.h>
#include <Wire.h>
#define i2c_add 0x0f

byte i, j, dir;

int signalPin2 = 2;
int signalPin3 = 3;
int signalPin4 = 4;


void setup() {
  pinMode(signalPin2, INPUT); // Init each pin with INPUT mode
  pinMode(signalPin3, INPUT); // (default mode)
  pinMode(signalPin4, INPUT);

  Motor.begin(i2c_add);
  upSpeed(100, 100); // Init speed move forward 
}

void loop() {
  
  for(dir=0, i=2, j=1; i<5; i++, j <<= 1) { // Read each pin INPUT (2-5)
    if(digitalRead(i) == HIGH) // Some sort of bit shift logic
      dir += j;
  }
  
  switch (dir) { // A bit shameful

    case 0: //No line detected - Keep going for some time
     upSpeed(100, 100);
    break;
    
    case 1: // Line on the right - Adjust to the right
     upSpeed(100, 50);
    break;
    
    case 2: // Line in the middle - Keep going
     upSpeed(100, 100);
     delay(100);
    break;
    
    case 3: // Line on both right and mid - Turn right
     delay(280);
     upSpeed(0, 0);
     upSpeed(100, -80);
     delay(800);
    break;
    
    case 4: // Line on the left - Adjust to the left
     upSpeed(50, 100);
     delay(100);
    break;
    
    case 5: // Line on both right and left - Everything's fine..
     upSpeed(100, 100);
    break;
    
    case 6: // Line on both left and mid - Turn left
     delay(280);
     upSpeed(0, 0);
     upSpeed(-80, 100);
     delay(800);
    break;
    
    case 7: // Line on left, right and mid - Merry Christmas
     delay(280);
     upSpeed(0, 0);
     upSpeed(-80, 100);
     delay(800);
    break;
  }
  
  delay(10); // Operate with a 10ms delay
}

void upSpeed(int M1, int M2) {
  Motor.speed(MOTOR1, M1);
  Motor.speed(MOTOR2, -M2);
}
