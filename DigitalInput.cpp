#include <DigitalInput.h>

using namespace Phantom;

DigitalInput::DigitalInput(Pin *pin, bool pullup): pin(pin), pullup(pullup)
{
	auto bit = pin->getBitMask();

	auto mode = pin->getModeRegister();
	*mode &= ~bit; // Set mode to input

	// Drive output for internal pullup
	auto out = pin->getOutputRegister();
	if (pullup)
		*out |= bit;
	else
		*out &= ~bit;
}

DigitalInput::~DigitalInput()
{
	if (pullup)
	{	// Drive output low
		auto bit = pin->getBitMask();
		auto out = pin->getOutputRegister();
		*out |= bit;
	}
}

bool DigitalInput::get()
{
	// Read bit from input register
	auto bit = pin->getBitMask();
	auto in = pin->getInputRegister();
	return *in & bit;
}