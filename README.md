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
        ThisThread::sleep_for(1s);

        sensor.wake();
        ThisThread::sleep_for(60ms);
        
        // because printf doesn't support float values in mbed
        double Temperature = (1.0*sensor.temperature())/256;
        int tempIntegerPart = int(Temperature);
        int tempDecimalPart = (double(Temperature) - tempIntegerPart)*100;

        printf("Temperature:\t%i.%i°C\r\n", tempIntegerPart, tempDecimalPart);

        sensor.sleep();
    }
}
```
