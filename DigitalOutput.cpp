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
	set(false);
	auto bit = pin->getBitMask();
	auto mode = pin->getModeRegister();
	*mode &= ~bit;
}

inline void DigitalOutput::set(bool state)
{
	// The compiler will optomise these.
	auto bit = pin->getBitMask();
	auto out = pin->getOutputRegister();

	if (state) {
		*out |= bit;
	} else {
		*out &= ~bit;
	}
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