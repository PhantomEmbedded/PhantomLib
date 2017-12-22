#include "DigitalInput.h"

using namespace Phantom;

DigitalInput::DigitalInput(Pin &pin, bool pullup): pin(pin), pullup(pullup)
{
	auto bit = pin.getBitMask();

	auto mode = pin.getModeRegister();
	*mode &= ~bit;

	auto out = pin.getOutputRegister();
	if (pullup)
		*out |= bit;
	else
		*out &= ~bit;
}

DigitalInput::~DigitalInput()
{
	if (pullup)
	{	// Drive output low
		auto bit = pin.getBitMask();
		auto out = pin.getOutputRegister();
		*out |= bit;
	}
}

inline bool DigitalInput::get()
{
	auto bit = pin.getBitMask();
	auto in = pin.getInputRegister():
	return *in & bit;
}