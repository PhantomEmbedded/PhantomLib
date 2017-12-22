#include "DigitalInput.h"

using namespace Phantom;

DigitalInput::DigitalInput(Pin &pin, bool pullup): pin(pin), pullup(pullup)
{
	uint8_t port = pin.getPort();
	uint8_t bit = pin.getBitMask();

	volatile uint16_t *reg, *out;

	reg = pin.getModeRegister();
	out = pin.getOutputRegister();

	uint8_t oldSREG = SREG;
	cli();
	*reg &= ~bit;

	if (pullup)
		*out |= bit;
	else
		*out &= ~bit;
	
	SREG = oldSREG;
}

DigitalInput::~DigitalInput()
{
	if (pullup) // Return pin mode to input
	{
		uint8_t bit = pin.getBitMask();

		uint8_t oldSREG = SREG;
		cli();
		*pin.getModeRegister() &= ~bit;
		*pin.getOutputRegister() |= bit;

		SREG = oldSREG;
	}
}

inline bool DigitalInput::get()
{
	return *pin.getInputRegister() & pin.getBitMask();
}