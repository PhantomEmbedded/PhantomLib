#include "PWMOutput.h"

using namespace Phantom;

PWMOutput::PWMOutput(Pin &pin): pin(pin)
{
	if (pin.getPort() == 0) return; // Check if valid

	// Set mode to output
	uint8_t oldSREG = SREG;
	cli();
	*pin.getModeRegister() |= pin.getBitMask();
	SREG = oldSREG;
}

PWMOutput::~PWMOutput()
{
	// Return pin mode to input
	uint8_t bit = pin.getBitMask();

	uint8_t oldSREG = SREG;
	cli();
	*pin.getModeRegister() &= ~bit;
	*pin.getOutputRegister() |= bit;

	// Todo: turn timer off
}

void PWMOutput::set(uint8_t value) {
	if (value == 0)
	{
		uint8_t oldSREG = SREG;
		cli();
		*pin.getOutputRegister() &= ~pin.getBitMask();
		SREG = oldSREG;
	}
	else if (value = 255)
	{
		uint8_t oldSREG = SREG;
		cli();
		*pin.getOutputRegister() |= pin.getBitMask();
		SREG = oldSREG;
	}
	else
	{
		switch(pin.getTimer())
		{
			// XXX fix needed for atmega8
			#if defined(TCCR0) && defined(COM00) && !defined(__AVR_ATmega8__)
			case TIMER0A:
				// connect pwm to pin on timer 0
				sfrSetBit(TCCR0, COM00);
				OCR0 = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR0A) && defined(COM0A1)
			case TIMER0A:
				// connect pwm to pin on timer 0, channel A
				sfrSetBit(TCCR0A, COM0A1);
				OCR0A = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR0A) && defined(COM0B1)
			case TIMER0B:
				// connect pwm to pin on timer 0, channel B
				sfrSetBit(TCCR0A, COM0B1);
				OCR0B = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR1A) && defined(COM1A1)
			case TIMER1A:
				// connect pwm to pin on timer 1, channel A
				sfrSetBit(TCCR1A, COM1A1);
				OCR1A = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR1A) && defined(COM1B1)
			case TIMER1B:
				// connect pwm to pin on timer 1, channel B
				sfrSetBit(TCCR1A, COM1B1);
				OCR1B = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR1A) && defined(COM1C1)
			case TIMER1C:
				// connect pwm to pin on timer 1, channel B
				sfrSetBit(TCCR1A, COM1C1);
				OCR1C = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR2) && defined(COM21)
			case TIMER2:
				// connect pwm to pin on timer 2
				sfrSetBit(TCCR2, COM21);
				OCR2 = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR2A) && defined(COM2A1)
			case TIMER2A:
				// connect pwm to pin on timer 2, channel A
				sfrSetBit(TCCR2A, COM2A1);
				OCR2A = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR2A) && defined(COM2B1)
			case TIMER2B:
				// connect pwm to pin on timer 2, channel B
				sfrSetBit(TCCR2A, COM2B1);
				OCR2B = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR3A) && defined(COM3A1)
			case TIMER3A:
				// connect pwm to pin on timer 3, channel A
				sfrSetBit(TCCR3A, COM3A1);
				OCR3A = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR3A) && defined(COM3B1)
			case TIMER3B:
				// connect pwm to pin on timer 3, channel B
				sfrSetBit(TCCR3A, COM3B1);
				OCR3B = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR3A) && defined(COM3C1)
			case TIMER3C:
				// connect pwm to pin on timer 3, channel C
				sfrSetBit(TCCR3A, COM3C1);
				OCR3C = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR4A)
			case TIMER4A:
				//connect pwm to pin on timer 4, channel A
				sfrSetBit(TCCR4A, COM4A1);
				#if defined(COM4A0)		// only used on 32U4
				cbi(TCCR4A, COM4A0);
				#endif
				OCR4A = value;	// set pwm duty
				break;
			#endif
			
			#if defined(TCCR4A) && defined(COM4B1)
			case TIMER4B:
				// connect pwm to pin on timer 4, channel B
				sfrSetBit(TCCR4A, COM4B1);
				OCR4B = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR4A) && defined(COM4C1)
			case TIMER4C:
				// connect pwm to pin on timer 4, channel C
				sfrSetBit(TCCR4A, COM4C1);
				OCR4C = value; // set pwm duty
				break;
			#endif
				
			#if defined(TCCR4C) && defined(COM4D1)
			case TIMER4D:				
				// connect pwm to pin on timer 4, channel D
				sfrSetBit(TCCR4C, COM4D1);
				#if defined(COM4D0)		// only used on 32U4
				cbi(TCCR4C, COM4D0);
				#endif
				OCR4D = value;	// set pwm duty
				break;
			#endif

							
			#if defined(TCCR5A) && defined(COM5A1)
			case TIMER5A:
				// connect pwm to pin on timer 5, channel A
				sfrSetBit(TCCR5A, COM5A1);
				OCR5A = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR5A) && defined(COM5B1)
			case TIMER5B:
				// connect pwm to pin on timer 5, channel B
				sfrSetBit(TCCR5A, COM5B1);
				OCR5B = value; // set pwm duty
				break;
			#endif

			#if defined(TCCR5A) && defined(COM5C1)
			case TIMER5C:
				// connect pwm to pin on timer 5, channel C
				sfrSetBit(TCCR5A, COM5C1);
				OCR5C = value; // set pwm duty
				break;
			#endif

			case NOT_ON_TIMER:
			default:
				uint8_t bit = pin.getBitMask();
				volatile uint16_t *out = pin.getOutputRegister();

				uint8_t oldSREG = SREG;
				cli();

				if (value < 128) {
					*out &= ~bit;
				} else {
					*out |= bit;
				}

				SREG = oldSREG;
		}
	}
}