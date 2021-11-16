#pragma once

#include "mbed.h"
 
class TCN75 {
    public:
        TCN75(I2C* i2c, uint8_t address);

        bool sleep();
        bool wake();

        int16_t temperature(bool* error = nullptr);
    
    private:
        I2C* i2c;
        uint8_t address;
    
    private:
        const char ConfigPointer = 0x01;
        const char ConfigData = 0b01100000;
};