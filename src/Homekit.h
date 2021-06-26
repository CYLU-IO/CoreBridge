#ifndef CB_Homekit_h
#define CB_Homekit_h

#include <inttypes.h>

enum
{
  HOMEKIT_GET_FW_VERSION_CMD = 0x20,
  HOMEKIT_INIT_CMD = 0x21,
  HOMEKIT_CREATE_ACCESSORY_CMD = 0x22,
  HOMEKIT_COUNT_ACCESSORY_CMD = 0x23,
  HOMEKIT_BEGIN_ACCESSORY_CMD = 0x24,
  HOMEKIT_DELETE_ACCESSORY_CMD = 0x25,
  HOMEKIT_ADD_SERVICE_CMD = 0x26,
  HOMEKIT_SET_SERVICE_VALUE_CMD = 0x27,
  HOMEKIT_GET_SERVICE_VALUE_CMD = 0x28,
  HOMEKIT_READ_SERVICE_TRIGGERED_CMD = 0x29,
};

class HomekitClass
{
private:
  static char version[6];

public:
  const char *getVersion();

  void init();

  int createAccessory(const char *sn, const char *name);

  int countAccessory();

  int beginAccessory();

  int deleteAccessory();

  int addService(uint8_t index, uint8_t state, const char *name);

  int setServiceValue(uint8_t index, uint8_t state);

  int getServiceValue(uint8_t index);

  int readServiceTriggered(uint8_t index);

  int resetToFactory();
};

extern HomekitClass Homekit;

#endif