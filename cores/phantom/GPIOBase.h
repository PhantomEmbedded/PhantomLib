#ifndef GPIO_BASE_H
#define GPIO_BASE_H

namespace GPIO
{
	typedef struct
	{
		volatile uint8_t* input_register;
		volatile uint8_t* mode_register;
		volatile uint8_t* output_register;
	} Port;
}

#endif
