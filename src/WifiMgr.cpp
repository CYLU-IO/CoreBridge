#include <Arduino.h>

#include "CoreBridge.h"
#include "utility/spi_drv.h"

extern "C"
{
  #include "WifiMgr.h"
}

int WifiMgrClass::getStatus()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(WIFIMGR_GET_STATUS_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    // Wait for reply
    uint8_t _data = 0;
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(WIFIMGR_GET_STATUS_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

WifiMgrClass WifiMgr;