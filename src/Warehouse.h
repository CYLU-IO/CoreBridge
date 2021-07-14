#ifndef CB_Warehouse_h
#define CB_Warehouse_h

#define EEPROM_I2C_ADDR 0x50
#define EEPROM_HEAD_ADDR 0x00
#define EEPROM_BUFFER_LEN 14400

class WarehouseClass
{
private:
  void write(int val, int addr);
  int read(int addr);

public:
  void begin();

  int getHeadAddr();
  int setHeadAddr(int addr);

  int appendData(int value);
  void getDataPack(int addr, int amount, int *buffer);

  int clearStorage();
};

extern WarehouseClass Warehouse;

#endif