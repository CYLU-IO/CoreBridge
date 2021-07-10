#ifndef CB_Warehouse_h
#define CB_Warehouse_h

#define EEPROM_I2C_ADDR     0x50
#define EEPROM_HEAD_ADDR    1
#define EEPROM_BUFFER_LEN   14400

class WarehouseClass
{
private:
public:
  void begin();

  int getHeadAddr();

  void write(int val, int address);
  int read(int address);
};

extern WarehouseClass Warehouse;

#endif