#ifndef Homekit_Drv_h
#define Homekit_Drv_h

#include <inttypes.h>
#include "utility/homekit_spi.h"

#define HK_FW_VER_LENGTH 6

class HomekitDrv
{
private:
  // firmware version string in the format a.b.c
  static char _hk_fwVersion[HK_FW_VER_LENGTH];

public:
  /*
     * Driver initialization
     */
  static void HomekitDriverInit();

  static void HomekitDriverDeinit();

  static const char *getHKVersion();
  
  static int8_t init();

  static int8_t create(const char *sn, uint8_t sn_len, const char *name, uint8_t name_len);

  static int8_t addService(uint8_t addr, uint8_t id, uint8_t state, const char *name, uint8_t name_len);

  static int8_t begin();

  static int8_t setServiceValue(uint8_t addr, uint8_t id, uint8_t state);

  static int8_t getServiceValue(uint8_t addr, uint8_t id);

  static int8_t getServiceTriggered(uint8_t addr, uint8_t id);

  static int8_t deleateAccessory();

  static int8_t resetToFactory();
};

extern HomekitDrv homekitDrv;

#endif
