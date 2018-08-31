#include "SerialTransceiver.h"

SerialTransceiver::SerialTransceiver(Serial::Transceiver transceiver, Serial::Rate rate):
	transceiver(transceiver),
	rate(rate),
	mode(OperatingMode::AsyncDoubleSpeed)
{
	initialize();
}

SerialTransceiver::SerialTransceiver(Serial::Transceiver transceiver, Serial::Rate rate, OperatingMode mode):
	transceiver(transceiver),
	rate(rate),
	mode(mode)
{
	initialize();
}

void SerialTransceiver::initialize()
{
	uint16_t baud_setting = (F_CPU / (mode * rate)) - 1;

	if (mode == OperatingMode::AsyncDoubleSpeed)
	{
		*transceiver.control_and_satus_register.A |= (1 << U2X0);
	}
	else if (mode == OperatingMode::AsyncNormal)
	{
		*transceiver.control_and_satus_register.A &= ~(1 << U2X0);
	}

	*transceiver.baud_rate_register.L = (uint8_t)(baud_setting);
	*transceiver.baud_rate_register.H = (uint8_t)(baud_setting >> 8);

	*transceiver.control_and_satus_register.B = (1<<RXEN0) | (1<<TXEN0); // rx/tx eanble

	*transceiver.control_and_satus_register.C = (1<<USBS0) | (3<<UCSZ00); // 8 data, 2 stop
}

void SerialTransceiver::transmit(uint8_t data)
{
	while ( !( *transceiver.control_and_satus_register.A & (1<<UDRE0))); // wait for empty transmit buffer

	*transceiver.data_register = data;
}

void SerialTransceiver::set_operating_mode(OperatingMode new_mode)
{
	mode = new_mode;
	initialize();
}
