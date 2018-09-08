#include "SerialDevice.h"

SerialDevice::SerialDevice(Serial::Device device, Serial::Rate rate):
	device(device),
	rate(rate),
	mode(OperatingMode::AsyncDoubleSpeed)
{
	initialize();
}

SerialDevice::SerialDevice(Serial::Device device, Serial::Rate rate, OperatingMode mode):
	device(device),
	rate(rate),
	mode(mode)
{
	initialize();
}

void SerialDevice::initialize()
{
	uint16_t baud_setting = (F_CPU / (mode * rate)) - 1;

	set_baud_rate(baud_setting);

	set_double_speed(mode == OperatingMode::AsyncDoubleSpeed);

	set_tx_enabled(true);
	set_rx_enabled(true);

	set_stop_bits(StopBits::Bit2);
	set_data_bits(DataBits::Bit8);
}

void SerialDevice::set_double_speed(bool state)
{
	if (state)
		*device.control_and_satus_register.A |= (1 << U2X0);
	else
		*device.control_and_satus_register.A &= ~(1 << U2X0);
}

void SerialDevice::set_baud_rate(uint16_t baud_setting)
{
	*device.baud_rate_register.L = (uint8_t)(baud_setting);
	*device.baud_rate_register.H = (uint8_t)(baud_setting >> 8);
}

void SerialDevice::set_tx_enabled(bool state)
{
	if (state)
		*device.control_and_satus_register.B |= (1<<TXEN0);
	else
		*device.control_and_satus_register.B &= ~(1<<TXEN0);
}

void SerialDevice::set_rx_enabled(bool state)
{
	if (state)
		*device.control_and_satus_register.B |= (1<<RXEN0);
	else
		*device.control_and_satus_register.B |= ~(1<<RXEN0);
}

void SerialDevice::set_stop_bits(bool state)
{
	if (state)
		*device.control_and_satus_register.C |= (1<<USBS0);
	else
		*device.control_and_satus_register.C &= ~(1<<USBS0);
}

void SerialDevice::set_data_bits(DataBits bits)
{
	*device.control_and_satus_register.C &= ~(3<<UCSZ00);
	*device.control_and_satus_register.C |= (3<<UCSZ00) & (bits<<UCSZ00);

	*device.control_and_satus_register.B &= ~(0b1<<UCSZ02);
	*device.control_and_satus_register.C |= (0b1<<UCSZ02) & (bits<<UCSZ02);
}

void SerialDevice::transmit(uint8_t data)
{
	while (!transmit_ready()); // wait for empty transmit buffer

	*device.data_register = data;
}

bool SerialDevice::transmit_ready()
{
	return *device.control_and_satus_register.A & (1<<UDRE0);
}

uint8_t SerialDevice::receive()
{
	while (!receive_ready()); // wait for data

	return *device.data_register;
}

bool SerialDevice::receive_ready()
{
	return *device.control_and_satus_register.A & (1<<RXC0);
}

void SerialDevice::flush_receive_buffer()
{
	uint8_t dummy = 0;
	while (receive_ready())
	{
		dummy = *device.data_register;
	}
}

void SerialDevice::set_operating_mode(OperatingMode new_mode)
{
	mode = new_mode;
	initialize();
}
