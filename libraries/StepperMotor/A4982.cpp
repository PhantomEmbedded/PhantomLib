#include "A4982.h"

A4982::A4982(
		DigitalOutput * step_output,
		DigitalOutput * direction_output,
		DigitalOutput * microstep_1_output,
		DigitalOutput * microstep_2_output,
		DigitalOutput * enable_output,
		DigitalOutput * cs_output
	):
	step_output(step_output),
	direction_output(direction_output),
	microstep_1_output(microstep_1_output),
	microstep_2_output(microstep_2_output),
	enable_output(enable_output),
	cs_output(cs_output)
{

}

void A4982::set_microstep(MicrostepResolution resolution)
{
	microstep_1_output->set(resolution & 0b01);
	microstep_2_output->set(resolution & 0b10);
}

void A4982::set_enabled(bool enabled)
{
	enable_output->set(!enabled);
}

void A4982::set_direction(Direction direction)
{
	direction_output->set((bool)direction);
}

void A4982::step()
{
	step_output->set(false);
	_delay_us(100);
	step_output->set(true);
	_delay_us(100);
}
