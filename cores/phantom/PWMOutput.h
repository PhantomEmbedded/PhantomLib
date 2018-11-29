#ifndef PWM_OUTPUT_H
#define PWM_OUTPUT_H

#include <Timers.h>

class PWMOutput
{
public:
	enum Output
	{
		A,
		B
	};
	
	PWMOutput(Timer::TimerCounter8BitWithPWM timer, Output output);
	
	void set(uint8_t value);

	void set_prescaler();

private:
	enum Type
	{
		Bit8,
		Bit16
	};

	Type type;

	Timer::TimerCounter8BitWithPWM timer;
	Output output;
};

#endif