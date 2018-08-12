#ifndef DIGITAL_OUTPUT_H
#define DIGITAL_OUTPUT_H

#include <GPIO.h>

class DigitalOutput
{
public:
	DigitalOutput(GPIO::Port port, uint8_t pin);

	void set(bool state);
	void toggle();

private:
	const GPIO::Port port;
	const uint8_t bitmask;
};

#endif