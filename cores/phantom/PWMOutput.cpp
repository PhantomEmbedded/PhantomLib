#include "PWMOutput.h"

PWMOutput8Bit::PWMOutput8Bit(Timer::TimerCounter8BitWithPWM timer, Output output):
	timer(timer),
	output(output)
{
	switch (output)
	{
		case A: *timer.output.A.port.mode_register |= (1 << timer.output.A.bit); break;
		case B: *timer.output.B.port.mode_register |= (1 << timer.output.A.bit); break;
	}
	*timer.control.A |= (1<<COM0A1)|(1<<COM0B1)|(1<<WGM00);
	*timer.control.B |= (1<<CS00);
}

void PWMOutput8Bit::set(uint8_t value)
{
	switch (output)
	{
		case A: *timer.output_compare.A = value; break;
		case B: *timer.output_compare.B = value; break;
	}
}
