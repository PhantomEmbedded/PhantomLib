#ifndef STEPPER_DRIVER_H
#define STEPPER_DRIVER_H

#include <avr/io.h>

class StepperDriver
{
public:
	enum Direction {
		Forward = 0,
		Reverse = 1
	};

	enum MicrostepResolution
	{
		FullStep		= 0,
		HalfStep		= 1,
		QuarterStep		= 2,
		SixteenthStep	= 3
	};

	StepperDriver();
	~StepperDriver();

	// Control
	virtual void set_direction(Direction direction) {}
	virtual void step() {}
	
};

#endif