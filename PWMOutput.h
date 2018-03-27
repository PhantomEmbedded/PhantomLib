#ifndef PWM_OUTPUT_H
#define PWM_OUTPUT_H

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <Pin.h>

namespace Phantom
{
	class PWMOutput
	{
	public:
		PWMOutput(Pin *pin);
		~PWMOutput();
		
		void set(uint8_t value);

	private:
		Pin *pin;
	};
}

#endif /* END PWM_OUTPUT_H */
