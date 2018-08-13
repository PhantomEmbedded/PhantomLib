#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <GPIOBase.h>

namespace GPIO
{
	const Port B = {&PINB, &DDRB, &PORTB};
	const Port C = {&PINC, &DDRC, &PORTC};
	const Port D = {&PIND, &DDRD, &PORTD};
}

#endif
