#include "DigitalInput.h"

DigitalInput::DigitalInput(GPIO::Port port, uint8_t pin):
	port(port),
	bitmask(1<<pin)
{
	initialize();
}

DigitalInput::DigitalInput(GPIO::PortPin port_pin):
	port(port_pin.port),
	bitmask(1<<port_pin.pin)
{
	initialize();
}

void DigitalInput::set_pullup(bool setup) const
{
	*port.output_register |= bitmask;
}

bool DigitalInput::get() const
{
	return *port.input_register & bitmask;
}

void DigitalInput::initialize() const
{
	*port.mode_register &= ~bitmask;
}
