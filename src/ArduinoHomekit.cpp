#include <string.h>
#include "utility/homekit_drv.h"
#include "ArduinoHomekit.h"


HomekitClass::HomekitClass() : _timeout(50000)
{  
}

void HomekitClass::init() {
    HomekitDrv::HomekitDriverInit();
}

const char* HomekitClass::getFwVersion() {
	return HomekitDrv::getFwVersion();
}

int HomekitClass::init(const char* sn, const char* name, const char* code, const char* setupId) {
    return HomekitDrv::init(sn, strlen(sn), name, strlen(name), code, strlen(code), setupId, strlen(setupId));
}

int HomekitClass::updateService(uint8_t addr, uint8_t id, uint8_t state, const char* name) {
    return HomekitDrv::updateServices(addr, id, state, name, strlen(name));
}

int HomekitClass::begin() {
    return HomekitDrv::begin();
}

int HomekitClass::setState(uint8_t addr, uint8_t id, uint8_t state) {
    return HomekitDrv::setState(addr, id, state);
}

int HomekitClass::getState(uint8_t addr, uint8_t id) {
    return HomekitDrv::getState(addr, id);
}

int HomekitClass::getTriggerState(uint8_t addr, uint8_t id) {
    return HomekitDrv::getTriggerState(addr, id);
}

int HomekitClass::cleanModules() {
    return HomekitDrv::cleanModules();
}

int HomekitClass::destroy() {
    return HomekitDrv::destroy();
}

HomekitClass Homekit;
