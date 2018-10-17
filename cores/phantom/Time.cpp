#include "Time.h"

Time::Time():
	milliseconds_since_epoch(0)
{
	TCCR0A = 0x00;
	TCCR0B = (1<<CS00)|(1<<CS01);
	TIMSK0 = (1<<TOIE0);
	sei();
}

void Time::interrupt_callback()
{
	milliseconds_since_epoch += 1;
}

uint32_t Time::get_milliseconds() {
	return milliseconds_since_epoch;
}