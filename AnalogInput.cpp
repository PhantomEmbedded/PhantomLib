#include <AnalogInput.h>

using namespace Phantom;

AnalogInput::AnalogInput(Pin *pin, bool pullup): pin(pin), pullup(pullup)
{
	auto bit = pin->getBitMask();
	auto mode = pin->getModeRegister();
	auto out = pin->getOutputRegister();
	
	// Clr mode bit (set input)
	*mode &= ~bit;

	// Set output for pullup
	if (pullup)
		*out |= bit;
	else
		*out &= ~bit;

	// AREF = AVcc
	ADMUX = (1<<REFS0);
	// ADC Enable
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

}

AnalogInput::~AnalogInput()
{
	if (pullup) // Return pin mode to input
	{
		auto bit = pin->getBitMask();
		auto mode = pin->getModeRegister();
		auto out = pin->getOutputRegister();

		*mode &= ~bit;
		*out |= bit;
	}
}

uint16_t AnalogInput::get()
{
	uint8_t pinNumber = pin->getNumber() - A0; // Subtract first analog pin to remove offset
	ADMUX = (ADMUX & 0xF8) | pinNumber; // clears the bottom 3 bits before ORing

	// start single convertion
	// write ’1′ to ADSC
	ADCSRA |= (1 << ADSC);

	// wait for ADSC to become 0
	while(ADCSRA & (1 << ADSC));

	return ADC;
}