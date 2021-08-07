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

  int uartReceive(uint8_t port, uint16_t length, uint8_t *buffer);
  char *uartTransmit(uint8_t &port, uint16_t &length);
};

extern CoreBridgeClass CoreBridge;

#endif