#include <USART.h>

using namespace Phantom;

USART::USART()
{
	uint8_t port = 0; // temp
	DR 		= (volatile uint16_t *)(pgm_read_word(USART_DR + port));
	CSR_A 	= (volatile uint16_t *)(pgm_read_word(USART_CSR_A + port));
	CSR_B 	= (volatile uint16_t *)(pgm_read_word(USART_CSR_B + port));
	CSR_C 	= (volatile uint16_t *)(pgm_read_word(USART_CSR_C + port));
	BRR_L 	= (volatile uint16_t *)(pgm_read_word(USART_BRR_L + port));
	BRR_H 	= (volatile uint16_t *)(pgm_read_word(USART_BRR_H + port));

	enable_rx();
	enable_tx();

	set_operating_mode(AsyncNormalMode);
	set_baud_rate(115200);
	set_frame_bits(8);
	set_parity(NoParity);
	set_stop_bits(1);
}

USART::~USART()
{
	disable_rx();
	disable_tx();
}

void USART::transmit(uint16_t data)
{
	while (!data_register_empty());

	if (frame_bits > 8)
	{
		if (data & 0x0100)
			set_bit(CSR_B, TXB80);
		else
			clear_bit(CSR_B, TXB80);
	}

	*DR = (uint8_t)data;
}

uint16_t USART::receive()
{
	uint16_t data;
	while (!data_received());

	if (frame_bits > 8)
	{
		uint8_t bit8 = (*CSR_B >> 1) & 0b1;
		data = ((bit8 << 8) | *DR);
	}
	else
		data = *DR;

	return data;
}

void USART::flush()
{
	uint8_t dummy;
	while (data_received())
		dummy = *DR;
}

void USART::enable_rx() 	{ set_bit(CSR_B, RXEN0); }

void USART::disable_rx() 	{ clear_bit(CSR_B, RXEN0); }

void USART::enable_tx() 	{ set_bit(CSR_B, TXEN0); }

void USART::disable_tx() 	{ clear_bit(CSR_B, TXEN0); }

void USART::set_operating_mode(OperatingMode mode)
{
	*CSR_C &= ~(0b11 << UMSEL00);

	*CSR_C |= (mode << UMSEL00);
}

void USART::set_baud_rate(uint32_t baud)
{
	uint32_t max_baud = (F_CPU / (16L * 4096L));

	if (baud < max_baud)
	{
		baud_rate = F_CPU / operating_mode / baud - 1;
		*BRR_H = (uint8_t)(baud_rate >> 8);
		*BRR_L = (uint8_t)(baud_rate);
	}
}

void USART::set_frame_bits(uint8_t n)
{
	frame_bits = n;

	*CSR_C &= ~(0b111 << UCSZ00);

	uint8_t output;
	switch (n)
	{
		case 5: output = 0b000; break;
		case 6: output = 0b001; break;
		case 7: output = 0b010; break;
		case 8: output = 0b011; break;
		case 9: output = 0b111; break;
		default: output = 0b011; break; // 8
	}

	*CSR_C |= (output << UCSZ00);
}

void USART::set_parity(ParityMode mode)
{
	parity_mode = mode;

	*CSR_C &= ~(0b111 << UMSEL00);

	*CSR_C |= (mode << UMSEL00);
}

void USART::set_stop_bits(uint8_t n)
{
	stop_bits = n;

	switch (n)
	{
		case 1: set_bit(CSR_B, USBS0); break;
		case 2: clear_bit(CSR_B, USBS0); break;
	}
}

bool USART::data_register_empty()
{
	// true: empty, false: full
	return *CSR_A & (1 << UDRE0);
}

bool USART::data_received()
{
	return *CSR_A & (1 << RXC0);
}

// Register Manipulation

void USART::clear_bit(volatile uint16_t *reg, uint8_t bit)
{
	*reg &= ~(1 << bit);
}

void USART::set_bit(volatile uint16_t *reg, uint8_t bit)
{
	*reg |= (1 << bit);
}