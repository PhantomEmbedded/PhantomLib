#ifndef DIGITAL_OUTPUT_H
#define DIGITAL_OUTPUT_H

#include <avr/pgmspace.h>
#include <util/delay.h>
#include <Pin.h>

namespace Phantom
{
	class DigitalOutput
	{
	public:
		DigitalOutput(Pin *pin);
		~DigitalOutput();

		void set(bool state);

		void toggle();

		void pulse(double time, bool state);

	private:
		Pin *pin;
		
	};
}

#endif /* END DIGITAL_OUTPUT_H */
