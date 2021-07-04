#ifndef CB_Warehouse_h
#define CB_Warehouse_h

class WarehouseClass
{
private:
public:
  void begin();

  void write(int val, int address, int ADDR);

  int read(int address, int ADDR);
};

extern WarehouseClass Warehouse;

#endif