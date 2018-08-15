#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <GPIOBase.h>

namespace GPIO
{
	const PROGMEM Port B = {&PINB, &DDRB, &PORTB};
	const PROGMEM Port C = {&PINC, &DDRC, &PORTC};
	const PROGMEM Port D = {&PIND, &DDRD, &PORTD};
}

#endif
