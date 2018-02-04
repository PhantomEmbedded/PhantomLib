#include <PWMOutput.h>

using namespace Phantom;

PWMOutput::PWMOutput(Pin *pin): pin(pin)
{
	// Set pin as output
	auto bit = pin->getBitMask();
	auto mode = pin->getModeRegister();
	*mode |= bit;

	// TEMPORARY (REMOVE ASAP)
	TCCR0A = 0b10100001;
	TCCR0B = 0b00000001;
	TCCR1A = 0b10100001;
	TCCR1B = 0b00000001;
	TCCR2A = 0b10100001;
	TCCR2B = 0b00000001;

}

PWMOutput::~PWMOutput()
{
	auto bit = pin->getBitMask();
	auto out = pin->getOutputRegister();
	auto mode = pin->getModeRegister();

	*mode &= ~bit;	// Mode to input
	*out &= ~bit;	// Output to low
}

void PWMOutput::set(uint8_t value)
{
	// Set OCR
	*pin->getTimer() = value;
}