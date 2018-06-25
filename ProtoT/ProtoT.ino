#include <VirtualWire.h>
#include <VirtualWire_Config.h>

void setup() {
  vw_set_tx_pin(8);
  vw_setup(1500);
}

void loop() {
  const char *msg = "hello";
  
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx();
}
