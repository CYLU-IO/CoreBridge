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

int CoreBridgeClass::getEnablePOP()
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_GET_ENABLE_POP, PARAM_NUMS_0);

    SpiDrv::spiSlaveDeselect();
    //Wait the reply elaboration
    SpiDrv::waitForSlaveReady();
    SpiDrv::spiSlaveSelect();

    // Wait for reply
    uint8_t _data = 0;
    uint8_t _dataLen = 0;
    SpiDrv::waitResponseCmd(COREBRIDGE_GET_ENABLE_POP, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

int CoreBridgeClass::createAccessory()
{
    return Homekit.createAccessory();
}

int CoreBridgeClass::countAccessory()
{
    return Homekit.countAccessory();
}

int CoreBridgeClass::beginAccessory()
{
    return Homekit.beginAccessory();
}

int CoreBridgeClass::addModule(uint8_t index, const char *name, uint8_t type, uint8_t priority, uint8_t state)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_ADD_MODULE_CMD, PARAM_NUMS_5);
    SpiDrv::sendParam(&index, 1, NO_LAST_PARAM);
    SpiDrv::sendParam(&type, 1, NO_LAST_PARAM);
    SpiDrv::sendParam(&priority, 1, NO_LAST_PARAM);
    SpiDrv::sendParam(&state, 1, NO_LAST_PARAM);
    SpiDrv::sendParam((uint8_t *)name, strlen(name), LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 9 + strlen(name);
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
    SpiDrv::waitResponseCmd(COREBRIDGE_ADD_MODULE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

int CoreBridgeClass::getModuleSwitchState(uint8_t index)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_GET_MODULE_SWITCH_STATE_CMD, PARAM_NUMS_1);
    SpiDrv::sendParam(&index, 1, LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 6;
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
    SpiDrv::waitResponseCmd(COREBRIDGE_GET_MODULE_SWITCH_STATE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

int CoreBridgeClass::setModuleSwitchState(uint8_t index, uint8_t state)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_SET_MODULE_SWITCH_STATE_CMD, PARAM_NUMS_2);
    SpiDrv::sendParam(&index, 1, NO_LAST_PARAM);
    SpiDrv::sendParam(&state, 1, LAST_PARAM);

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
    SpiDrv::waitResponseCmd(COREBRIDGE_SET_MODULE_SWITCH_STATE_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

int CoreBridgeClass::setModuleCurrent(uint8_t index, uint16_t value)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_SET_MODULE_CURRENT_CMD, PARAM_NUMS_2);
    SpiDrv::sendParam(&index, 1, NO_LAST_PARAM);
    SpiDrv::sendBufferLen16(&value, 1, LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 9;
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
    SpiDrv::waitResponseCmd(COREBRIDGE_SET_MODULE_CURRENT_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

int CoreBridgeClass::getModulePriority(uint8_t index)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_GET_MODULE_PRIORITY_CMD, PARAM_NUMS_1);
    SpiDrv::sendParam(&index, 1, LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 6;
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
    SpiDrv::waitResponseCmd(COREBRIDGE_GET_MODULE_PRIORITY_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

int CoreBridgeClass::readModuleTriggered(uint8_t index)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_READ_MODULE_TRIGGERED_CMD, PARAM_NUMS_1);
    SpiDrv::sendParam(&index, 1, LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 6;
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
    SpiDrv::waitResponseCmd(COREBRIDGE_READ_MODULE_TRIGGERED_CMD, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
}

int CoreBridgeClass::pushWarehouseBuffer(uint16_t *buffer, uint8_t length)
{
    WAIT_FOR_SLAVE_SELECT();
    // Send Command
    SpiDrv::sendCmd(COREBRIDGE_PUSH_WAREHOUSE_BUFFER, PARAM_NUMS_1);
    SpiDrv::sendBufferLen16(buffer, length, LAST_PARAM);

    // pad to multiple of 4
    int commandSize = 6;
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
    SpiDrv::waitResponseCmd(COREBRIDGE_PUSH_WAREHOUSE_BUFFER, PARAM_NUMS_1, &_data, &_dataLen);
    SpiDrv::spiSlaveDeselect();

    return _data;
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