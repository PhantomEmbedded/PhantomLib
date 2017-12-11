#ifndef DIGITAL_INPUT_H
#define DIGITAL_INPUT_H

#include <avr/pgmspace.h>
#include "Pin.h"

namespace Bubble
{
	class DigitalInput
	{
	public:
		DigitalInput(Pin &pin);
		~DigitalInput();

		bool get();
	private:
		Pin pin;
		
	};
}

#endif /* END DIGITAL_INPUT_H */