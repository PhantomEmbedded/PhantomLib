#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(GPIO::Port port, uint8_t pin):
	port(port),
	bitmask(1<<pin)
{
	initialize();
}

DigitalOutput::DigitalOutput(GPIO::PortPin port_pin):
	port(port_pin.port),
	bitmask(1<<port_pin.pin)
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
