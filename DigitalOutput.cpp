#include "DigitalOutput.h"

using namespace Phantom;

DigitalOutput::DigitalOutput(Pin *pin): pin(pin)
{
	// Set pin as output
	auto bit = pin->getBitMask();
	auto mode = pin->getModeRegister();
	*mode |= bit;
}

DigitalOutput::~DigitalOutput()
{
	//uint8_t oldSREG = SREG;
	//cli();
	*pin->getModeRegister() &= ~pin->getBitMask();
	set(false);
	//SREG = oldSREG;
}

inline void DigitalOutput::set(bool state)
{
	// The compiler will optomise these.
	auto bit = pin->getBitMask();
	auto out = pin->getOutputRegister();

	//uint8_t oldSREG = SREG; // Only needed with interrupts
	//cli(); // Only needed with interrupts

	if (state) {
		*out |= bit;
	} else {
		*out &= ~bit;
	}

	//SREG = oldSREG; // Only needed with interrupts
}

inline void DigitalOutput::toggle()
{
	auto bit = pin->getBitMask();
	auto out = pin->getOutputRegister();

	*out ^= bit;
}

inline void DigitalOutput::pulse(double time, bool state)
{
	set(state);

	_delay_us(time);

	set(!state);
}