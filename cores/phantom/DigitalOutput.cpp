#include "DigitalOutput.h"

DigitalOutput::DigitalOutput(GPIO::Port port, uint8_t pin):
	port(port),
	pin(pin),
	bitmask(1<<pin)
{

	initialize();
}

void DigitalOutput::initialize()
{
	*port.mode_register |= bitmask;
}

void DigitalOutput::set(State state)
{
	if (state == High)
		*port.output_register |= bitmask;
	else
		*port.output_register &= ~bitmask;
}

void DigitalOutput::set(bool state) {
	set((State)state);
}

void DigitalOutput::toggle() {
	*port.input_register |= bitmask;
}