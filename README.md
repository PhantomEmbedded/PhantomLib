# Phantom AVR Core
The aim is to improve the Arduino environment through the use of modern C++ techniques.

## Installation

HTTP
```bash
https://github.com/PhantomEmbedded/avr-core.git ~/Arduino/hardware/Phantom/avr
```
SSH
```bash
git clone git@github.com:PhantomEmbedded/avr-core.git ~/Arduino/hardware/Phantom/avr
```

You will need to restart yout Arduino IDE.

## Blink

```c++
#include <DigitalOutput.h>
#include <util/delay.h>

DigitalOutput out(GPIO::B, 5);

int main()
{
  while(true)
  {
    out.toggle();
    _delay_ms(500);
  }
}
```
