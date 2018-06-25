#include <VirtualWire.h>
#include <VirtualWire_Config.h>

void setup() {
  Serial.begin(9600);
  vw_setup(1500);
  vw_set_rx_pin(7);
  vw_rx_start();
}

void loop() {
  uint8_t msg[VW_MAX_MESSAGE_LEN];
  uint8_t msg_len = VW_MAX_MESSAGE_LEN;
  
  vw_wait_rx();
  
  if(vw_get_message(msg, &msg_len)){
    byte i;
    
    for(i = 0; i < msg_len; i++)
     Serial.println((char)msg[i]);
  }
}
