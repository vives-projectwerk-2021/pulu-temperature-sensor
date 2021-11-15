# pulu-temperature-sensor
library for the pulu temperature sensors

## example
```c
#include "mbed.h"
#include "TCN75.h"

I2C i2c(I2C_SDA, I2C_SCL);

TCN75 sensor(&i2c, 0x48<<1);

int main()
{
    while (1) 
    {
        ThisThread::sleep_for(500ms);
        
        // because printf doesn't support float values in mbed
        double Temperature = sensor.temperature();
        int tempIntegerPart = int(Temperatue);
        int tempDecimalPart = (double(Temperature) - tempIntegerPart)*100;

        printf("Temperature:\t%i.%i°C\r\n", tempIntegerPart, tempDecimalPart);
    }
}
```
