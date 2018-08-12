#include "DigitalInput.h"

DigitalInput::DigitalInput(GPIO::Port port, uint8_t pin):
	port(port),
	bitmask(1<<pin)
{
	*port.mode_register &= ~bitmask;
}

void DigitalInput::set_pullup(bool setup)
{
	*port.output_register |= bitmask;
}

bool DigitalInput::get()
{
	return *port.input_register & bitmask;
}