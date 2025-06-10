#ifndef __CSL_PIN_COMMUNICATION
#define __CSL_PIN_COMMUNICATION

#include "main.h"

namespace csl {
    enum Protocol {
        I2C,
        SPI,
        UART,
    };

    enum PinCommStatus
    {
        OK       = 0x00U,
        ERROR    = 0x01U,
        BUSY     = 0x02U,
        TIMEOUT  = 0x03U
    };

    struct PinHandle {
        Protocol protocol;
        union {
            I2C_HandleTypeDef i2c;
            SPI_HandleTypeDef spi;
            UART_HandleTypeDef uart;
        } handle;
    };

    PinCommStatus transmit(PinHandle pin, char* ptr, unsigned int len);
    PinCommStatus receive(PinHandle pin, char* ptr, unsigned int len);
}

#endif