#ifndef USART_H
#define USART_H

#include <BoardBase.h>

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
		}

		enum ParityMode
		{
			Disabled,
			Reserved,
			EnabledEven,
			EnabledOdd
		}

		enum ClockPolarityMode
		{
			TXRisingRXFalling = 0,
			RXRisingTXFalling = 1
		}

		USART(OperatingMode mode, uint16_t baud, uint8_t bits, uint8_t parity, uint8_t stop);
		~USART();
	private:
		// Registers
		volatile uint16_t *DR;
		volatile uint16_t *CSR_A;
		volatile uint16_t *CSR_B;
		volatile uint16_t *CSR_C;
		volatile uint16_t *BRR_L;
		volatile uint16_t *BRR_H;

		// USART I/O Data Register 0
		void write_io_register(uint8_t data);
		uint8_t read_io_register();

		// USART Control and Status Register A
		bool receive_complete();	// RXC
		bool transmit_complete();	// TXC
		void transmit_complete(bool state);	// TXC
		bool data_register_empty(); // UDRE
		bool frame_error();			// FE
		bool data_overrun();		// DOR
		bool parity_error();		// UPE
		void double_transmission_speed(bool state); // U2X
		bool double_transmission_speed(); // U2X
		void multi_processor_communication_mode(bool state); // MPCM
		bool multi_processor_communication_mode(); // MPCM

		// USART Control and Status Register B
		bool rx_complete_interrupt_enable();
		void rx_complete_interrupt_enable(bool enabled);
		bool tx_complete_interrupt_enable();
		void tx_complete_interrupt_enable(bool enabled);
		bool data_register_empty_interrupt_enable();
		void data_register_empty_interrupt_enable(bool enabled);
		bool rx_enable();
		void rx_enable(bool enabled);
		bool tx_enable();
		void tx_enable(bool enabled);
		void frame_character_size(uint8_t size);
		bool rx_data_bit_8();
		bool tx_data_bit_8();
		void tx_data_bit_8(bool state);

		// USART Control and Status Register C
		OperatingMode mode_select();
		void mode_select(OperatingMode mode);
		ParityMode parity_mode();
		void parity_mode(ParityMode mdoe);
		uint8_t stop_bits();
		void stop_bits();
			// Character size defined in register B section
		ClockPolarityMode clock_polarity();
		void clock_polarity(ClockPolarityMode mode);

	};
}

#endif /* USART_H */