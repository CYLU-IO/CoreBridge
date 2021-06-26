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

char HomekitClass::version[] = {0};

const char *HomekitClass::getVersion()
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_GET_FW_VERSION_CMD, PARAM_NUMS_0);

  SpiDrv::spiSlaveDeselect();
  //Wait the reply elaboration
  SpiDrv::waitForSlaveReady();
  SpiDrv::spiSlaveSelect();

  memset(version, 0x00, sizeof(version));

  // Wait for reply
  uint8_t _dataLen = 0;
  SpiDrv::waitResponseCmd(HOMEKIT_GET_FW_VERSION_CMD, PARAM_NUMS_1, (uint8_t *)version, &_dataLen);
  SpiDrv::spiSlaveDeselect();

  return version;
}

void HomekitClass::init()
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_INIT_CMD, PARAM_NUMS_0);

  SpiDrv::spiSlaveDeselect();
  //Wait the reply elaboration
  SpiDrv::waitForSlaveReady();
  SpiDrv::spiSlaveSelect();

  // Wait for reply
  uint8_t _data = 0;
  uint8_t _dataLen = 0;
  SpiDrv::waitResponseCmd(HOMEKIT_INIT_CMD, PARAM_NUMS_1, &_data, &_dataLen);
  SpiDrv::spiSlaveDeselect();
}

int HomekitClass::createAccessory(const char *sn, const char *name)
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_CREATE_ACCESSORY_CMD, PARAM_NUMS_2);
  SpiDrv::sendParam((uint8_t *)sn, strlen(sn), NO_LAST_PARAM);
  SpiDrv::sendParam((uint8_t *)name, strlen(name), LAST_PARAM);

  // pad to multiple of 4
  int commandSize = 6 + strlen(sn) + strlen(name);
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

int HomekitClass::deleteAccessory()
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_DELETE_ACCESSORY_CMD, PARAM_NUMS_0);

  SpiDrv::spiSlaveDeselect();
  //Wait the reply elaboration
  SpiDrv::waitForSlaveReady();
  SpiDrv::spiSlaveSelect();

  // Wait for reply
  uint8_t _data = 0;
  uint8_t _dataLen = 0;
  SpiDrv::waitResponseCmd(HOMEKIT_DELETE_ACCESSORY_CMD, PARAM_NUMS_1, &_data, &_dataLen);
  SpiDrv::spiSlaveDeselect();

  return _data;
}

int HomekitClass::addService(uint8_t addr, uint8_t state, const char *name)
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_ADD_SERVICE_CMD, PARAM_NUMS_3);
  SpiDrv::sendParam(&addr, sizeof(addr), NO_LAST_PARAM);
  SpiDrv::sendParam(&state, 1, NO_LAST_PARAM);
  SpiDrv::sendParam((uint8_t *)name, strlen(name), LAST_PARAM);

  // pad to multiple of 4
  int commandSize = 6 + sizeof(addr) + strlen(name);
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
  SpiDrv::waitResponseCmd(HOMEKIT_ADD_SERVICE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
  SpiDrv::spiSlaveDeselect();

  return _data;
}

int HomekitClass::setServiceValue(uint8_t addr, uint8_t state)
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_SET_SERVICE_VALUE_CMD, PARAM_NUMS_2);
  SpiDrv::sendParam(&addr, sizeof(addr), NO_LAST_PARAM);
  SpiDrv::sendParam(&state, 1, LAST_PARAM);

  // pad to multiple of 4
  int commandSize = 7 + sizeof(addr);
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
  SpiDrv::waitResponseCmd(HOMEKIT_SET_SERVICE_VALUE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
  SpiDrv::spiSlaveDeselect();

  return _data;
}

int HomekitClass::getServiceValue(uint8_t addr)
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_GET_SERVICE_VALUE_CMD, PARAM_NUMS_1);
  SpiDrv::sendParam(&addr, sizeof(addr), LAST_PARAM);

  // pad to multiple of 4
  int commandSize = 6 + sizeof(addr);
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
  SpiDrv::waitResponseCmd(HOMEKIT_GET_SERVICE_VALUE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
  SpiDrv::spiSlaveDeselect();

  return _data;
}

int HomekitClass::readServiceTriggered(uint8_t addr)
{
  WAIT_FOR_SLAVE_SELECT();
  // Send Command
  SpiDrv::sendCmd(HOMEKIT_READ_SERVICE_TRIGGERED_CMD, PARAM_NUMS_1);
  SpiDrv::sendParam(&addr, sizeof(addr), LAST_PARAM);

  // pad to multiple of 4
  int commandSize = 6 + sizeof(addr);
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
  SpiDrv::waitResponseCmd(HOMEKIT_READ_SERVICE_TRIGGERED_CMD, PARAM_NUMS_1, &_data, &_dataLen);
  SpiDrv::spiSlaveDeselect();

  return _data;
}

HomekitClass Homekit;
