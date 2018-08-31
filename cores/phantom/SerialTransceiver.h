#ifndef SERIAL_TRANSCEIVER_H
#define SERIAL_TRANSCEIVER_H

#include <Serial.h>

class SerialTransceiver
{
public:
	enum OperatingMode: uint8_t
	{
		AsyncNormal = 16,
		AsyncDoubleSpeed = 8,
		SyncMaster = 2 
	};

	enum ParityMode: uint8_t
	{
		Disabled = 0b00,
		EvenParity = 0b10,
		OddParity = 0b11
	};

	enum StopBits: bool
	{
		Bit1 = 0,
		Bit2 = 1
	};

	enum DataBits: uint8_t
	{
		Bit5 = 0b000,
		Bit6 = 0b001,
		Bit7 = 0b010,
		Bit8 = 0b011,
		Bit9 = 0b111
	};

	SerialTransceiver(Serial::Transceiver transceiver, Serial::Rate rate);
	SerialTransceiver(Serial::Transceiver transceiver, Serial::Rate rate, OperatingMode mode);

	void initialize();

	void set_double_speed(bool sate);
	void set_baud_rate(uint16_t baud_setting);
	void set_tx_enabled(bool state);
	void set_rx_enabled(bool state);
	void set_stop_bits(bool state);
	void set_data_bits(DataBits bits);

	void set_operating_mode(OperatingMode new_mode);

	void transmit(uint8_t data);

	uint8_t receive();
	void peek();

private:
	const Serial::Transceiver transceiver;
	Serial::Rate rate;
	OperatingMode mode;
};

#endif
