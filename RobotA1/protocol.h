#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <VirtualWire.h>
#include <VirtualWire_Config.h>
#include "define.h"

#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */
#define WIDTH  8
#define TOPBIT 128


class Protocol {
public:
  Protocol();
  ~Protocol();

  void init();

  void sendFrame(const float &botSpeed, const int &_ptA, const int &_ptB);
  void writeFrame(const float &botSpeed, const int &_ptA, const int &_ptB);

  void crcInit();
  uint8_t crcExec(uint8_t message[], byte nBytes);

  uint8_t rot127(uint8_t clearVal);

private:

  uint8_t  crcTable[256];
  uint8_t frame[6];
};

#endif

