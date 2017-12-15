#ifndef BOARD_ARDUINO_UNO_H
#define BOARD_ARDUINO_UNO_H

#include <avr/pgmspace.h>

#include "BoardBase.h"

namespace Phantom
{

	#define F_CPU 16000000UL

	const uint8_t PIN_COUNT = 20;
	const uint8_t PIN_COUNT_ADC = 6;
	const uint8_t PIN_COUNT_DAC = 6;

	// SPI
	const uint8_t SPI_SS    = 10;
	const uint8_t SPI_MOSI 	= 11;
	const uint8_t SPI_MISO 	= 12;
	const uint8_t SPI_SCK 	= 13;

	// I2C (Wire)
	const uint8_t I2C_SDA = 18;
	const uint8_t I2C_SCL = 19;
	// Analog
	const uint8_t A0 = 14;
	const uint8_t A1 = 15;
	const uint8_t A2 = 16;
	const uint8_t A3 = 17;
	const uint8_t A4 = 18;
	const uint8_t A5 = 19;
	const uint8_t A6 = 20;
	const uint8_t A7 = 21;

	// PWM

	bool digitalPinHasPWM(uint8_t pin)
	{
		switch (pin)
		{
			default: return false; break;
			#ifndef __AVR_ATmega8__
			case 3:
			case 5:
			case 6:
			#endif
			case 9:
			case 10:
			case 11:
				return true; break;
		}
	}

	// PCICR
	inline volatile uint8_t* digitalPinToPCICR(uint8_t pin)
	{
		return ((pin) >= 0 && (pin) <= 21) ? (&PCICR) : ((uint8_t *)0);
	}

	inline uint8_t digitalPinToPCICRbit(uint8_t pin)
	{
		return ((pin) <= 7) ? 2 : (((pin) <= 13) ? 0 : 1);
	}

	// PCMSK
	inline volatile uint8_t*  digitalPinToPCMSK(uint8_t pin)
	{
		return ((pin) <= 7) ? (&PCMSK2) : (((pin) <= 13) ? (&PCMSK0) : (((pin) <= 21) ? (&PCMSK1) : ((uint8_t *)0)));
	}

	inline uint8_t digitalPinToPCMSKbit(uint8_t pin)
	{
		return ((pin) <= 7) ? (pin) : (((pin) <= 13) ? ((pin) - 8) : ((pin) - 14));
	}

	// Interrupt
	inline uint8_t digitalPinToInterrupt(uint8_t pin)
	{
		return (pin) == 2 ? 0 : ((pin) == 3 ? 1 : NOT_AN_INTERRUPT);
	}

	// Port Mapping
	// these arrays map port names (e.g. port B) to the
	// appropriate addresses for various functions (e.g. reading
	// and writing)
	const uint16_t PROGMEM portToModePGM[] =
	{
		NOT_A_PORT,
		NOT_A_PORT,
		(uint16_t) &DDRB,
		(uint16_t) &DDRC,
		(uint16_t) &DDRD,
	};

	const uint16_t PROGMEM portToOutputPGM[] =
	{
		NOT_A_PORT,
		NOT_A_PORT,
		(uint16_t) &PORTB,
		(uint16_t) &PORTC,
		(uint16_t) &PORTD,
	};

	const uint16_t PROGMEM portToInputPGM[] =
	{
		NOT_A_PORT,
		NOT_A_PORT,
		(uint16_t) &PINB,
		(uint16_t) &PINC,
		(uint16_t) &PIND,
	};

	const uint8_t PROGMEM digitalPinToPortPGM[] =
	{
		PD, /* 0 */
		PD,
		PD,
		PD,
		PD,
		PD,
		PD,
		PD,
		PB, /* 8 */
		PB,
		PB,
		PB,
		PB,
		PB,
		PC, /* 14 */
		PC,
		PC,
		PC,
		PC,
		PC,
	};

	const uint8_t PROGMEM digitalPinToBitMaskPGM[] =
	{
		_BV(0), /* 0, port D */
		_BV(1),
		_BV(2),
		_BV(3),
		_BV(4),
		_BV(5),
		_BV(6),
		_BV(7),
		_BV(0), /* 8, port B */
		_BV(1),
		_BV(2),
		_BV(3),
		_BV(4),
		_BV(5),
		_BV(0), /* 14, port C */
		_BV(1),
		_BV(2),
		_BV(3),
		_BV(4),
		_BV(5),
	};

	const uint8_t PROGMEM digitalPinToTimerPGM[] =
	{
		NOT_ON_TIMER, /* 0 - port D */
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		// on the ATmega168, digital pin 3 has hardware pwm
	#if defined(__AVR_ATmega8__)
		NOT_ON_TIMER,
	#else
		TIMER2B,
	#endif
		NOT_ON_TIMER,
		// on the ATmega168, digital pins 5 and 6 have hardware pwm
	#if defined(__AVR_ATmega8__)
		NOT_ON_TIMER,
		NOT_ON_TIMER,
	#else
		TIMER0B,
		TIMER0A,
	#endif
		NOT_ON_TIMER,
		NOT_ON_TIMER, /* 8 - port B */
		TIMER1A,
		TIMER1B,
	#if defined(__AVR_ATmega8__)
		TIMER2,
	#else
		TIMER2A,
	#endif
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER, /* 14 - port C */
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
	};
}

#endif /* END BOARD_ARDUINO_UNO_H */