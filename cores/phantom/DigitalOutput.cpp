#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(GPIO::Port port, uint8_t bit):
	port(port),
	bitmask(1<<bit)
{
	initialize();
}

DigitalOutput::DigitalOutput(GPIO::Pin pin):
	port(pin.port),
	bitmask(1<<pin.bit)
{
	initialize();
}

void DigitalOutput::set(bool state) const
{
	if (state)
		*port.output_register |= bitmask;
	else
		*port.output_register &= ~bitmask;
}

void DigitalOutput::toggle() const
{
	*port.input_register |= bitmask;
}

void DigitalOutput::initialize() const
{
	*port.mode_register |= bitmask;
}
