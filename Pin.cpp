#include "Pin.h"

using namespace Phantom;

Pin::Pin(uint8_t number): number(number)
{
	port			= pgm_read_byte(digitalPinToPortPGM + (number));
	bitMask			= pgm_read_byte(digitalPinToBitMaskPGM + (number));
	timer			= pgm_read_byte(digitalPinToTimerPGM + (number) );
	bit				= number;
	inputRegister	= (volatile uint8_t *)(pgm_read_word(portToOutputPGM + (number)));
	outputRegister	= (volatile uint8_t *)(pgm_read_word(portToInputPGM + (number)));
	modeRegister	= (volatile uint8_t *)(pgm_read_word(portToModePGM + (number)));
}

Pin::~Pin()
{
	
}