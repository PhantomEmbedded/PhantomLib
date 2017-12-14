#include "NeoPixel.h"

using namespace Phantom;

NeoPixel::NeoPixel(
	Pin &pin,
	uint16_t pixelCount,
	ColorOffset offset,
	DatastreamSpeed speed):
		output(pin),
		pixelCount(pixelCount),
		offset(offset),
		speed(speed)
{
	output.set(false);
	pixels = new Pixel[pixelCount]
}

NeoPixel::~NeoPixel()
{
	delete[] pixels;
}

void NeoPixel::setPixel(uint16_t number,Pixel pixel)
{
	pixels[number] = pixel;
}

void NeoPixel::update() {
	for (uint16_t p = 0; p < pixelCount; ++p)
	{
		/*
		Data Transfer Times (all total 1.25us +/- 600ns)
		Logic 0:
			High 0.35us
			LOW  0.80us
		Logic 1:
			High 0.70us
			LOW  0.60us
		*/
		uint32_t data = pixels[p].red + (pixels[p].green << 8) + (pixels[p].blue << 16); // This order will have to change according to ColorOffset
		
		for (uint8_t bitIter = 0; bitIter < 24; ++bitIter)
		{
			if (data &= (1u << bitIter))
			{	// HIGH
				output.set(true);
				// Wait 0.70us
				output.set(false);
				// Wait 0.60us
			}
			else
			{	// LOW
				output.set(true);
				// Wait 0.35us
				output.set(false);
				// Wait 0.80us
			}
		}
	}
}