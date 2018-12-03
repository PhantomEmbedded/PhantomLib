#ifndef TIMERS_H
#define TIMERS_H

#include <Timer.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "GPIO.h"

const TimerCounter8BitWithPWM TC0 =
{
	.output				= {{GPIO::D, 6}, {GPIO::D, 5}},
	.control 			= {&TCCR0A, &TCCR0B},
	.interrupt_mask 	= &TIMSK0,
	.general_control 	= &AVR_GTCCR,
	.value 				= &TCNT0,
	.output_compare 	= {&OCR0A, &OCR0B},
	.interrupt_flag 	= &TIFR0
};

const TimerCounter16BitWithPWM TC1 =
{
	.control 		= {&TCCR1A, &TCCR1B, &TCCR1C},
	.value 			= {&TCNT1L, &TCNT1H},
	.input_capture 	= {&ICR1L, &ICR1H},
	.output_compare =
	{
		.A = {&OCR1AL, &OCR1AH},
		.B = {&OCR1BL, &OCR1BH}
	},
	.interrupt_mask = &TIMSK1,
	.interrupt_flag = &TIFR1
};

#endif