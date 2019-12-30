#include "I2CDevice.h"

I2CDevice::I2CDevice(I2C::Interface interface, uint8_t slave_address):
	interface(interface),
	slave_address(slave_address)
{
	initalize();
}

void I2CDevice::initalize()
{
	*interface.status_register &= ~((1<<TWPS0)|(1<<TWPS1)); // prescaler to 00
	*interface.bit_rate_register = ((F_CPU / 100000L) - 16) / 2; // bit rate

	// set pullups
	*interface.pin.scl.port.output_register |= (1<<interface.pin.scl.bit);
	*interface.pin.sda.port.output_register |= (1<<interface.pin.sda.bit);

	// enable i2c module, acks, i2c interrupt
	*interface.control_register = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
}

void I2CDevice::write(uint8_t data)
{
	transmit_start();

	while(!start_condition_sent());

	if (!succsessful_start_condition_transmition())
		{/* todo: error handler */}

	set_slave_write_address(slave_address);

	while(!address_packet_transmitted());

	if (!succsessful_address_packet_transmition())
		{/* todo: error handler */}

	transmit_data(data);

	while(!data_transmitted());

	if (!succsessful_data_transmition())
		{/* todo: error handler */}

	transmit_stop();
}

void I2CDevice::transmit_start()
{
	*interface.control_register = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
}

bool I2CDevice::start_condition_sent()
{
	return (*interface.control_register & (1<<TWINT));
}

bool I2CDevice::succsessful_start_condition_transmition()
{
	return (*interface.status_register & 0xF8) == TW_START;
}

void I2CDevice::set_slave_write_address(uint8_t address)
{
	uint8_t sla_w = TW_WRITE;
	sla_w |= address << 1;
	*interface.data_register = sla_w;
	*interface.control_register = (1<<TWINT)|(1<<TWEN);
}

bool I2CDevice::address_packet_transmitted()
{
	return *interface.control_register & (1<<TWINT);
}

bool I2CDevice::succsessful_address_packet_transmition()
{
	return (*interface.status_register & 0xF8) == TW_MT_SLA_ACK;
}

void I2CDevice::transmit_data(uint8_t data)
{
	*interface.data_register = data;
	*interface.control_register = (1<<TWINT)|(1<<TWEN);
}

bool I2CDevice::data_transmitted()
{
	return *interface.control_register & (1<<TWINT);
}

bool I2CDevice::succsessful_data_transmition()
{
	return (*interface.status_register & 0xF8) == TW_MT_DATA_ACK;
}

void I2CDevice::transmit_stop() {
	*interface.control_register = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}