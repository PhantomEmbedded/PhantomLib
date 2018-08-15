#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <GPIOBase.h>

namespace GPIO
{
	const PROGMEM Port A = {&PINA,&DDRA,&PORTA};
	const PROGMEM Port B = {&PINB,&DDRB,&PORTB};
	const PROGMEM Port C = {&PINC,&DDRC,&PORTC};
	const PROGMEM Port D = {&PIND,&DDRD,&PORTD};
	const PROGMEM Port E = {&PINE,&DDRE,&PORTE};
	const PROGMEM Port F = {&PINF,&DDRF,&PORTF};
	const PROGMEM Port G = {&PING,&DDRG,&PORTG};
	const PROGMEM Port H = {&PINH,&DDRH,&PORTH};
	const PROGMEM Port J = {&PINJ,&DDRJ,&PORTJ};
	const PROGMEM Port K = {&PINK,&DDRK,&PORTK};
	const PROGMEM Port L = {&PINL,&DDRL,&PORTL};
}

#endif
