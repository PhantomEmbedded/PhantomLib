#ifndef DIGITAL_OUTPUT_H
#define DIGITAL_OUTPUT_H

#include <GPIO.h>

class DigitalOutput
{
public:
	DigitalOutput(GPIO::Port port, uint8_t bit);
	DigitalOutput(GPIO::Pin pin);

	void initialize() const;

	void set(bool state) const;
	void toggle() const;

private:
	const GPIO::Pin pin;
	const uint8_t bitmask;
};

#endif
