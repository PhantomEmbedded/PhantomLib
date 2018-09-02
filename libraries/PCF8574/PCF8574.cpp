#include "PCF8574.h"

PCF8574::PCF8574(I2C::Interface interface, uint8_t address):
	device(interface, address)
{

}

void PCF8574::write(uint8_t byte)
{
	value = byte;
	device.write(byte);
}

void PCF8574::write(uint8_t bit, bool state)
{
	const uint8_t bitmask = 1 << bit;

	if (state)
		value |= bitmask;
	else
		value &= ~bitmask;

	write(value);
}