#include "EEPROM.h"

using namespace EEPROM;

bool EEPROM::ready()
{
	// if EEWE is 0, EEPROM is ready
	return !(EECR & (1 << EEPE));
}

uint8_t EEPROM::read_byte(const uint8_t * address)
{
	return eeprom_read_byte(address);
}

uint16_t EEPROM::read_word(const uint16_t * address)
{
	return eeprom_read_word(address);
}

uint32_t EEPROM::read_dword(const uint32_t * address)
{
	return eeprom_read_dword(address);
}

float EEPROM::read_float(const float * address)
{
	return eeprom_read_float(address);
}

void EEPROM::write_byte(uint8_t * address, uint8_t value)
{
	eeprom_write_byte(address, value);
}

void EEPROM::write_word(uint16_t * address, uint16_t value)
{
	eeprom_write_word(address, value);
}

void EEPROM::write_dword(uint32_t * address, uint32_t value)
{
	eeprom_write_dword(address, value);
}

void EEPROM::write_float(float * address, float value)
{
	eeprom_write_float(address, value);
}

void EEPROM::update_byte(uint8_t * address, uint8_t value)
{
	eeprom_update_byte(address, value);
}

void EEPROM::update_word(uint16_t * address, uint16_t value)
{
	eeprom_update_word(address, value);
}

void EEPROM::update_dword(uint32_t * address, uint32_t value)
{
	eeprom_update_dword(address, value);
}

void EEPROM::update_float(float * address, float value)
{
	eeprom_update_float(address, value);
}
