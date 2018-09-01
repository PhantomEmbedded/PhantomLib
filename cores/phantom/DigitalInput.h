#ifndef DIGITAL_INPUT_H
#define DIGITAL_INPUT_H

#include <GPIO.h>

class DigitalInput
{
public:
	DigitalInput(GPIO::Port port, uint8_t bit);
	DigitalInput(GPIO::Pin pin);

	void initialize() const;

	void set_pullup(bool state) const;

	bool get() const;

private:

	const GPIO::Pin pin;
	const uint8_t bitmask;
};

#endif
