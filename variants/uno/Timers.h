#include <Timer.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

const PROGMEM Timer::TimerCounter8BitWithPWM TC0 = {&TCCR0A, &TCCR0B, &TIMSK0, &AVR_GTCCR, &TCNT0, &OCR0A, &OCR0B, &TIFR0};
const PROGMEM Timer::TimerCounter8BitWithPWM TC1 = {&TCCR1A, &TCCR1B, &TCCR1C, &TCNT1L, &TCNT1H, &ICR1L, &ICR1H, &OCR1AL, &OCR1AH, &OCR1BL, &OCR1BH, &TIMSK1, &TIFR1};
