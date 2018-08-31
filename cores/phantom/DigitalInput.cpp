#include "DigitalInput.h"

DigitalInput::DigitalInput(GPIO::Port port, uint8_t bit):
	port(port),
	bitmask(1<<bit)
{
	initialize();
}

DigitalInput::DigitalInput(GPIO::Pin pin):
	port(pin.port),
	bitmask(1<<pin.bit)
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
