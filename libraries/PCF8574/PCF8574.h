#ifndef PCF8574_H
#define PCF8574_H

#include <I2CDevice.h>

class PCF8574
{
public:
	PCF8574(I2C::Interface interface, uint8_t address);

	void initalize();
	
	void write(uint8_t byte);
	void write(uint8_t bit, bool state);
private:
	const I2CDevice device;

	uint8_t value;
};

#endif