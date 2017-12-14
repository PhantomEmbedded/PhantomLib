#ifndef NEO_PIXEL_H
#define NEO_PIXEL_H

#include "Pin.h"
#include "DigitalOutput.h"
#include <vector>

namespace Phantom
{
	class NeoPixel
	{
	public:
		enum ColorOffset
		{
			// Todo
		}

		enum DatastreamSpeed
		{
			400KHz
			800KHz
		}

		struct Pixel
		{
			uint8_t red;
			uint8_t green;
			uint8_t blue;
		}

		NeoPixel(
			Pin &pin,
			uint16_t pixelCount,
			ColorOffset offset,
			DatastreamSpeed speed);
		~NeoPixel();

		void setPixel(Pixel pixel); // Change led value in buffer

		void update(); // Update led string
	private:
		// Hardware Interface
		Pin pin;
		DigitalOutput output;

		// Software Inferface
		uint16_t pixelCount;
		ColorOffset offset;
		DatastreamSpeed speed;

		// Pixel data
		Pixel *pixels;
	};
}

#endif /* END NEO_PIXEL_H */