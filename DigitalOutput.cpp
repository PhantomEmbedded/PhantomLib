#include "DigitalOutput.h"

using namespace Phantom;

DigitalOutput::DigitalOutput(Pin &pin): pin(pin)
{
	if (pin.getPort() == 0) return; // Check if valid

	//uint8_t oldSREG = SREG;
	//cli();
	*pin.getModeRegister() |= pin.getBitMask();
	//SREG = oldSREG;
}

DigitalOutput::~DigitalOutput()
{
	//uint8_t oldSREG = SREG;
	//cli();
	*pin.getModeRegister() &= ~pin.getBitMask();
	set(false);
	//SREG = oldSREG;
}

inline void DigitalOutput::set(bool state)
{
	// The compiler will optomise these.
	uint8_t bit = pin.getBitMask();
	volatile uint16_t *out = pin.getOutputRegister();

	//uint8_t oldSREG = SREG; // Only needed with interrupts
	//cli(); // Only needed with interrupts

	if (state) {
		*out |= bit;
	} else {
		*out &= ~bit;
	}

	//SREG = oldSREG; // Only needed with interrupts
}

inline void DigitalOutput::pulse(double time, bool state)
{
	// Time to go low = 0.96us
	// Time to go high = 0.7us
	set(state);

	_delay_us(time - (state ? 0.96 : 0.7));

	set(!state);
}