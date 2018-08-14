#ifndef TIMER_BASE_H
#define TIMER_BASE_H

#include <avr/io.h>

#undef PSRSYNC
#undef TSM

// fix global macro screwing with non-global member naming
const auto AVR_GTCCR = GTCCR;
#undef GTCCR

namespace Timer
{
	typedef struct
	{
		union
		{
			struct
			{
				uint8_t WGMn0 	: 1,
						WGMn1 	: 1,
						unused 	: 2,
						COMnB0	: 1,
						COMnB1	: 1,
						COMnA0	: 1,
						COMnA1	: 1;
			};
			volatile uint8_t * full;
		} TCCRnA;
		union
		{
			struct
			{
				uint8_t CSn 	: 3,
						WGMn2 	: 1,
						unused 	: 2,
						FOCnB	: 1,
						FOCnA	: 1;
			};
			volatile uint8_t * full;
		} TCCRnB;
		union
		{
			struct
			{
				uint8_t TOIE 	: 1,
						OCIEA 	: 1,
						OCIEB 	: 1;
			};
			volatile uint8_t * full;
		} TIMSKn;
		union
		{
			struct
			{
				uint8_t PSRSYNC : 1,
						RSRASY	: 1,
						unused	: 5,
						TSM		: 1;
			};
			volatile uint8_t * full;
		} GTCCR;
		volatile uint8_t * TCNTn;
		volatile uint8_t * OCRnA;
		volatile uint8_t * OCRnB;
		union
		{
			struct
			{
				uint8_t TOV 	: 1,
						OCFA 	: 1,
						OCFB	: 1;
			};
			volatile uint8_t * full;
		} TIFR0n;
	} TimerCounter8BitWithPWM;
}

#endif
