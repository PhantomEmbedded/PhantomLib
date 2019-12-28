#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H

#include "StepperDriver.h"
#include <inttypes.h>
#include <stdlib.h>

class StepperMotor
{
public:
	StepperMotor(StepperDriver * driver, uint16_t steps_per_degree);

	void set_target_angle(double angle);
	void override_angle(double angle);

	void update();
	void stop();

	bool movement_finished();

private:
	StepperDriver * driver;
	uint16_t steps_per_degree;

	int32_t degrees_to_steps(double angle);

	int32_t current_step_count;
	int32_t steps_to_go;
	StepperDriver::Direction direction;
};

#endif