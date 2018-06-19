#include <VirtualWire.h>

void setup() {
	Serial.begin(9600);
	vw_setup(2000);
}

void loop(){
	byte message[VW_MAX_MESSAGE_LEN];
	int len = Serial.readBytesUntil('\n', (char*) message, VW_MAX_MESSAGE_LEN - 1);
	
	if(!len) return;

	message[len] = '\0';

	vw_send(message, len +1);
	vw_wait_tx;

}
