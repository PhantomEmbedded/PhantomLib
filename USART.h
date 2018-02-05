#ifndef USART_H
#define USART_H

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

		USART(OperatingMode mode, uint16_t baud, uint8_t bits, uint8_t parity, uint8_t stop);
		~USART();
	private:
		// USART Control and Status Register 0 A
		bool get_receive_complete();	// RXC0
		bool get_transmit_complete();	// TXC0
		void set_transmit_complete(bool state);	// TXC0
		bool get_data_register_empty(); // UDRE0
		bool get_frame_error();			// FE0
		bool get_data_overrun();		// DOR0
		bool get_parity_error();		// UPE0
		void set_double_transmission_speed(bool state); // U2X0
		bool get_double_transmission_speed(); // U2X0
		void set_multi_processor_communication_mode(bool state); // MPCM0

		// USART Control and Status Register 0 B

	};
}

#endif /* USART_H */