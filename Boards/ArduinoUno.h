#ifndef BOARD_ARDUINO_UNO_H
#define BOARD_ARDUINO_UNO_H

#include "BoardBase.h"

namespace Phantom
{

	#define F_CPU 16000000UL

	const uint8_t PIN_COUNT = 20;
	const uint8_t PIN_COUNT_ADC = 8;
	const uint8_t PIN_COUNT_PWM = 6;

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
			case 3:
			case 5:
			case 6:
			case 9:
			case 10:
			case 11:
				return true; break;
		}
	}

	// PCICR
	inline volatile uint8_t* digitalPinToPCICR(uint8_t pin)
	{
		if (pin <= 21)
			return &PCICR;
		else
			return 0;
	}

	inline uint8_t digitalPinToPCICRbit(uint8_t pin)
	{
		if (pin <= 7)
			return 2;
		else if (pin <= 13)
			return 0;
		else
			return 1;
	}

	// PCMSK
	inline volatile uint8_t*  digitalPinToPCMSK(uint8_t pin)
	{
		if (pin <= 7)
			return &PCMSK2;
		else if (pin <= 13)
			return PCMSK0;
		else if (pin <= 21)
			return PCMSK1;
		else
			return 0;
	}

	inline uint8_t digitalPinToPCMSKbit(uint8_t pin)
	{
		if (pin <= 7)
			return pin;
		else if (pin <= 13)
			return (pin - 8);
		else
			return (pin - 14);
	}

	// Interrupt
	inline uint8_t digitalPinToInterrupt(uint8_t pin)
	{
		if (pin == 2)
			return 0;
		else if (pin == 3)
			return 1;
		else
			return NOT_AN_INTERRUPT;
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

	const uint16_t PROGMEM digitalPinToTimerPGM[] =
	{
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		(uint16_t) &OCR2B,
		NOT_ON_TIMER,
		(uint16_t) &OCR0B,
		(uint16_t) &OCR0A,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		(uint16_t) &OCR1A,
		(uint16_t) &OCR1B,
		(uint16_t) &OCR2A,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER,
		NOT_ON_TIMER
	};
}

#endif /* END BOARD_ARDUINO_UNO_H */