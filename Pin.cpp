#include "Pin.h"

using namespace Phantom;

Pin::Pin(uint8_t number): number(number)
{
	port			= pgm_read_byte(digitalPinToPortPGM + (number));
	bitMask			= pgm_read_byte(digitalPinToBitMaskPGM + (number));
	timer			= pgm_read_byte(digitalPinToTimerPGM + (number));
	analogBit		= number;
	modeRegister	= (volatile uint16_t *)(pgm_read_word(portToModePGM + (port)));
	inputRegister	= (volatile uint16_t *)(pgm_read_word(portToOutputPGM + (port)));
	outputRegister	= (volatile uint16_t *)(pgm_read_word(portToInputPGM + (port)));
}

Pin::~Pin()
{
	
}

