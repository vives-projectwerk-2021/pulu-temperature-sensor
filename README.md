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
        
        // because printf doesn't support float values in mbed
        double Temperature = temp.readGroundTemperature();
        int tempIntegerPart = int(Temperatue);
        int tempDecimalPart = (double(Temperature) - tempIntegerPart)*100;

        printf("Temperature:\t%i.%i°C\r\n", tempIntegerPart, tempDecimalPart);
    }
}
```
