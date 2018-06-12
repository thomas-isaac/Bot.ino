//------------------------------------------------------------
//Name: Line finder digital mode
//Function: detect black line or white line for two sensors
//Parameter:   When digital signal is HIGH, black line
//             When digital signal is LOW, white line
//-------------------------------------------------------------
int signalPin3 = 3;    // connected to digital pin 3
int signalPin5 = 5;    // connected to digital pin 5

void setup()   {
  pinMode(signalPin3, INPUT); // initialize the digital pin as an output
  pinMode(signalPin5, INPUT); // initialize the digital pin as an output
  Serial.begin(9600);  // initialize serial communications at 9600 bps:
}
// the loop() method runs over and over again,
// as long as the Arduino has power
void loop()
{ 
  Serial.println("Input: \n");
  if(HIGH == digitalRead(signalPin3))
    Serial.println("1. black ");      // display the color when signal is High
  else  Serial.println("1. white ");  // display the color when signal is not High
  
  if(HIGH == digitalRead(signalPin5))
    Serial.println("2. black");
  else  Serial.println("2. white");
  
  delay(1000);                  // wait for a second
}
