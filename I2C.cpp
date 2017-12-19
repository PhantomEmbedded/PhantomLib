#include "I2C.h"

I2C::I2C(uint8_t address):
{
	// Set I2C pins as input
	*sda.getModeRegister() &= ~sda.getBitMask();
	*scl.getModeRegister() &= ~scl.getBitMask();

	// Activate internal pullups
	*sda.getOutputRegister() |= sda.getBitMask();
	*scl.getOutputRegister() |= scl.getBitMask();

	// Set I2C prescaler
	TWSR &= ~_BV(TWPS0);
	TWSR &= ~_BV(TWPS1);

	// Set I2C bit rate
	TWBR = ((F_CPU / TWI_FREQ) - 16) / 2;

	// Enable I2C module, acks, and I2C interrupt
	TWCR = _BV(TWEN) | _BV(TWIE) | _BV(TWEA);

	// Set address
	setAddress(address);
}

I2C::~I2C()
{
	// Disable I2C module, acks, and I2C interrupt
	TWCR &= ~(_BV(TWEN) | _BV(TWIE) | _BV(TWEA));

	// Deactivate internal pullups for I2C
	*sda.getModeRegister() &= ~sda.getBitMask();
	*scl.getModeRegister() &= ~scl.getBitMask();
}

void I2C::write(uint8_t address, uint8_t byte)
{
	write(address, {byte});
}

void I2C::write(address, std::initializer_list<uint8_t> bytes)
{
	state = State::MasterTransmitter;

}

void I2C::setAddress(uint8_t address)
{
	TWAR = address << 1;
}

void I2C::setFrequency(Speed speed)
{
	TWBR = ((F_CPU / uint32_t(speed)) - 16) / 2;
}