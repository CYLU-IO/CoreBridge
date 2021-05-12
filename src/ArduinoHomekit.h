#ifndef ArduinoHomekit_h
#define ArduinoHomekit_h

#include <inttypes.h>

extern "C" {
	#include "utility/homekit_definitions.h"
	#include "utility/homekit_types.h"
}


class HomekitClass
{
private:
    static void init(); 
    unsigned long _timeout;
public:
    HomekitClass();

    const char* getFwVersion();
    
    int init(const char* sn, const char* name, const char* code, const char* setupId);

    int updateService(uint8_t addr, uint8_t id, uint8_t state, const char* name);

    int begin();

    int setState(uint8_t addr, uint8_t id, uint8_t state);

    int getState(uint8_t addr, uint8_t id);

    int getTriggerState(uint8_t addr, uint8_t id);

    int cleanModules();

    int destroy();
};

extern HomekitClass Homekit;

#endif