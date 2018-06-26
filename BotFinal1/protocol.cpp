#include "protocol.h"

uint8_t  crcTable[256];
uint8_t data[2] = {42, 43};
uint8_t frame[5];

Protocol::Protocol() {}
Protocol::~Protocol() {}


void Protocol::sendFrame() {
  vw_set_tx_pin(8);
  vw_setup(1500);

  vw_send(frame, strlen((char*)frame));
  vw_wait_tx();
}


void Protocol::receiveFrame() { }


void Protocol::writeFrame() {
  uint8_t dst = 7;
  uint8_t src = 7;
  uint8_t checksum;
  uint8_t i;
  
  frame[0] = dst;
  frame[1] = src;
  
  for(i=0; i <=sizeof(data); i++) frame[i+2] = rot127(data[i]);
  
  if(!crcTable) crcInit();
  checksum = crcExec(frame, sizeof(frame));
  frame[i+1]= checksum;
}


void Protocol::readFrame() { }




void Protocol::crcInit() { 
  uint8_t  remainder;

  for (uint8_t dividend = 0; dividend < 256; ++dividend) {
    remainder = dividend << (WIDTH - 8);

    for (uint8_t bit = 8; bit > 0; --bit) (remainder & TOPBIT) ? remainder = (remainder << 1) ^ POLYNOMIAL : remainder = (remainder <<1);

    crcTable[dividend] = remainder;
  }
}


uint8_t Protocol::crcExec(uint8_t message[], byte nBytes) { 
  uint8_t data;
  uint8_t remainder = 0;

  for (byte byteNum = 0; byteNum < nBytes; ++byteNum) {
    data = message[byteNum] ^ (remainder >> (WIDTH - 8));
    remainder = crcTable[data] ^ (remainder << 8);
  }
  
  return (remainder);  
}


uint8_t Protocol::rot127(uint8_t clearVal) {
  uint8_t rotVal;
  rotVal = (rotVal <=128) ? rotVal +127 : rotVal -127;
  return(rotVal);
}
