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
		
		void set(float value);

	private:
		Pin *pin;
	};
}

#endif /* END PWM_OUTPUT_H */
