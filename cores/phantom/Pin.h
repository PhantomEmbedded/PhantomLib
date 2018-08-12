#ifndef PIN_H
#define PIN_H

#include <avr/pgmspace.h>
#include <Boards/BoardBase.h>

namespace Phantom
{
	class Pin
	{
	public:
		Pin(uint8_t number);
		~Pin();
		
		uint8_t getNumber() {return number;}
		uint8_t getPort() {return port;}
		uint8_t getBitMask() {return bitMask;}
		uint8_t getAnalogBit() {return analogBit;} // Only for analog pins
		volatile uint16_t *getTimer() {return timer;}
		volatile uint16_t *getInputRegister() {return inputRegister;}
		volatile uint16_t *getOutputRegister() {return outputRegister;}
		volatile uint16_t *getModeRegister() {return modeRegister;}
	private:

		uint8_t number;
		// AVR
		uint8_t port, bitMask, analogBit;
		volatile uint16_t *timer, *modeRegister, *inputRegister, *outputRegister;
	};
}

#endif /* END PIN_H */