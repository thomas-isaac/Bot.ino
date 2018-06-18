# Robot Controller

This simple program allows a robot to move and follow a line. It gets the sensors input and behaves accordingly.
It is based on the Grove I2C Motor Driver to controle the motors speed.

# Usage

The program is ready to you use.
The switch cases can be modified to change the speed used for each move, though they are already optimized.

# Functionnalities

The program is divided into three basic functions.

**init()** Initializes the robot by starting the I2C Motor Driver located at a defined address

**run()** The main function, contains the for loop to get and store the sensors input as well as the switch case to process it. 

**upSpeed()** Receives two speeds as parameter and calls the Motor Driver speed function accordingly.
