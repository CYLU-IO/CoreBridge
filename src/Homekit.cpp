#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <Arduino.h>

#include "CoreBridge.h"
#include "utility/spi_drv.h"

extern "C"
{
#include "Homekit.h"
}

int HomekitClass::createAccessory()
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_CREATE_ACCESSORY_CMD, PARAM_NUMS_0);

  SpiDrv::spiSlaveDeselect();
  //Wait the reply elaboration
  SpiDrv::waitForSlaveReady();
  SpiDrv::spiSlaveSelect();

  // Wait for reply
  uint8_t _data = 0;
  uint8_t _dataLen = 0;
  SpiDrv::waitResponseCmd(HOMEKIT_CREATE_ACCESSORY_CMD, PARAM_NUMS_1, &_data, &_dataLen);
  SpiDrv::spiSlaveDeselect();

  return _data;
}

int HomekitClass::countAccessory()
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_COUNT_ACCESSORY_CMD, PARAM_NUMS_0);

  SpiDrv::spiSlaveDeselect();
  //Wait the reply elaboration
  SpiDrv::waitForSlaveReady();
  SpiDrv::spiSlaveSelect();

  // Wait for reply
  uint8_t _data = 0;
  uint8_t _dataLen = 0;
  SpiDrv::waitResponseCmd(HOMEKIT_COUNT_ACCESSORY_CMD, PARAM_NUMS_1, &_data, &_dataLen);
  SpiDrv::spiSlaveDeselect();

  return _data;
}

int HomekitClass::beginAccessory()
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_BEGIN_ACCESSORY_CMD, PARAM_NUMS_0);

  SpiDrv::spiSlaveDeselect();
  //Wait the reply elaboration
  SpiDrv::waitForSlaveReady();
  SpiDrv::spiSlaveSelect();

  // Wait for reply
  uint8_t _data = 0;
  uint8_t _dataLen = 0;
  SpiDrv::waitResponseCmd(HOMEKIT_BEGIN_ACCESSORY_CMD, PARAM_NUMS_1, &_data, &_dataLen);
  SpiDrv::spiSlaveDeselect();

  return _data;
}

HomekitClass Homekit;
