#include <VirtualWire.h>
#include <VirtualWire_Config.h>

#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */
#define WIDTH  8
#define TOPBIT 128

uint8_t frame[6];

uint8_t dst = 7;
uint8_t src = 7;

uint8_t data[2] = {42, 43};
uint8_t checksum;

byte i;
byte j;

void crcInit();

void setup() {
  Serial.begin(9600);
  vw_set_tx_pin(8);
  vw_setup(1500);
}

void loop() {
  frame[0] = dst;
  frame[1] = src;
  
  for(i=0; i <=sizeof(data); i++){
    frame[i+2] = rot47(data[i]);
  }

  crcInit();
  checksum = crcFast(frame, sizeof(frame));
  frame[i+1]= checksum;
  
  for(j = 0; j < i+2;j++)
  Serial.println(frame[j]);
  
  vw_send(frame, strlen((char*)frame));
  vw_wait_tx();
}

uint8_t rot47(uint8_t var) {
  var = (var <=128) ? var +127 : var -127;
  return(var);
}

uint8_t  crcTable[256];

void crcInit() {
  uint8_t  remainder;

  for (int dividend = 0; dividend < 256; ++dividend) {
    remainder = dividend << (WIDTH - 8);

    for (uint8_t bit = 8; bit > 0; --bit) (remainder & TOPBIT) ? remainder = (remainder << 1) ^ POLYNOMIAL : remainder = (remainder <<1);

    crcTable[dividend] = remainder;
  }

}

uint8_t crcFast(uint8_t message[], int nBytes)
{
    uint8_t data;
    uint8_t remainder = 0;

    for (byte byteNum = 0; byteNum < nBytes; ++byteNum) {
        data = message[byteNum] ^ (remainder >> (WIDTH - 8));
        remainder = crcTable[data] ^ (remainder << 8);
    }

    return (remainder);
}



