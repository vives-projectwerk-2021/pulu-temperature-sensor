#ifndef TEMPERATURESENSORS_H
#define TEMPERATURESENSORS_H
#include "I2C.h"
#include "mbed.h"
#include <cstdint>

class TemperatureSensors {
    // public methods
    public:
        // constructor
        TemperatureSensors(I2C *i2c);
        
        // read temperature from within the tube
        double readGroundTemperature();

        // read temperature from top pcb
        double readMainTemperature();

    private:
        I2C *i2c;
    
    // adresses and pointers
    private:
        const char GroundTempAddr = 0x90;            // TCN75 address:      0x48<<1
        const char MainTempAddr = 0x92;              // TCN75 address:      0x49<<1

        const char ConfigPointer = 0x01;
        const char ConfigData = 0b01100000;

    // private methods
    private:
        double readTemperature(uint8_t address);
};

#endif