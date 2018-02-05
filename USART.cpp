#include <USART.h>

USART::USART(OperatingMode mode, uint16_t baud, uint8_t bits, uint8_t parity, uint8_t stop)
{
	// Set baud rate
	uint16_t UBRRn = (F_CPU / (mode * baud)) - 1; 
	UBRR0H = (uint8_t) (UBRRn >> 8);
	UBRR0L = (uint8_t) (UBRRn);

	// Enable Receiver and Transmitter
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);

	// Set frame format (8 data, 2 stop bit). This needs to be changed to be automatic
	switch (stop)
	{
		case 1: UCSR0C &= ~(1<<USBS0); break;
		case 2: UCSR0C |= (1<<USBS0);  break;
	}

	uint8_t char_size_setting;
	switch (bits)
	{
		case 5: char_size_setting = 0b000; break;
		case 6: char_size_setting = 0b001; break;
		case 7: char_size_setting = 0b010; break;
		case 8: char_size_setting = 0b011; break;
		case 9: char_size_setting = 0b111; break;
	}

}