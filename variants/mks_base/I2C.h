#ifndef I2C_H
#define I2C_H

#include <I2CBase.h>
#include "GPIO.h"

namespace I2C
{
	const Interface A =
	{
		{
			{GPIO::C, 5},
			{GPIO::C, 4}
		},
		&TWBR,
		&TWSR,
		&TWAR,
		&TWDR,
		&TWCR,
		&TWAMR
	};
}

#endif
