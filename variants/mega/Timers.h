#ifndef TIMERS_H
#define TIMERS_H

#include <Timer.h>
#include "GPIO.h"

const TimerCounter8BitWithPWM TC0 =
{
	.output				= {{GPIO::B, 7}, {GPIO::G, 5}},
	.control 			= {&TCCR0A, &TCCR0B},
	.interrupt_mask 	= &TIMSK0,
	.value 				= &TCNT0,
	.output_compare 	= {&OCR0A, &OCR0B},
	.interrupt_flag 	= &TIFR0
};

const TimerCounter16BitWithPWM TC1 =
{
	.output			= {{GPIO::B, 5}, {GPIO::B, 6}, {GPIO::B, 7}},
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

const TimerCounter8BitWithPWMWithAsync TC2 =
{
	.output				= {{GPIO::B, 4}, {GPIO::H, 6}},
	.control 			= {&TCCR2A, &TCCR2B},
	.interrupt_mask 	= &TIMSK2,
	.value 				= &TCNT2,
	.output_compare 	= {&OCR2A, &OCR2B},
	.async_status		= &ASSR,
	.interrupt_flag 	= &TIFR2
};

const TimerCounter16BitWithPWM TC3 =
{
	.output			= {{GPIO::E, 3}, {GPIO::E, 4}, {GPIO::E, 5}},
	.control 		= {&TCCR3A, &TCCR3B, &TCCR3C},
	.value 			= {&TCNT3L, &TCNT3H},
	.input_capture 	= {&ICR3L, &ICR3H},
	.output_compare =
	{
		.A = {&OCR3AL, &OCR3AH},
		.B = {&OCR3BL, &OCR3BH}
	},
	.interrupt_mask = &TIMSK3,
	.interrupt_flag = &TIFR3
};

const TimerCounter16BitWithPWM TC4 =
{
	.output			= {{GPIO::H, 3}, {GPIO::H, 4}, {GPIO::H, 5}},
	.control 		= {&TCCR4A, &TCCR4B, &TCCR4C},
	.value 			= {&TCNT4L, &TCNT4H},
	.input_capture 	= {&ICR4L, &ICR4H},
	.output_compare =
	{
		.A = {&OCR4AL, &OCR4AH},
		.B = {&OCR4BL, &OCR4BH}
	},
	.interrupt_mask = &TIMSK4,
	.interrupt_flag = &TIFR4
};

const TimerCounter16BitWithPWM TC5 =
{
	.output			= {{GPIO::L, 3}, {GPIO::L, 4}, {GPIO::L, 5}},
	.control 		= {&TCCR5A, &TCCR5B, &TCCR5C},
	.value 			= {&TCNT5L, &TCNT5H},
	.input_capture 	= {&ICR5L, &ICR5H},
	.output_compare =
	{
		.A = {&OCR5AL, &OCR5AH},
		.B = {&OCR5BL, &OCR5BH}
	},
	.interrupt_mask = &TIMSK5,
	.interrupt_flag = &TIFR5
};

#endif