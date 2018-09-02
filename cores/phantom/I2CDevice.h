#ifndef I2C_DEVICE_H
#define I2C_DEVICE_H

#include <I2C.h>

class I2CDevice
{
public:
	I2CDevice(I2C::Interface interface, uint8_t slave_address);

	void initalize();

	void write(uint8_t data);

private:
	const I2C::Interface interface;
	const uint8_t slave_address;

	void transmit_start();
	bool start_condition_sent();
	bool succsessful_start_condition_transmition();
	void set_slave_write_address(uint8_t address);
	bool address_packet_transmitted();
	bool succsessful_address_packet_transmition();
	void transmit_data(uint8_t data);
	bool data_transmitted();
	bool succsessful_data_transmition();
	void transmit_stop();
};

#endif