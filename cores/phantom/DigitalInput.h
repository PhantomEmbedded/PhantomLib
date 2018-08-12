#ifndef DIGITAL_INPUT_H
#define DIGITAL_INPUT_H

#include <GPIO.h>

class DigitalInput
{
public:
	DigitalInput(GPIO::Port port, uint8_t pin);

	void set_pullup(bool state);

	bool get();

private:
	const GPIO::Port port;
	const uint8_t bitmask;
};

#endif