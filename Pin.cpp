#include <Pin.h>

using namespace Phantom;

Pin::Pin(uint8_t number): number(number)
{
	port			= pgm_read_byte(digitalPinToPortPGM + (number));
	bitMask			= pgm_read_byte(digitalPinToBitMaskPGM + (number));
	analogBit		= number;
	timer			= (volatile uint16_t *)(pgm_read_byte(digitalPinToTimerPGM + (intptr_t)number));
	modeRegister	= (volatile uint16_t *)(pgm_read_word(portToModePGM + port));
	inputRegister	= (volatile uint16_t *)(pgm_read_word(portToInputPGM + port));
	outputRegister	= (volatile uint16_t *)(pgm_read_word(portToOutputPGM + port));
}

Pin::~Pin()
{
	// Delete pointers
	delete timer;
	delete modeRegister;
	delete inputRegister;
	delete outputRegister;
}

