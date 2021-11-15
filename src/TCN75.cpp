#include "TCN75.h"

TCN75::TCN75(I2C* i2c, uint16_t address) {
    this.i2c = i2c
    this.address = address
}

void TemperatureSensors::sleep()
{
    char cmd[2] {0};                        // empty data buffer
    cmd[0] = ConfigPointer;                 // Pointer to CONFIG register
    cmd[1] = 0b00000001;                    // Data for CONFOG register (enter sleep mode)
    i2c->write(address, cmd, 2);            // Send Address and command
}

void TemperatureSensors::wake()
{
    char cmd[2] {0};                        // empty data buffer
    cmd[0] = ConfigPointer;                 // Pointer to CONFIG register
    cmd[1] = 0b00000000;                    // Data for CONFOG register (leave sleep mode)
    i2c->write(address, cmd, 2);            // Send Address and command
}

uint16_t TCN75::temperature() {
    char cmd[2] {0};                        // empty data buffer
    cmd[0] = ConfigPointer;                 // Pointer to CONFIG register
    cmd[1] = ConfigData;                    // Data for CONFOG register (for 12bit operation)
    i2c->write(address, cmd, 2);            // Send Address and command

    cmd[0] = 0x00;                          // set address to 0x00
    i2c->write(address, cmd, 1);            // Write adress/command byte, then register address
    i2c->read(address, cmd, 2);             // Read 2 bytes from TEMP register

    uint16_t temp = (cmd[0]<<8) | cmd[1];   // combine bytes
    return temp;
}