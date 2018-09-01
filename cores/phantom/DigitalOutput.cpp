#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(GPIO::Port port, uint8_t bit):
	pin(GPIO::Pin {port, bit}),
	bitmask(1<<bit)
{
	initialize();
}

DigitalOutput::DigitalOutput(GPIO::Pin pin):
	pin(pin),
	bitmask(1<<pin.bit)
{
	initialize();
}

void DigitalOutput::initialize() const
{
	*pin.port.mode_register |= bitmask;
}

void DigitalOutput::set(bool state) const
{
	if (state)
		*pin.port.output_register |= bitmask;
	else
		*pin.port.output_register &= ~bitmask;
}

void DigitalOutput::toggle() const
{
	*pin.port.input_register |= bitmask;
}
