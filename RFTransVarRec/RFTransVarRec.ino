#include <VirtualWire.h>
#include <VirtualWire_Config.h>

void setup() {
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_rx_pin();
  vw_rx_start();
}

void loop() {
  float msg;
  byte msg_length = sizeof(float);
  
  vw_wait_rx();
  
  if(vw_get_message((byte *) &msg, &msg_length))
    Serial.println(msg);
}
