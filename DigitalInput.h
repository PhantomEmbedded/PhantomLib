#ifndef DIGITAL_INPUT_H
#define DIGITAL_INPUT_H

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "Pin.h"

namespace Phantom
{
	class DigitalInput
	{
	public:
		DigitalInput(Pin *pin, bool pullup);
		~DigitalInput();

		bool get();
	private:
		Pin *pin;

		bool pullup;
		
	};
}

#endif /* END DIGITAL_INPUT_H */