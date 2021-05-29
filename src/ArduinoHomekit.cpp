#include <string.h>
#include "utility/homekit_drv.h"
#include "ArduinoHomekit.h"

void HomekitClass::drvInit()
{
    HomekitDrv::HomekitDriverInit();
}

const char *HomekitClass::getHKVersion()
{
    return HomekitDrv::getHKVersion();
}

int HomekitClass::init()
{
    return HomekitDrv::init();
}

int HomekitClass::create(const char *sn, const char *name)
{
    return HomekitDrv::create(sn, strlen(sn), name, strlen(name));
}

int HomekitClass::addService(uint8_t addr, uint8_t id, uint8_t state, const char *name)
{
    return HomekitDrv::addService(addr, id, state, name, strlen(name));
}

int HomekitClass::begin()
{
    return HomekitDrv::begin();
}

int HomekitClass::setServiceValue(uint8_t addr, uint8_t id, uint8_t state)
{
    return HomekitDrv::setServiceValue(addr, id, state);
}

int HomekitClass::getServiceValue(uint8_t addr, uint8_t id)
{
    return HomekitDrv::getServiceValue(addr, id);
}

int HomekitClass::getServiceTriggered(uint8_t addr, uint8_t id)
{
    return HomekitDrv::getServiceTriggered(addr, id);
}

int HomekitClass::deleateAccessory()
{
    return HomekitDrv::deleateAccessory();
}

int HomekitClass::resetToFactory()
{
    return HomekitDrv::resetToFactory();
}

HomekitClass Homekit;
