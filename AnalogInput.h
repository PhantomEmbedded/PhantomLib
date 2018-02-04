#ifndef ANALOG_INPUT_H
#define ANALOG_INPUT_H

#include <avr/pgmspace.h>
#include <Pin.h>

namespace Phantom
{
	class AnalogInput
	{
	public:
		AnalogInput(Pin *pin, bool pullup);
		~AnalogInput();

		uint16_t get();
		
	private:
		Pin *pin;
		bool pullup;
	};
}

#endif /* END ANALOG_INPUT_H */