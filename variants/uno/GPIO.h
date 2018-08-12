#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>

namespace GPIO
{
	typedef struct
	{
		volatile uint8_t* input_register;
		volatile uint8_t* mode_register;
		volatile uint8_t* output_register;
	} Port;

	const Port B = {&PINB,&DDRB,&PORTB};
}

#endif