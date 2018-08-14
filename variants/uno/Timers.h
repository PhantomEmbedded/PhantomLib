#include <Timer.h>
#include <avr/io.h>

Timer::TimerCounter8BitWithPWM TC0 = {TCCR0A, TCCR0B, TIMSK0, AVR_GTCCR, TCNT0, OCR0A, OCR0B, TIFR0};
