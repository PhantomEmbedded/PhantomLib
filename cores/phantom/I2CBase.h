#ifndef I2C_BASE_H
#define	I2C_BASE_H

#include <util/twi.h>
#include "GPIOBase.h"

namespace I2C
{
	enum Modes
	{
		MasterTransmitter,
		MasterReceiver,
		SlaveTransmitter,
		SlaveReceiver
	};

	typedef struct
	{
		struct {
			GPIO::Pin scl;
			GPIO::Pin sda;
		} pin;
		volatile uint8_t* bit_rate_register;
		volatile uint8_t* status_register;
		volatile uint8_t* slave_address_register;
		volatile uint8_t* data_register;
		volatile uint8_t* control_register;
		volatile uint8_t* address_mask_register;
	} Interface;
}

#endif