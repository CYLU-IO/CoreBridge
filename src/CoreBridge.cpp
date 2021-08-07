#include <Arduino.h>

#include "CoreBridge.h"
#include "utility/spi_drv.h"

void CoreBridgeClass::begin()
{
    SpiDrv::begin();
}

void CoreBridgeClass::end()
{
    SpiDrv::end();
}

int CoreBridgeClass::uartReceive(uint8_t port, uint16_t length, uint8_t *buffer)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_UART_RECEIVE, PARAM_NUMS_2);
    SpiDrv::sendParam(&port, 1, NO_LAST_PARAM);
    SpiDrv::sendBufferLen16(buffer, length, LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 7;
    while (commandSize % 4)
    {
        SpiDrv::readChar();
        commandSize++;
    }

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    // Wait for reply
    uint8_t _data = 0;
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(COREBRIDGE_UART_RECEIVE, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

char *CoreBridgeClass::uartTransmit(uint8_t &port, uint16_t &length)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_UART_TRANSMIT, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    // Wait for reply
    tDataParam params[PARAM_NUMS_2] = { {0, NULL},
                                        {0, NULL} };

    SpiDrv::waitResponseDataParams(COREBRIDGE_UART_TRANSMIT, PARAM_NUMS_2, params);
    SpiDrv::spiSlaveDeselect();

    port = params[0].data[0];
    length = params[1].dataLen;

    free(params[0].data);
    
    return params[1].data;
}

CoreBridgeClass CoreBridge;