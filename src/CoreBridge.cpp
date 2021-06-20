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

int CoreBridgeClass::resetToFactory()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_RESET_TO_FACTORY_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    // Wait for reply
    uint8_t _data = 0;
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(COREBRIDGE_RESET_TO_FACTORY_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

CoreBridgeClass CoreBridge;