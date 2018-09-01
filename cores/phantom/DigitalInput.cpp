#include "DigitalInput.h"

DigitalInput::DigitalInput(GPIO::Port port, uint8_t bit):
	pin(GPIO::Pin {port, bit}),
	bitmask(1<<bit)
{
	initialize();
}

DigitalInput::DigitalInput(GPIO::Pin pin):
	pin(pin),
	bitmask(1<<pin.bit)
{
	initialize();
}

void DigitalInput::initialize() const
{
	*pin.port.mode_register &= ~bitmask;
}

void DigitalInput::set_pullup(bool setup) const
{
	*pin.port.output_register |= bitmask;
}

bool DigitalInput::get() const
{
	return *pin.port.input_register & bitmask;
}