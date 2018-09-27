#ifndef A4982_H
#define A4982_H

#include <util/delay.h>
#include <DigitalOutput.h>

class A4982
{
public:
	enum MicrostepResolution
	{
		FullStep		= 0b00,
		HalfStep		= 0b10,
		QuarterStep		= 0b01,
		SixteenthStep	= 0b11
	};

	enum Direction {
		Forward = 0,
		Reverse = 1
	};

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

	DigitalOutput * step_output;

private:
	DigitalOutput * direction_output;
	DigitalOutput * microstep_1_output;
	DigitalOutput * microstep_2_output;
	DigitalOutput * enable_output;
	DigitalOutput * cs_output;
};

#endif
