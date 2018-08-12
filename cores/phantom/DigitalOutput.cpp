#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(GPIO::Port port, uint8_t pin):
	port(port),
	bitmask(1<<pin)
{
	*port.mode_register |= bitmask;
}

void DigitalOutput::set(bool state)
{
	if (state)
		*port.output_register |= bitmask;
	else
		*port.output_register &= ~bitmask;
}

void DigitalOutput::toggle()
{
	*port.input_register |= bitmask;
}