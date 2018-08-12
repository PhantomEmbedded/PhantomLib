#ifndef BOARD_ARDUINO_MEGA_H
#define BOARD_ARDUINO_MEGA_H

#include "BoardBase.h"

namespace Phantom
{

	#define F_CPU 16000000UL

	const uint8_t PIN_COUNT = 70;
	const uint8_t PIN_COUNT_ADC = 16;
	const uint8_t PIN_COUNT_PWM = 15;

	// SPI
	const uint8_t SPI_SS    = 53;
	const uint8_t SPI_MOSI 	= 51;
	const uint8_t SPI_MISO 	= 50;
	const uint8_t SPI_SCK 	= 52;

	// I2C (Wire)
	const uint8_t I2C_SDA = 20;
	const uint8_t I2C_SCL = 21;
	// Analog
	const uint8_t A0 = 54;
	const uint8_t A1 = 55;
	const uint8_t A2 = 56;
	const uint8_t A3 = 57;
	const uint8_t A4 = 58;
	const uint8_t A5 = 59;
	const uint8_t A6 = 60;
	const uint8_t A7 = 61;
	const uint8_t A8 = 62;
	const uint8_t A9 = 63;
	const uint8_t A10 = 64;
	const uint8_t A11 = 65;
	const uint8_t A12 = 66;
	const uint8_t A13 = 67;
	const uint8_t A14 = 68;
	const uint8_t A15 = 69;

	// PWM

	inline bool digitalPinHasPWM(uint8_t pin)
	{
		if 		((pin >= 2) and (pin <= 13))
			return true;
		else if ((pin >= 44) && (pin <= 46))
			return true;
	}

	// PCICR
	inline volatile uint8_t* digitalPinToPCICR(uint8_t pin)
	{
		if 		((pin >= 10) and (pin <= 13))
			return &PCICR;
		else if ((pin >= 50) and (pin <= 53))
			return &PCICR;
		else if ((pin >= 62) and (pin <= 69))
			return &PCICR;
		else
			return 0;
	}

	inline uint8_t digitalPinToPCICRbit(uint8_t pin)
	{
		if 		((pin >= 10) and (pin <= 13))
			return 0;
		else if ((pin >= 50) and (pin <= 53))
			return 0;
		else if ((pin >= 62) and (pin <= 69))
			return 2;
		else
			return 0;
	}

	// PCMSK
	inline volatile uint8_t*  digitalPinToPCMSK(uint8_t pin)
	{
		if 		((pin >= 10) && (pin <= 13))
			return &PCMSK0;
		else if ((pin >= 50) && (pin <= 53))
			return &PCMSK0;
		else if ((pin >= 62) && (pin <= 69))
			return &PCMSK2;
		else
			return 0;
	}

	inline uint8_t digitalPinToPCMSKbit(uint8_t pin)
	{
		if ((pin >= 10) and (pin <= 13))
			return pin - 6;
		else if (pin == 50)
			return 3;
		else if (pin == 51)
			return 2;
		else if (pin == 52)
			return 1;
		else if (pin == 55)
			return 0;
		else if ((pin >= 62) and (pin <= 69))
			return pin - 62;
		else
			return 0;
	}

	// Interrupt
	inline uint8_t digitalPinToInterrupt(uint8_t pin)
	{
		if 		(pin == 2)
			return 0;
		else if (pin == 3)
			return 1;
		else if (pin >= 18 && pin <= 21)
			return 23 - pin;
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
		(uint16_t) &DDRA,
		(uint16_t) &DDRB,
		(uint16_t) &DDRC,
		(uint16_t) &DDRD,
		(uint16_t) &DDRE,
		(uint16_t) &DDRF,
		(uint16_t) &DDRG,
		(uint16_t) &DDRH,
		NOT_A_PORT,
		(uint16_t) &DDRJ,
		(uint16_t) &DDRK,
		(uint16_t) &DDRL,
	};

	const uint16_t PROGMEM portToOutputPGM[] =
	{
		NOT_A_PORT,
		(uint16_t) &PORTA,
		(uint16_t) &PORTB,
		(uint16_t) &PORTC,
		(uint16_t) &PORTD,
		(uint16_t) &PORTE,
		(uint16_t) &PORTF,
		(uint16_t) &PORTG,
		(uint16_t) &PORTH,
		NOT_A_PORT,
		(uint16_t) &PORTJ,
		(uint16_t) &PORTK,
		(uint16_t) &PORTL,
	};

