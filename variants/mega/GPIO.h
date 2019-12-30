#ifndef GPIO_H
#define GPIO_H

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <GPIOBase.h>

namespace GPIO
{
	const Port A = {&PINA,&DDRA,&PORTA};
	const Port B = {&PINB,&DDRB,&PORTB};
	const Port C = {&PINC,&DDRC,&PORTC};
	const Port D = {&PIND,&DDRD,&PORTD};
	const Port E = {&PINE,&DDRE,&PORTE};
	const Port F = {&PINF,&DDRF,&PORTF};
	const Port G = {&PING,&DDRG,&PORTG};
	const Port H = {&PINH,&DDRH,&PORTH};
	const Port J = {&PINJ,&DDRJ,&PORTJ};
	const Port K = {&PINK,&DDRK,&PORTK};
	const Port L = {&PINL,&DDRL,&PORTL};
}

#endif