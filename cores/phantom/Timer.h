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
				volatile uint8_t
						WGMn0 	: 1,
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
				volatile uint8_t
						CSn 	: 3,
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
				volatile uint8_t
						TOIE 	: 1,
						OCIEA 	: 1,
						OCIEB 	: 1;
			};
			volatile uint8_t * full;
		} TIMSKn;
		union
		{
			struct
			{
				volatile uint8_t
						PSRSYNC : 1,
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
				volatile uint8_t
						TOV 	: 1,
						OCFA 	: 1,
						OCFB	: 1;
			};
			volatile uint8_t * full;
		} TIFR0n;
	} TimerCounter8BitWithPWM;

	typedef struct 
	{
		union
		{
			struct
			{
				volatile uint8_t
						WGMn0 	: 1,
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
				volatile uint8_t
						CSn 	: 3,
						WGMn2 	: 1,
						WGMn3 	: 1,
						unused	: 1,
						ICES	: 1,
						ICNC	: 1;
			};
			volatile uint8_t * full;
		} TCCRnB;
		union
		{
			struct
			{
				volatile uint8_t
						unused	: 6,
						FOCnA	: 1,
						FOCnB	: 1;
			};
		} TCCRnC;
		volatile uint8_t * TCNTnL;
		volatile uint8_t * TCNTnH;
		volatile uint8_t * ICRnL;
		volatile uint8_t * ICRnH;
		volatile uint8_t * OCRnAL;
		volatile uint8_t * OCRnAH;
		volatile uint8_t * OCRnBL;
		volatile uint8_t * OCRnBH;
		union
		{
			struct
			{
				volatile uint8_t
						TOIE	: 1,
						OCIEA	: 1,
						OCIEB	: 1,
						unused	: 2,
						ICIE	: 1;
			};
			volatile uint8_t * full;
		} TIMSKn;
		union
		{
			struct
			{
				volatile uint8_t
						TOV		: 1,
						OCFA	: 1,
						OCFB	: 1,
						unused	: 2,
						ICF		: 1;
			};
			volatile uint8_t * full;
		} TIFRn;
	} TimerCounter16BitWithPWM;
}

#endif
