#ifndef SERIAL_BASE_H
#define SERIAL_BASE_H

namespace Serial
{
	typedef struct
	{
		volatile uint8_t * const data_register;
		struct {
			volatile uint8_t * const A;
			volatile uint8_t * const B;
			volatile uint8_t * const C;
		} control_and_satus_register;
		struct {
			volatile uint8_t * const L;
			volatile uint8_t * const H;
		} baud_rate_register;
	} Transceiver;
}

#endif
