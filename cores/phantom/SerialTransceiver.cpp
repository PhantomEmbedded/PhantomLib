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

	set_baud_rate(baud_setting);

	set_double_speed(mode == OperatingMode::AsyncDoubleSpeed);

	set_tx_enabled(true);
	set_rx_enabled(true);

	set_stop_bits(StopBits::Bit2);
	set_data_bits(DataBits::Bit8);
}

void SerialTransceiver::set_double_speed(bool state)
{
	if (state)
		*transceiver.control_and_satus_register.A |= (1 << U2X0);
	else
		*transceiver.control_and_satus_register.A &= ~(1 << U2X0);
}

void SerialTransceiver::set_baud_rate(uint16_t baud_setting)
{
	*transceiver.baud_rate_register.L = (uint8_t)(baud_setting);
	*transceiver.baud_rate_register.H = (uint8_t)(baud_setting >> 8);
}

void SerialTransceiver::set_tx_enabled(bool state)
{
	if (state)
		*transceiver.control_and_satus_register.B |= (1<<TXEN0);
	else
		*transceiver.control_and_satus_register.B &= ~(1<<TXEN0);
}

void SerialTransceiver::set_rx_enabled(bool state)
{
	if (state)
		*transceiver.control_and_satus_register.B |= (1<<RXEN0);
	else
		*transceiver.control_and_satus_register.B |= ~(1<<RXEN0);
}

void SerialTransceiver::set_stop_bits(bool state)
{
	if (state)
		*transceiver.control_and_satus_register.C |= (1<<USBS0);
	else
		*transceiver.control_and_satus_register.C &= ~(1<<USBS0);
}

void SerialTransceiver::set_data_bits(DataBits bits)
{
	*transceiver.control_and_satus_register.C &= ~(3<<UCSZ00);
	*transceiver.control_and_satus_register.C |= (3<<UCSZ00) & (bits<<UCSZ00);

	*transceiver.control_and_satus_register.B &= ~(0b1<<UCSZ02);
	*transceiver.control_and_satus_register.C |= (0b1<<UCSZ02) & (bits<<UCSZ02);
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
