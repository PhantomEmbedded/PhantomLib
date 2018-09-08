#ifndef SERIAL_H
#define SERIAL_H

#include <SerialTransceiver.h>

namespace Serial
{
	enum Rate : uint32_t
	{
		bps2400 = 2400,
		bps4800 = 4800, 
		bps9600 = 9600,
		bps14400 = 14400,
		bps19200 = 19200,
		bps28800 = 28800,
		bps38400 = 38400,
		bps57600 = 57600,
		bps76800 = 76800,
		bps115200 = 115200,
		bps230400 = 230400,
		bps250000 = 250000,
		bps500000 = 500000,
		bps1000000 = 1000000
	};

	const Transceiver A = {&UDR0, {&UCSR0A, &UCSR0B, &UCSR0C}, {&UBRR0L, &UBRR0H}};
}

#endif
