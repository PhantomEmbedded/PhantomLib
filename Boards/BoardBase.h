#ifndef BOARD_BASE
#define BOARD_BASE

#include <avr/pgmspace.h>
#include <avr/io.h>
#include "../Phantom.h"

const uint8_t NOT_A_PIN = 0;
const uint8_t NOT_A_PORT = 0;

const uint8_t NOT_AN_INTERRUPT = -1;

const uint8_t PA = 1;
const uint8_t PB = 2;
const uint8_t PC = 3;
const uint8_t PD = 4;
const uint8_t PE = 5;
const uint8_t PF = 6;
const uint8_t PG = 7;
const uint8_t PH = 8;
const uint8_t PJ = 10;
const uint8_t PK = 11;
const uint8_t PL = 12;

const uint8_t NOT_ON_TIMER = 0;
const uint8_t TIMER0A = 1;
const uint8_t TIMER0B = 2;
const uint8_t TIMER1A = 3;
const uint8_t TIMER1B = 4;
const uint8_t TIMER1C = 5;
const uint8_t TIMER2  = 6;
const uint8_t TIMER2A = 7;
const uint8_t TIMER2B = 8;
const uint8_t TIMER3A = 9;
const uint8_t TIMER3B = 10;
const uint8_t TIMER3C = 11;
const uint8_t TIMER4A = 12;
const uint8_t TIMER4B = 13;
const uint8_t TIMER4C = 14;
const uint8_t TIMER4D = 15;
const uint8_t TIMER5A = 16;
const uint8_t TIMER5B = 17;
const uint8_t TIMER5C = 18;

// External arrays defined in board header
extern const uint16_t portToModePGM[];
extern const uint16_t portToInputPGM[];
extern const uint16_t portToOutputPGM[];
extern const uint16_t digitalPinToTimerPGM[];
extern const uint8_t digitalPinToPortPGM[];
extern const uint8_t digitalPinToBitMaskPGM[];

#endif /* END BOARD_BASE */