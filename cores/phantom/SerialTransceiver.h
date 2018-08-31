#ifndef SERIAL_TRANSCEIVER_H
#define SERIAL_TRANSCEIVER_H

#include <Serial.h>

class SerialTransceiver
{
public:
	enum OperatingMode
	{
		AsyncNormal = 16,
		AsyncDoubleSpeed = 8,
		SyncMaster = 2 
	};

	SerialTransceiver(Serial::Transceiver transceiver, Serial::Rate rate);
	SerialTransceiver(Serial::Transceiver transceiver, Serial::Rate rate, OperatingMode mode);

	void initialize();

	void set_operating_mode(OperatingMode new_mode);

	void transmit(uint8_t data);

	void receive();
	void peek();

private:
	const Serial::Transceiver transceiver;
	Serial::Rate rate;
	OperatingMode mode;
};

#endif
