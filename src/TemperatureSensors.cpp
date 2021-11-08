#include "mbed.h"
#include "PinMap.h"
#include "TemperatureSensors.h"
#include <cstdint>
#include <cstdio>

TemperatureSensors::TemperatureSensors(I2C *i2c)
{
    this->i2c = i2c;
}

double TemperatureSensors::readGroundTemperature()
{
    return readTemperature(GroundTempAddr);
}

double TemperatureSensors::readMainTemperature()
{
    return readTemperature(MainTempAddr);
}

double TemperatureSensors::readTemperature(uint8_t address){
    char cmd[2] {0};                        // empty data buffer
    cmd[0] = ConfigPointer;                 // Pointer to CONFIG register
    cmd[1] = ConfigData;                    // Data for CONFOG register (for 12bit operation)
    i2c->write(address, cmd, 2);            // Send Address and command

    cmd[0] = 0x00;                          // set address to 0x00
    i2c->write(address, cmd, 1);            // Write adress/command byte, then register address
    i2c->read(address, cmd, 2);             // Read 2 bytes from TEMP register

    uint16_t temp = (cmd[0]<<8) | cmd[1];   // combine bytes
    return double(temp/256.0);
}
