#ifndef CoreBridge_h
#define CoreBridge_h

#include "WifiMgr.h"
#include "Homekit.h"
#include "MqttCtrl.h"

enum
{
  COREBRIDGE_RESET_NETWORK_CMD = 0x1e,
  COREBRIDGE_RESET_TO_FACTORY_CMD = 0x1f,

  COREBRIDGE_ADD_MODULE_CMD = 0x23,
  COREBRIDGE_GET_MODULE_VALUE_CMD = 0x24,
  COREBRIDGE_SET_MODULE_VALUE_CMD = 0x25,
  COREBRIDGE_READ_MODULE_TRIGGERED_CMD = 0x26,
};

class CoreBridgeClass
{
public:
  void begin();
  void end();

  int createAccessory();
  int countAccessory();
  int beginAccessory();

  int addModule(uint8_t index, uint8_t state, const char *name);
  int getModuleValue(uint8_t index);
  int setModuleValue(uint8_t index, uint8_t state);
  int readModuleTriggered(uint8_t index);

  int resetNetwork();
  int resetToFactory();
};

extern CoreBridgeClass CoreBridge;

#endif