	const uint16_t PROGMEM portToInputPGM[] =
	{
		NOT_A_PIN,
		(uint16_t) &PINA,
		(uint16_t) &PINB,
		(uint16_t) &PINC,
		(uint16_t) &PIND,
		(uint16_t) &PINE,
		(uint16_t) &PINF,
		(uint16_t) &PING,
		(uint16_t) &PINH,
		NOT_A_PIN,
		(uint16_t) &PINJ,
		(uint16_t) &PINK,
		(uint16_t) &PINL,
	};

	const uint8_t PROGMEM digitalPinToPortPGM[] =
	{
		// PORTLIST (in CSV format)
		// Port, Name	
		PE, // USART0_RX
		PE, // USART0_TX
		PE, // PWM2
		PE, // PWM3
		PG, // PWM4
		PE, // PWM5
		PH, // PWM6
		PH, // PWM7
		PH, // PWM8
		PH, // PWM9
		PB, // PWM10
		PB, // PWM11
		PB, // PWM12
		PB, // PWM13
		PJ, // USART3_TX
		PJ, // USART3_RX
		PH, // USART2_TX
		PH, // USART2_RX
		PD, // USART1_TX
		PD, // USART1_RX
		PD, // I2C_SDA
		PD, // I2C_SCL
		PA, // D22
		PA, // D23
		PA, // D24
		PA, // D25
		PA, // D26
		PA, // D27
		PA, // D28
		PA, // D29
		PC, // D30
		PC, // D31
		PC, // D32
		PC, // D33
		PC, // D34
		PC, // D35
		PC, // D36
		PC, // D37
		PD, // D38
		PG, // D39
		PG, // D40
		PG, // D41
		PL, // D42
		PL, // D43
		PL, // D44
		PL, // D45
		PL, // D46
		PL, // D47
		PL, // D48
		PL, // D49
		PB, // SPI_MISO
		PB, // SPI_MOSI
		PB, // SPI_SCK
		PB, // SPI_SS
		PF, // A0
		PF, // A1
		PF, // A2
		PF, // A3
		PF, // A4
		PF, // A5
		PF, // A6
		PF, // A7
		PK, // A8
		PK, // A9
		PK, // A10
		PK, // A11
		PK, // A12
		PK, // A13
		PK, // A14
		PK, // A15
	};

	const uint8_t PROGMEM digitalPinToBitMaskPGM[] =
	{
		// PIN IN PORT (in CSV format)
		// Bit,	   Name
		_BV(0), // USART0_RX
		_BV(1), // USART0_TX
		_BV(4), // PWM2
		_BV(5), // PWM3
		_BV(5), // PWM4
		_BV(3), // PWM5
		_BV(3), // PWM6
		_BV(4), // PWM7
		_BV(5), // PWM8
		_BV(6), // PWM9
		_BV(4), // PWM10
		_BV(5), // PWM11
		_BV(6), // PWM12
		_BV(7), // PWM13
		_BV(1), // USART3_TX
		_BV(0), // USART3_RX
		_BV(1), // USART2_TX
		_BV(0), // USART2_RX
		_BV(3), // USART1_TX
		_BV(2), // USART1_RX
		_BV(1), // I2C_SDA
		_BV(0), // I2C_SCL
		_BV(0), // D22
		_BV(1), // D23
		_BV(2), // D24
		_BV(3), // D25
		_BV(4), // D26
		_BV(5), // D27
		_BV(6), // D28
		_BV(7), // D29
		_BV(7), // D30
		_BV(6), // D31
		_BV(5), // D32
		_BV(4), // D33
		_BV(3), // D34
		_BV(2), // D35
		_BV(1), // D36
		_BV(0), // D37
		_BV(7), // D38
		_BV(2), // D39
		_BV(1), // D40
		_BV(0), // D41
		_BV(7), // D42
		_BV(6), // D43
		_BV(5), // D44
		_BV(4), // D45
		_BV(3), // D46
		_BV(2), // D47
		_BV(1), // D48
		_BV(0), // D49
		_BV(3), // SPI_MISO
		_BV(2), // SPI_MOSI
		_BV(1), // SPI_SCK
		_BV(0), // SPI_SS
		_BV(0), // A0
		_BV(1), // A1
		_BV(2), // A2
		_BV(3), // A3
		_BV(4), // A4
		_BV(5), // A5
		_BV(6), // A6
		_BV(7), // A7
		_BV(0), // A8
		_BV(1), // A9
		_BV(2), // A10
		_BV(3), // A11
		_BV(4), // A12
		_BV(5), // A13
		_BV(6), // A14
		_BV(7), // A15
	};

