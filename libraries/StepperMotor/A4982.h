#ifndef A4982_H
#define A4982_H

#include <util/delay.h>
#include <DigitalOutput.h>
#include "StepperDriver.h"

class A4982: public StepperDriver
{
public:
	A4982(
		DigitalOutput * step_output,
		DigitalOutput * direction_output,
		DigitalOutput * microstep_1_output,
		DigitalOutput * microstep_2_output,
		DigitalOutput * enable_output,
		DigitalOutput * cs_output
	);

	void set_microstep(MicrostepResolution resolution);
	void set_enabled(bool enabled);

	void set_direction(Direction direction);
	void step();

private:
	DigitalOutput * step_output;
	DigitalOutput * direction_output;
	DigitalOutput * microstep_1_output;
	DigitalOutput * microstep_2_output;
	DigitalOutput * enable_output;
	DigitalOutput * cs_output;
};

#endif
