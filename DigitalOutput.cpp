#include "DigitalOutput.h"

using namespace Phantom;

DigitalOutput::DigitalOutput(Pin &pin): pin(pin)
{
	if (pin.getPort() == 0) return; // Check if valid

	uint8_t oldSREG = SREG;
	cli();
	*pin.getModeRegister() |= pin.getBitMask();
	SREG = oldSREG;
}

DigitalOutput::~DigitalOutput()
{
	// Return pin mode to output
	uint8_t bit = pin.getBitMask();

	uint8_t oldSREG = SREG;
	cli();
	*pin.getModeRegister() &= ~bit;
	*pin.getOutputRegister() |= bit;

	SREG = oldSREG;
}

inline void DigitalOutput::set(bool state)
{
	// The compiler will optomise these.
	uint8_t bit = pin.getBitMask();
	volatile uint16_t *out = pin.getOutputRegister();

	uint8_t oldSREG = SREG;
	cli();

	if (state == false) {
		*out &= ~bit;
	} else {
		*out |= bit;
	}

	SREG = oldSREG;
}