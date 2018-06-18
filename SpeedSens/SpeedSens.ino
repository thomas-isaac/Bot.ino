#define WCIRCONF 396 // Circonference of the wheel in mm
#define WSENS 5 // Wheel sensor digital pin


int i = 0;
int wSpeed;
int initTime;

bool transition;


void setup() {
}

void loop() {
	if(transition != digitalRead(WSENS)) {
		if(i = 0)
			initTime = millis();
		
		i++;
		transition = digitalRead(WSENS);

		if(i = 20) {
			i = 0;
			wSpeed = WCIRCONF / (millis() - initTime);
			Serial.println(wSpeed);
		}
	}
}
