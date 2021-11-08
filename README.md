# pulu-temperature-sensor
library for the pulu temperature sensors

## example
```c
#include "mbed.h"
#include "TemperatureSensors.h"

I2C i2c(I2C_SDA, I2C_SCL);

TemperatureSensors temp(&i2c);

int main()
{
    while (1) 
    {
        ThisThread::sleep_for(500ms);
        printf("Temperatue:\t%i°C\r\n", int(temp.readGroundTemperature()*1000));
    }
}
```
