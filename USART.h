#ifndef USART_H
#define USART_H

#include <Boards/BoardBase.h>
#include <avr/pgmspace.h>

namespace Phantom
{
	class USART
	{
	public:
		enum OperatingMode
		{
			AsyncNormalMode = 16,
			AsyncDoubleSpeedMode = 8,
			SyncMasterMode = 2
		};

		enum ParityMode
		{
			NoParity	= 0b00,
			EnabledEven = 0b10,
			EnabledOdd 	= 0b11
		};

		enum ClockPolarityMode
		{
			TXRisingRXFalling = 0,
			RXRisingTXFalling = 1
		};

		USART();
		USART(
			OperatingMode mode,
			uint32_t baud_rate,
			uint8_t frame_bits,
			uint8_t parity_bits,
			uint8_t stop_bits
		);
		~USART();

		void transmit(uint16_t data);
		uint16_t receive();

		void set_operating_mode(OperatingMode mode);
		void set_baud_rate(uint32_t baud);
		void set_frame_bits(uint8_t bits);
		void set_parity(ParityMode mode);
		void set_stop_bits(uint8_t bits);

	private:
		// Registers
		volatile uint16_t *DR;
		volatile uint16_t *CSR_A;
		volatile uint16_t *CSR_B;
		volatile uint16_t *CSR_C;
		volatile uint16_t *BRR_L;
		volatile uint16_t *BRR_H;

		OperatingMode operating_mode;
		uint32_t baud_rate, baud_rate_max;
		uint8_t frame_bits;
		ParityMode parity_mode;
		uint8_t stop_bits;

		// enable/disable rx/tx
		void enable_rx();
		void disable_rx();
		void enable_tx();
		void disable_tx();

		// status helpers
		bool data_register_empty();
		bool data_received();

		// register helper functions
		void clear_bit(volatile uint16_t *reg, uint8_t bit);
		void set_bit(volatile uint16_t *reg, uint8_t bit);
	};
}

#endif /* USART_H */