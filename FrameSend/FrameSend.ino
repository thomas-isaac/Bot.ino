#include <VirtualWire.h>
#include <VirtualWire_Config.h>

#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */
#define WIDTH  8
#define TOPBIT 128

uint8_t  crcTable[256];
uint8_t frame[6];

void setup() {
  Serial.begin(9600);
}

void loop() {
  sendFrame();
}

void sendFrame() {
  writeFrame();
  vw_set_tx_pin(8);
  vw_setup(1500);

  vw_send(frame, strlen((char*)frame));
  vw_wait_tx();
}


void writeFrame() {
  uint8_t i;
  
  frame[0] = 7; // DST
  frame[1] = 7; // SRC
  frame[2] = 80;
  frame[3] = 65;
  frame[4] = 66;
  
  for(i=2; i < sizeof(frame) -1; i++) frame[i] = rot127(frame[i]);

  if(!crcTable) crcInit();
  frame[i+1]= crcExec(frame, sizeof(frame));;
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