	const uint16_t PROGMEM digitalPinToTimerPGM[] =
	{
		// TIMERS (in CSV format)
		// Timer, Name
		NOT_ON_TIMER, 	// USART0_RX
		NOT_ON_TIMER, 	// USART0_TX
		TIMER3B, 		// PWM2
		TIMER3C, 		// PWM3
		TIMER0B, 		// PWM4
		TIMER3A, 		// PWM5
		TIMER4A, 		// PWM6
		TIMER4B, 		// PWM7
		TIMER4C, 		// PWM8
		TIMER2B, 		// PWM9
		TIMER2A, 		// PWM10
		TIMER1A, 		// PWM11
		TIMER1B, 		// PWM12
		TIMER0A, 		// PWM13
		NOT_ON_TIMER, 	// USART3_TX
		NOT_ON_TIMER, 	// USART3_RX
		NOT_ON_TIMER, 	// USART2_TX
		NOT_ON_TIMER, 	// USART2_RX
		NOT_ON_TIMER, 	// USART1_TX
		NOT_ON_TIMER, 	// USART1_RX
		NOT_ON_TIMER, 	// I2C_SDA
		NOT_ON_TIMER, 	// I2C_SCL
		NOT_ON_TIMER, 	// D22
		NOT_ON_TIMER, 	// D23
		NOT_ON_TIMER, 	// D24
		NOT_ON_TIMER, 	// D25
		NOT_ON_TIMER, 	// D26
		NOT_ON_TIMER, 	// D27
		NOT_ON_TIMER, 	// D28
		NOT_ON_TIMER, 	// D29
		NOT_ON_TIMER, 	// D30
		NOT_ON_TIMER, 	// D31
		NOT_ON_TIMER, 	// D32
		NOT_ON_TIMER, 	// D33
		NOT_ON_TIMER, 	// D34
		NOT_ON_TIMER, 	// D35
		NOT_ON_TIMER, 	// D36
		NOT_ON_TIMER, 	// D37
		NOT_ON_TIMER, 	// D38
		NOT_ON_TIMER, 	// D39
		NOT_ON_TIMER, 	// D40
		NOT_ON_TIMER, 	// D41
		NOT_ON_TIMER, 	// D42
		NOT_ON_TIMER, 	// D43
		TIMER5C, 		// D44
		TIMER5B, 		// D45
		TIMER5A, 		// D46
		NOT_ON_TIMER, 	// D47
		NOT_ON_TIMER, 	// D48
		NOT_ON_TIMER, 	// D49
		NOT_ON_TIMER, 	// SPI_MISO
		NOT_ON_TIMER, 	// SPI_MOSI
		NOT_ON_TIMER, 	// SPI_SCK
		NOT_ON_TIMER, 	// SPI_SS
		NOT_ON_TIMER, 	// A0
		NOT_ON_TIMER, 	// A1
		NOT_ON_TIMER, 	// A2
		NOT_ON_TIMER, 	// A3
		NOT_ON_TIMER, 	// A4
		NOT_ON_TIMER, 	// A5
		NOT_ON_TIMER, 	// A6
		NOT_ON_TIMER, 	// A7
		NOT_ON_TIMER, 	// A8
		NOT_ON_TIMER, 	// A9
		NOT_ON_TIMER, 	// A10
		NOT_ON_TIMER, 	// A11
		NOT_ON_TIMER, 	// A12
		NOT_ON_TIMER, 	// A13
		NOT_ON_TIMER, 	// A14
		NOT_ON_TIMER, 	// A15
	};
}

#endif /* END BOARD_ARDUINO_UNO_H */