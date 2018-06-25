#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <VirtualWire.h>
#include <VirtualWire_Config.h>


class Protocol {
	public:
		Protocol();
		~Protocol();

		void sendFrame();
		void receiveFrame();
		void writeFrame();
		void readFrame();

		void checksum();
		void rot47();
};

#endif
