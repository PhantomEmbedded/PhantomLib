#ifndef PIN_H
#define PIN_H

namespace Bubble
{
	class Pin
	{
	public:
		Pin(uint8_t number);
		~Pin();
	
	private:
		uint8_t number;
	};
}

#endif /* END PIN_H */