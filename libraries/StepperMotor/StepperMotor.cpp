#include "StepperMotor.h"

StepperMotor::StepperMotor(StepperDriver * driver, uint16_t steps_per_degree):
	driver(driver),
	steps_per_degree(steps_per_degree)
{

}

void StepperMotor::set_target_angle(double angle)
{
	steps_to_go = abs(degrees_to_steps(angle)) - current_step_count;
	direction = angle > 0 ? StepperDriver::Forward : StepperDriver::Reverse;
	driver->set_direction(direction);
}

void StepperMotor::override_angle(double angle)
{
	current_step_count = abs(degrees_to_steps(angle));
}

void StepperMotor::update()
{
	if (!movement_finished())
	{
		driver->step();
		steps_to_go -= 1;
		current_step_count = direction ? 1 : -1;
	}
}

bool StepperMotor::movement_finished()
{
	return steps_to_go == 0;
}

int32_t StepperMotor::degrees_to_steps(double angle)
{
	return angle * steps_per_degree;
}