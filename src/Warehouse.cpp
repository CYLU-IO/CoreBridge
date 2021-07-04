#include <Wire.h>

#include "Warehouse.h"

void WarehouseClass::begin()
{
  Wire.begin();
}

void WarehouseClass::write(int val, int address, int ADDR)
{
  Wire.beginTransmission(ADDR);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xff)); // LSB

  Wire.write(val);
  Wire.endTransmission();
}

int WarehouseClass::read(int address, int ADDR)
{
  char rData = 0xff;

  Wire.beginTransmission(ADDR);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xff)); // LSB
  Wire.endTransmission();

  Wire.requestFrom(ADDR, 1);

  rData = Wire.read();

  return rData;
}

WarehouseClass Warehouse;