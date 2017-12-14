#ifndef PHANTOM_H
#define PHANTOM_H

inline void sfrClearBit(uint8_t sfr, uint8_t bit)
{
	_SFR_BYTE(sfr) &= ~_BV(bit);
}

inline void sfrSetBit(uint8_t sfr, uint8_t bit)
{
	_SFR_BYTE(sfr) |= _BV(bit);
}


#endif /* END PHANTOM_H */