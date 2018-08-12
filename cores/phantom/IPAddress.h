#ifndef IP_ADDRESS_H
#define IP_ADDRESS_H

namespace Phantom
{
	union IPv4
	{
		uint32_t ip;
		struct
		{
			uint8_t first;
			uint8_t second;
			uint8_t third;
			uint8_t fourth;
		};
	};

	union IPv6
	{
		// 128 bit return type no yet available
		struct
		{
			uint16_t first;
			uint16_t second;
			uint16_t third;
			uint16_t fourth;
			uint16_t fifth;
			uint16_t sixth;
			uint16_t seventh;
			uint16_t eigth;
		};
	};
}

#endif /* END IP_ADDRESS_H */