#ifndef PIN_H
#define PIN_H

#include <avr/pgmspace.h>

// External arrays defined in board header
extern const uint16_t PROGMEM portToModePGM[];
extern const uint16_t PROGMEM portToInputPGM[];
extern const uint16_t PROGMEM portToOutputPGM[];
extern const uint8_t PROGMEM digitalPinToPortPGM[];
extern const uint8_t PROGMEM digitalPinToBitMaskPGM[];
extern const uint8_t PROGMEM digitalPinToTimerPGM[];

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
		uint8_t getTimer() {return timer;}
		uint8_t getAnalogBit() {return analogBit;} // Only for analog pins
		uint16_t getInputRegister() {return inputRegister;}
		uint16_t getOutputRegister() {return outputRegister;}
		uint16_t getModeRegister() {return modeRegister;}
	private:
		uint8_t number;
		// AVR
		uint8_t port, bitMask, timer, analogBit;
		volatile uint16_t modeRegister, inputRegister, outputRegister;
	};
}

#endif /* END PIN_H */