/*
  Homekit_drv.cpp - Library for Arduino Homekit shield.
  Copyright (c) 2018 Arduino SA. All rights reserved.
  Copyright (c) 2011-2014 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "Arduino.h"
#include "utility/spi_drv.h"
#include "utility/homekit_drv.h"

#define _DEBUG_

extern "C"
{
#include "utility/homekit_spi.h"
#include "utility/homekit_types.h"
#include "utility/homekit_definitions.h"
#include "utility/debug.h"
}

// Cached values of retrieved data
char HomekitDrv::_acc_name[] = {0};
char HomekitDrv::_acc_code[] = {0};
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

const char* HomekitDrv::getFwVersion()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(GET_HK_FW_VERSION_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    memset(_hk_fwVersion, 0x00, sizeof(_hk_fwVersion));

    // Wait for reply
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(GET_HK_FW_VERSION_CMD, PARAM_NUMS_1, (uint8_t *)_hk_fwVersion, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    return _hk_fwVersion;
}

int8_t HomekitDrv::init(const char *sn, uint8_t sn_len, const char *name, uint8_t name_len, const char *code, const uint8_t code_len, const char *setupId, const uint8_t setupId_len)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(INIT_HOMEKIT_CMD, PARAM_NUMS_4);
    SpiDrv::sendParam((uint8_t *)sn, sn_len, NO_LAST_PARAM);
    SpiDrv::sendParam((uint8_t *)name, name_len, NO_LAST_PARAM);
    SpiDrv::sendParam((uint8_t *)code, code_len, NO_LAST_PARAM);
    SpiDrv::sendParam((uint8_t *)setupId, setupId_len, LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 6 + sn_len + name_len + code_len + setupId_len;
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
    SpiDrv::waitResponseCmd(INIT_HOMEKIT_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    
    return _data;
}

int8_t HomekitDrv::updateServices(uint8_t addr, uint8_t id, uint8_t state, const char* name, uint8_t name_len)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(UPDATE_HOMEKIT_SERVICES_CMD, PARAM_NUMS_4);
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
    SpiDrv::waitResponseCmd(UPDATE_HOMEKIT_SERVICES_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

int8_t HomekitDrv::begin()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(BEGIN_HOMEKIT_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    // Wait for reply
    uint8_t _data = 0;
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(BEGIN_HOMEKIT_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    
    return _data;
}

int8_t HomekitDrv::setState(uint8_t addr, uint8_t id, uint8_t state)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(HOMEKIT_SET_STATE_CMD, PARAM_NUMS_3);
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
    SpiDrv::waitResponseCmd(HOMEKIT_SET_STATE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

int8_t HomekitDrv::getState(uint8_t addr, uint8_t id)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(HOMEKIT_GET_STATE_CMD, PARAM_NUMS_2);
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
    SpiDrv::waitResponseCmd(HOMEKIT_GET_STATE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    
    return _data;
}

int8_t HomekitDrv::getTriggerState(uint8_t addr, uint8_t id)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(GET_TRIGGER_STATE_CMD, PARAM_NUMS_2);
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
    SpiDrv::waitResponseCmd(GET_TRIGGER_STATE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    
    return _data;
}

int8_t HomekitDrv::cleanModules()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(CLEAN_HOMEKIT_SERVICE_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    // Wait for reply
    uint8_t _data = 0;
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(CLEAN_HOMEKIT_SERVICE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    
    return _data;
}

int8_t HomekitDrv::destroy()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(STOP_HOMEKIT_CMD, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    // Wait for reply
    uint8_t _data = 0;
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(STOP_HOMEKIT_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();
    
    return _data;
}

HomekitDrv homekitDrv;
