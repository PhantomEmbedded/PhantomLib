#ifndef PIN_H
#define PIN_H

#include <avr/pgmspace.h>

namespace Bubble
{
	class Pin
	{
	public:
		Pin(uint8_t number);
		~Pin();
		
		uint8_t getNumber() {return number;}
		uint8_t getPort() {return port;}
		uint8_t getBitMask() {return bitMask;}
		uint8_t getTimer() {return timer;}
		uint8_t getBit() {return analogBit;} // Only for analog pins
		uint8_t getInputRegister() {return inputRegister;}
		uint8_t getOutputRegister() {return outputRegister;}
		uint8_t getModeRegister() {return modeRegister;}
	private:
		uint8_t number;
		// AVR
		uint8_t port, bitMask, timer, analogBit, inputRegister, outputRegister, modeRegister;
	};
}

#endif /* END PIN_H */