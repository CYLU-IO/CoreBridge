#ifndef CoreBridge_h
#define CoreBridge_h

#include "WifiMgr.h"
#include "Homekit.h"
#include "MqttCtrl.h"

enum
{
  COREBRIDGE_RESET_TO_FACTORY_CMD = 0x1f,
};

class CoreBridgeClass
{
public:
  void begin();

  void end();

  int resetToFactory();
};

extern CoreBridgeClass CoreBridge;

#endif