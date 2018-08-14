#ifndef EEPROM_H
#define EEPROM_H

#include <avr/eeprom.h>
#include <avr/io.h>

namespace EEPROM
{
	bool ready();

	uint8_t read_byte(const uint8_t * address);
	uint16_t read_word(const uint16_t * address);
	uint32_t read_dword(const uint32_t * address);
	float read_float(const float * address);

	void write_byte(uint8_t * address, uint8_t value);
	void write_word(uint16_t * address, uint16_t value);
	void write_dword(uint32_t * address, uint32_t value);
	void write_float(float * address, float value);

	void update_byte(uint8_t * address, uint8_t value);
	void update_word(uint16_t * address, uint16_t value);
	void update_dword(uint32_t * address, uint32_t value);
	void update_float(float * address, float value);
}

#endif
