#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */
#define WIDTH  8
#define TOPBIT 128

String frame;

unsigned int dst = 70;
unsigned int src = 7;

uint8_t data[] = {42, 43,};
uint8_t checksum;

void setup() {
  Serial.begin(9600);
}

void loop() {
  frame += dst;
  frame += src;
  
  for(byte i =0; i <sizeof(data); i++){
    data[i] = rot47(data[i]);
    frame += data[i];
  }

  crcInit();
  checksum = crcFast(data, sizeof(data));
  frame += checksum;

  Serial.println(frame);
}

char rot47(uint8_t var) {
  var = (126 -var <=47) ? var -47 : var +47;
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

    for (int byte = 0; byte < nBytes; ++byte) {
        data = message[byte] ^ (remainder >> (WIDTH - 8));
        remainder = crcTable[data] ^ (remainder << 8);
    }

    return (remainder);
}



