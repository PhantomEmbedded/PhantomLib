#ifndef PWM_OUTPUT_H
#define PWM_OUTPUT_H

#include "Timer.h"

class PWMOutput8Bit
{
public:
	enum Output
	{
		A,
		B
	};
	
	PWMOutput8Bit(Timer::TimerCounter8BitWithPWM timer, Output output);
	
	void set(uint8_t value);

	void set_prescaler();

private:
	Timer::TimerCounter8BitWithPWM timer;
	Output output;
};

#endif