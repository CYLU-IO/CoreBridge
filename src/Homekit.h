#ifndef CB_Homekit_h
#define CB_Homekit_h

#include <inttypes.h>

enum
{
  HOMEKIT_CREATE_ACCESSORY_CMD = 0x20,
  HOMEKIT_COUNT_ACCESSORY_CMD = 0x21,
  HOMEKIT_BEGIN_ACCESSORY_CMD = 0x22,
};

class HomekitClass
{
public:
  int createAccessory();
  int countAccessory();
  int beginAccessory();
};

extern HomekitClass Homekit;

#endif