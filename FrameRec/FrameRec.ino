#include <VirtualWire.h>
#include <VirtualWire_Config.h>

#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */
#define WIDTH  8
#define TOPBIT 128

uint8_t  crcTable[256];

void setup() {
  Serial.begin(9600);
  crcInit();
  vw_setup(1500);
  vw_set_rx_pin(7);
  vw_rx_start();
}

void loop() {
  uint8_t msg[6];
  uint8_t msg_len = 6;

  vw_wait_rx();

  if(vw_get_message(msg, &msg_len) && msg[0] == 7)
    for(byte i = 2; i < 5; i++) msg[i] = rot127(msg[i]);
  
  Serial.println(msg[2]);
  Serial.println((char)msg[3]);
  Serial.println((char)msg[4]);
    
}


void crcInit() { 
  uint8_t  remainder;

  for (int dividend = 0; dividend < 256; ++dividend) {
    remainder = dividend << (WIDTH - 8);

    for (uint8_t bit = 8; bit > 0; --bit) (remainder & TOPBIT) ? remainder = (remainder << 1) ^ POLYNOMIAL : remainder = (remainder <<1);

    crcTable[dividend] = remainder;
  }
}


uint8_t crcExec(uint8_t message[], byte nBytes) { 
  uint8_t data;
  uint8_t remainder = 0;

  for (byte byteNum = 0; byteNum < nBytes; ++byteNum) {
    data = message[byteNum] ^ (remainder >> (WIDTH - 8));
    remainder = crcTable[data] ^ (remainder << 8);
  }
  
  return (remainder);  
}


uint8_t rot127(uint8_t clearVal) {
  uint8_t rotVal;
  rotVal = clearVal;
  
  if(rotVal != 0 && rotVal != 128) rotVal = (rotVal <=128) ? rotVal +127 : rotVal -127;
  else if(rotVal == 0 || rotVal == 128) rotVal = (rotVal == 0) ? rotVal +128 : rotVal -128;

  return(rotVal);
}
