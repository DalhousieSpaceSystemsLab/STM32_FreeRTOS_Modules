#include "pin_communication.h"

namespace csl {
    PinCommStatus transmit(PinHandle pin, char *ptr, unsigned int len) {
        switch (pin.protocol) {
            case Protocol::I2C:
                return transmit_i2c(pin, ptr, len);
            case Protocol::SPI:
                return transmit_spi(pin, ptr, len);
            case Protocol::UART:
                return transmit_uart(pin, ptr, len);
            default:
                return PinCommStatus::ERROR;

        }
    }

    PinCommStatus receive(PinHandle pin, char *ptr, unsigned int len) {
        switch (pin.protocol) {
            case Protocol::I2C:
                return receive_i2c(pin, ptr, len);
            case Protocol::SPI:
                return receive_spi(pin, ptr, len);
            case Protocol::UART:
                return receive_uart(pin, ptr, len);
            default:
                return PinCommStatus::ERROR;

        }
    }
}

csl::PinCommStatus transmit_i2c(csl::PinHandle pin, char *ptr, unsigned int len) {
    // TODO: Not sure how to send over I2C
    // return HAL_I2C_Master_Transmit(pin.handle.i2c, ...)
    return csl::PinCommStatus::ERROR;
}

csl::PinCommStatus receive_i2c(csl::PinHandle pin, char *ptr, unsigned int len) {
    return csl::PinCommStatus::ERROR;
}

csl::PinCommStatus transmit_spi(csl::PinHandle pin, char *ptr, unsigned int len) {
    HAL_StatusTypeDef hal_status = HAL_SPI_Transmit(&pin.handle.spi, (uint8_t*) ptr, (uint16_t) len, HAL_MAX_DELAY);
    return (csl::PinCommStatus)hal_status;
}

csl::PinCommStatus receive_spi(csl::PinHandle pin, char *ptr, unsigned int len) {
    HAL_StatusTypeDef hal_status = HAL_SPI_Receive(&pin.handle.spi, (uint8_t*) ptr, (uint16_t) len, HAL_MAX_DELAY);
    return (csl::PinCommStatus)hal_status;
}

csl::PinCommStatus transmit_uart(csl::PinHandle pin, char *ptr, unsigned int len) {
    HAL_StatusTypeDef hal_status = HAL_UART_Transmit(&pin.handle.uart, (uint8_t*) ptr, (uint16_t) len, HAL_MAX_DELAY);
    return (csl::PinCommStatus)hal_status;
}

csl::PinCommStatus receive_uart(csl::PinHandle pin, char *ptr, unsigned int len) {
    HAL_StatusTypeDef hal_status = HAL_UART_Receive(&pin.handle.uart, (uint8_t*) ptr, (uint16_t) len, HAL_MAX_DELAY);
    return (csl::PinCommStatus)hal_status;
}