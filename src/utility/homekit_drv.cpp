#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <Arduino.h>
#include "utility/spi_drv.h"
#include "utility/homekit_drv.h"

extern "C"
{
#include "utility/homekit_spi.h"
}

// Firmware version
char HomekitDrv::_hk_fwVersion[] = {0};

// Public Methods

void HomekitDrv::HomekitDriverInit()
{
    SpiDrv::begin();
}

void HomekitDrv::HomekitDriverDeinit()
{
    SpiDrv::end();
}

const char* HomekitDrv::getHKVersion()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(HOMEKIT_GET_FW_VERSION_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    memset(_hk_fwVersion, 0x00, sizeof(_hk_fwVersion));

    // Wait for reply
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(HOMEKIT_GET_FW_VERSION_CMD, PARAM_NUMS_1, (uint8_t *)_hk_fwVersion, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    return _hk_fwVersion;
}

int8_t HomekitDrv::init()
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
    
    return _data;
}


int8_t HomekitDrv::create(const char *sn, uint8_t sn_len, const char *name, uint8_t name_len)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(HOMEKIT_CREATE_CMD, PARAM_NUMS_2);
    SpiDrv::sendParam((uint8_t *)sn, sn_len, NO_LAST_PARAM);
    SpiDrv::sendParam((uint8_t *)name, name_len, LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 6 + sn_len + name_len;
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
    SpiDrv::waitResponseCmd(HOMEKIT_CREATE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    
    return _data;
}

int8_t HomekitDrv::addService(uint8_t addr, uint8_t id, uint8_t state, const char* name, uint8_t name_len)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(HOMEKIT_ADD_SERVICE_CMD, PARAM_NUMS_4);
    SpiDrv::sendParam(&addr, sizeof(addr), NO_LAST_PARAM);
    SpiDrv::sendParam(&id, sizeof(id), NO_LAST_PARAM);
    SpiDrv::sendParam(&state, 1, NO_LAST_PARAM);
    SpiDrv::sendParam((uint8_t *)name, name_len, LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 6 + sizeof(addr) + sizeof(id) + name_len;
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

int8_t HomekitDrv::begin()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(HOMEKIT_BEGIN_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    // Wait for reply
    uint8_t _data = 0;
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(HOMEKIT_BEGIN_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    
    return _data;
}

int8_t HomekitDrv::setServiceValue(uint8_t addr, uint8_t id, uint8_t state)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(HOMEKIT_SET_SERVICE_VALUE_CMD, PARAM_NUMS_3);
    SpiDrv::sendParam(&addr, sizeof(addr), NO_LAST_PARAM);
    SpiDrv::sendParam(&id, sizeof(id), NO_LAST_PARAM);
    SpiDrv::sendParam(&state, 1, LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 7 + sizeof(addr) + sizeof(id);
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

int8_t HomekitDrv::getServiceValue(uint8_t addr, uint8_t id)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(HOMEKIT_GET_SERVICE_VALUE_CMD, PARAM_NUMS_2);
    SpiDrv::sendParam(&addr, sizeof(addr), NO_LAST_PARAM);
    SpiDrv::sendParam(&id, sizeof(id), LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 6 + sizeof(addr) + sizeof(id);
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

int8_t HomekitDrv::getServiceTriggered(uint8_t addr, uint8_t id)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(HOMEKIT_GET_SERVICE_TRIGGERED_CMD, PARAM_NUMS_2);
    SpiDrv::sendParam(&addr, sizeof(addr), NO_LAST_PARAM);
    SpiDrv::sendParam(&id, sizeof(id), LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 6 + sizeof(addr) + sizeof(id);
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
    SpiDrv::waitResponseCmd(HOMEKIT_GET_SERVICE_TRIGGERED_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    
    return _data;
}

int8_t HomekitDrv::deleateAccessory()
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

int8_t HomekitDrv::resetToFactory()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(HOMEKIT_RESET_TO_FACTORY_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    // Wait for reply
    uint8_t _data = 0;
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(HOMEKIT_RESET_TO_FACTORY_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    
    return _data;
}

HomekitDrv homekitDrv;
