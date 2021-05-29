#ifndef ArduinoHomekit_h
#define ArduinoHomekit_h

#include <inttypes.h>

class HomekitClass
{
private:
    static void drvInit();

public:
    const char *getHKVersion();

    int init();

    int create(const char *sn, const char *name);

    int addService(uint8_t addr, uint8_t id, uint8_t state, const char *name);

    int begin();

    int setServiceValue(uint8_t addr, uint8_t id, uint8_t state);

    int getServiceValue(uint8_t addr, uint8_t id);

    int getServiceTriggered(uint8_t addr, uint8_t id);

    int deleateAccessory();

    int resetToFactory();
};

extern HomekitClass Homekit;

#endif