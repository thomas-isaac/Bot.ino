#include "protocol.h"


Protocol::Protocol() {
}
Protocol::~Protocol() {
}

void Protocol::init()
{  
  vw_set_tx_pin(8);
  vw_setup(1500);

  crcInit();
}


void Protocol::sendFrame(const float &botSpeed, const int &_ptA, const int &_ptB) {
  this->writeFrame(botSpeed, _ptA, _ptB);

  vw_send(frame, strlen((char*)frame));
  vw_wait_tx();
  
  Serial.println("send");
}


void Protocol::writeFrame(const float &botSpeed, const int &_ptA, const int &_ptB) {
  Serial.print("writeFrame : ");
  Serial.print(botSpeed);
  Serial.print(" ");
  Serial.print(_ptA);
  Serial.print(" ");
  Serial.print(_ptB);
  Serial.println(" ");
  
  uint8_t i;

  frame[0] = 7; // DST
  frame[1] = 7; // SRC
  frame[2] = (uint8_t)(botSpeed*100);
  frame[3] = (uint8_t)_ptA+65;
  frame[4] = (uint8_t)_ptB+65;

  for(i=2; i <=sizeof(frame)-2; i++) frame[i] = rot127(frame[i]);

  frame[i+1]= crcExec(frame, sizeof(frame));
}


void Protocol::crcInit() { 
  uint8_t  remainder;

  for (int dividend = 0; dividend < 256; ++dividend) {
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
  rotVal = clearVal;

  if(rotVal != 0 && rotVal != 128) rotVal = (rotVal <=128) ? rotVal +127 : rotVal -127;
  else if(rotVal == 0 || rotVal == 128) rotVal = (rotVal == 0) ? rotVal +128 : rotVal -128;

  return(rotVal);
}

