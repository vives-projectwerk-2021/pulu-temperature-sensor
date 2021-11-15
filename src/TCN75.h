#pragma once

#include "mbed.h"
 
class TCN75 {
    public:
        TCN75(I2C* i2c, uint16_t address);

        void sleep();
        void wake();

        uint16_t temperature();
    
    private:
        I2C* i2c;
        uint16_t address;
    
    private:
        const char ConfigPointer = 0x01;
        const char ConfigData = 0b01100000;
};