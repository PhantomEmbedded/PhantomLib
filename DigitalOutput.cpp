#include <DigitalOutput.h>

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
	// The order of these events ensures that the output is driven from
	// high -> low, rather than high -> internal pullup -> low.
	
	// Drive output low
	set(false);

	// Set mode to input
	auto bit = pin->getBitMask();
	auto mode = pin->getModeRegister();
	*mode &= ~bit;
}

inline void DigitalOutput::set(bool state)
{
	// The compiler will optomise these.
	auto bit = pin->getBitMask();
	auto out = pin->getOutputRegister();

	if (state)
		*out |= bit; // high
	else
		*out &= ~bit; // low
}

inline void DigitalOutput::toggle()
{
	auto bit = pin->getBitMask();
	auto out = pin->getOutputRegister();
	*out ^= bit; // Toggle state
}