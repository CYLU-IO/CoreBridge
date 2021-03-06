#ifndef CoreBridge_h
#define CoreBridge_h

#include "WifiMgr.h"
#include "Homekit.h"
#include "MqttCtrl.h"
#include "Warehouse.h"

enum
{
  COREBRIDGE_GET_ENABLE_POP = 0x00,

  COREBRIDGE_RESET_NETWORK_CMD = 0x1e,
  COREBRIDGE_RESET_TO_FACTORY_CMD = 0x1f,

  COREBRIDGE_ADD_MODULE_CMD = 0x23,
  COREBRIDGE_SET_MODULE_SWITCH_STATE_CMD = 0x24,
  COREBRIDGE_GET_MODULE_SWITCH_STATE_CMD = 0x25,
  COREBRIDGE_SET_MODULE_CURRENT_CMD = 0x26,
  COREBRIDGE_GET_MODULE_PRIORITY_CMD = 0x27,
  COREBRIDGE_READ_MODULE_TRIGGERED_CMD = 0x28,

  COREBRIDGE_PUSH_WAREHOUSE_BUFFER = 0x30,
};

class CoreBridgeClass
{
public:
  void begin();
  void end();

  int getEnablePOP();

  int createAccessory();
  int countAccessory();
  int beginAccessory();

  int addModule(uint8_t index, const char *name, uint8_t type, uint8_t priority, uint8_t state);
  int getModuleSwitchState(uint8_t index);
  int setModuleSwitchState(uint8_t index, uint8_t state);

  int setModuleCurrent(uint8_t index, uint16_t value);

  int getModulePriority(uint8_t index);

  int readModuleTriggered(uint8_t index);

  int pushWarehouseBuffer(uint16_t *buffer, uint8_t length);

  int resetNetwork();
  int resetToFactory();
};

extern CoreBridgeClass CoreBridge;

#endif