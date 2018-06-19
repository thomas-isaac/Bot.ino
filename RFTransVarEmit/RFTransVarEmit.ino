#include <VirtualWire.h>
#include <VirtualWire_Config.h>

void setup() {
  vw_setup(2000);
  vw_set_tx_pin(8);
}

void loop() {
  float msg = 1234;
  
  vw_send((byte *) &msg, sizeof(msg));
  vw_wait_tx();
}
