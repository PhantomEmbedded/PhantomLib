#include "DigitalInput.h"

using namespace Phantom;

DigitalInput::DigitalInput(Pin &pin, bool pullup): pin(pin)
{
	uint8_t port = pin.getPort();
	uint8_t bit = pin.getBitMask();

	if (port == 0) return; // Check if valid

	volatile uint16_t *reg, *out;

	reg = pin.getModeRegister();
	out = pin.getOutputRegister();

	if (pullup)
	{ 
		uint8_t oldSREG = SREG;
				cli();
		*reg &= ~bit;
		*out |= bit;
	}
	else
	{
		uint8_t oldSREG = SREG;
				cli();
		*reg &= ~bit;
		*out &= ~bit;
		SREG = oldSREG;
	}
}

DigitalInput::~DigitalInput()
{

}

bool DigitalInput::get()
{
	if (pin.getPort() == NOT_A_PIN) return false;
	return (*pin.getInputRegister() & pin.getBitMask());
}