#include <USART.h>

USART::USART(OperatingMode mode, uint16_t baud, uint8_t bits, uint8_t parity, uint8_t stop)
{
	uint8_t port = 0; // temp
	DR 		= (volatile uint16_t *)(pgm_read_word(USART_DR + port));
	CSR_A 	= (volatile uint16_t *)(pgm_read_word(USART_CSR_A + port));
	CSR_B 	= (volatile uint16_t *)(pgm_read_word(USART_CSR_B + port));
	CSR_C 	= (volatile uint16_t *)(pgm_read_word(USART_CSR_C + port));
	BRR_L 	= (volatile uint16_t *)(pgm_read_word(USART_BRR_L + port));
	BRR_H 	= (volatile uint16_t *)(pgm_read_word(USART_BRR_L + port));
}

// Register Manipulation

void USART::write_io_register(uint8_t data)
{
	*DR = data;
}

uint8_t USART::read_io_register()
{
	return *DR;
}

bool USART::receive_complete()
{
	return *CSR_A & (1 << RXC);
}

bool USART::transmit_complete()
{
	return *CSR_A & (1 << TXC);
}

void USART::transmit_complete(bool state)
{
	if (state)
		*CSR_A |= (1 << TXC);
	else
		*CSR_A &= ~(1 << TXC);
}

bool USART::data_register_empty()
{
	return *CSR_A & (1 << UDRE);
}

bool USART::frame_error()
{
	return *CSR_A & (1 << FE);
}

bool USART::data_overrun()
{
	return *CSR_A & (1 << DOR);
}

bool USART::parity_error()
{
	return *CSR_A & (1 << UPE)
}

void USART::double_transmission_speed(bool state)
{
	if (state)
		*CSR_A |= (1 << U2X);
	else
		*CSR_A &= ~(1 << U2X);
}

bool USART::double_transmission_speed()
{
	return *CSR_A & (1 << U2X);
}

void USART::multi_processor_communication_mode(bool state)
{
	if (state)
		*CSR_A |= (1 << MPCM);
	else
		*CSR_A &= ~(1 << MPCM);
}

bool USART::rx_complete_interrupt_enable()
{

}

void USART::rx_complete_interrupt_enable(bool enabled)
{

}

bool USART::tx_complete_interrupt_enable()
{

}

void USART::tx_complete_interrupt_enable(bool enabled)
{

}

bool USART::data_register_empty_interrupt_enable()
{

}

void USART::data_register_empty_interrupt_enable(bool enabled)
{

}

bool USART::rx_enable()
{

}

void USART::rx_enable(bool enabled)
{

}

bool USART::tx_enable()
{

}

void USART::tx_enable(bool enabled)
{

}

void USART::frame_character_size(uint8_t size)
{

}

bool USART::rx_data_bit_8()
{

}

bool USART::tx_data_bit_8()
{

}

void USART::tx_data_bit_8(bool state)
{

}

OperatingMode USART::mode_select()
{

}

void USART::mode_select(OperatingMode mode)
{

}

ParityMode USART::parity_mode()
{

}

void USART::parity_mode(ParityMode mdoe)
{

}

uint8_t USART::stop_bits()
{

}

void USART::stop_bits()
{

}

ClockPolarityMode USART::clock_polarity()
{

}

void USART::clock_polarity(ClockPolarityMode mode)
{

}