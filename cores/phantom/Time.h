#ifndef TIME_H
#define TIME_H

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>

class Time
{
public:
	Time();

	void interrupt_callback();

	uint32_t get_milliseconds();

private:
	// clock / 1MHz
	const uint8_t cycles_per_microsecond = F_CPU / 1000000;
	// (ticks * prescaler) / cycle period
	const uint32_t microseconds_per_overflow = (256 * 64) / cycles_per_microsecond;
	const uint32_t milliseconds_per_overflow = microseconds_per_overflow / 1000;
	volatile uint16_t milliseconds_since_epoch;
	
};

#endif