#include "TCN75.h"

TCN75::TCN75(I2C* i2c, uint8_t address) {
    this->i2c = i2c;
    this->address = address;
}

/** Set the register to enter sleep mode
 * @return 0 on success
 */
bool TCN75::sleep()
{
    char cmd[2] {0};                        // empty data buffer
    cmd[0] = ConfigPointer;                 // Pointer to CONFIG register
    cmd[1] = 0b00000001;                    // Data for CONFOG register (enter sleep mode)
    return i2c->write(address, cmd, 2);     // Send Address and command
}

/** Set the register to leave sleep mode
 * @return 0 on success
 */
bool TCN75::wake()
{
    char cmd[2] {0};                        // empty data buffer
    cmd[0] = ConfigPointer;                 // Pointer to CONFIG register
    cmd[1] = 0b00000000;                    // Data for CONFOG register (leave sleep mode)
    return i2c->write(address, cmd, 2);     // Send Address and command
}

/** Read the register containing the temperature
 *  @return real temperature * 256
 */
int16_t TCN75::temperature(bool* error) {
    bool ack;
    char cmd[2] {0};                        // empty data buffer
    cmd[0] = ConfigPointer;                 // Pointer to CONFIG register
    cmd[1] = ConfigData;                    // Data for CONFOG register (for 12bit operation)
    ack = i2c->write(address, cmd, 2);      // Send Address and command
    if(ack) {
        if(error != nullptr) *error = true;
        return 0;
    }

    cmd[0] = 0x00;                          // set address to 0x00
    ack = i2c->write(address, cmd, 1);      // Write adress/command byte, then register address
    if(ack) {
        if(error != nullptr) *error = true;
        return 0;
    }
    ack = i2c->read(address, cmd, 2);             // Read 2 bytes from TEMP register
    if(ack) {
        if(error != nullptr) *error = true;
        return 0;
    }
    uint16_t temp = (cmd[0]<<8) | cmd[1];   // combine bytes
    if(error != nullptr) *error = false;
    return temp;
}