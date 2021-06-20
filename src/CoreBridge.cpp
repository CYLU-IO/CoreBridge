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

int CoreBridgeClass::resetNetwork()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_RESET_NETWORK_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();

    return 0;
}

int CoreBridgeClass::resetToFactory()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_RESET_TO_FACTORY_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();

    return 0;
}

CoreBridgeClass CoreBridge;