#ifndef TIMER_BASE_H
#define TIMER_BASE_H

#include <avr/io.h>
#include "GPIOBase.h"

#undef PSRSYNC
#undef TSM

// fix global macro screwing with non-global member naming
const auto AVR_GTCCR = GTCCR;
#undef GTCCR

typedef struct
{
	struct
	{
		GPIO::Pin A;
		GPIO::Pin B;
	} output;
	struct
	{
		volatile uint8_t * A;
		volatile uint8_t * B;
	} control;
	volatile uint8_t * interrupt_mask;
	volatile uint8_t * value;
	struct
	{
		volatile uint8_t * A;
		volatile uint8_t * B;
	} output_compare;
	volatile uint8_t * interrupt_flag;
} TimerCounter8BitWithPWM;

typedef struct
{
	struct
	{
		GPIO::Pin A;
		GPIO::Pin B;
	} output;
	struct
	{
		volatile uint8_t * A;
		volatile uint8_t * B;
	} control;
	volatile uint8_t * interrupt_mask;
	volatile uint8_t * value;
	struct
	{
		volatile uint8_t * A;
		volatile uint8_t * B;
	} output_compare;
	volatile uint8_t * async_status;
	volatile uint8_t * interrupt_flag;
} TimerCounter8BitWithPWMWithAsync;

typedef struct 
{
	struct
	{
		GPIO::Pin A;
		GPIO::Pin B;
		GPIO::Pin C;
	} output;
	struct
	{
		volatile uint8_t * A;
		volatile uint8_t * B;
		volatile uint8_t * C;
	} control;
	struct
	{
		volatile uint8_t * low;
		volatile uint8_t * high;
	} value;
	struct
	{
		volatile uint8_t * low;
		volatile uint8_t * high;
	} input_capture;
	struct
	{
		struct
		{
			volatile uint8_t * low;
			volatile uint8_t * high;
		} A;
		struct
		{
			volatile uint8_t * low;
			volatile uint8_t * high;
		} B;
	} output_compare;
	volatile uint8_t * interrupt_mask;
	volatile uint8_t * interrupt_flag;
} TimerCounter16BitWithPWM;

#endif
