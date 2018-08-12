#ifndef DIGITAL_OUTPUT_H
#define DIGITAL_OUTPUT_H

#include <GPIO.h>

class DigitalOutput
{
public:
	enum State {
		High = true,
		Low = false
	};

	DigitalOutput(GPIO::Port port, uint8_t pin);

	void initialize();

	void set(State state);
	void set(bool state);
	void toggle();

private:
	const GPIO::Port port;
	const uint8_t pin;
	const uint8_t bitmask;
};

#endif