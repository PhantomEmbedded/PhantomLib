#ifndef I2C_H
#define I2C_H

#include <util/twi.h>
#include <initializer_list>

#include "Pin.h"

namespace Phantom
{
	class I2C
	{
	public:
		enum State
		{
			Ready,
			MasterReceiver,
			MasterTransmitter,
			SlaveReceiver,
			SlaceTransmitter
		};

		enum Speed
		{
			Normal = 100000,
			Fast = 400000
		};

		I2C(uint8_t address);
		~I2C();

		void write(uint8_t byte);
		void write(std::initializer_list<uint8_t> bytes);

		uint8_t read();
		uint8_t* read(uint8_t byteCount);

		// I2C Parameters
		void setAddress(uint8_t address);
		void setFrequency(Speed speed);
		
	private:
		Pin sda(I2C_SDA);
		Pin scl(I2C_SCL);

		uint8_t address;

		State state = State::Ready;
		Speed speed = Speed::Normal;

		const uint8_t BUFFER_LENGTH = 32;
		uint8_t buffer[BUFFER_LENGTH];

		uint8_t address;
	};
}

#endif /* END I2C_H */