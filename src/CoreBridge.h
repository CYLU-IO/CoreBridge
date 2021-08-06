#ifndef CoreBridge_h
#define CoreBridge_h

enum
{
  COREBRIDGE_UART_RECEIVE = 0x00,
  COREBRIDGE_UART_TRANSMIT = 0x01,
};

class CoreBridgeClass
{
public:
  void begin();
  void end();

  int uartReceive(uint16_t length, uint8_t *buffer);
  char *uartTransmit(uint8_t &port, uint16_t &length);

  /*int getEnablePOP();

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
  int resetToFactory();*/
};

extern CoreBridgeClass CoreBridge;

#endif