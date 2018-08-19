# Phantom AVR Core
The aim is to improve the Arduino environment through the use of modern C++ techniques.

# Blink

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
