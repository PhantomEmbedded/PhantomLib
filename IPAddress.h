#ifndef IP_ADDRESS_H
#define IP_ADDRESS_H

#include <avr/pgmspace.h>
#include <avr/interrupt.h>

namespace Phantom
{
	template <typename T>
	class IPAddress
	{
	public:
		union IPV4
		{
			uint32_t address;
			struct
			{
				uint8_t first;
				uint8_t second;
				uint8_t third;
				uint8_t fourth;
			};
		};

		union IPV6
		{
			//uint128_t address; // Todo: find a good way to get a 128 bit type
			struct
			{
				uint16_t first;
				uint16_t second;
				uint16_t third;
				uint16_t fourth;
				uint16_t fifth;
				uint16_t sixth;
				uint16_t seventh;
				uint16_t eighth;
			};
		};

		IPAddress(T address);

		~IPAddress();

		// Inline functions
		T get() {return address;}

	private:
		T address;
		
	};
}

#endif /* END IP_ADDRESS_H */