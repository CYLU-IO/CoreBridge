#include <Wire.h>

#include "Warehouse.h"

void WarehouseClass::begin()
{
  Wire.begin();
}

int WarehouseClass::getHeadAddr()
{
  return 0;
}

void WarehouseClass::write(int val, int address)
{
  Wire.beginTransmission(EEPROM_I2C_ADDR);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xff)); // LSB

  Wire.write(val);
  Wire.endTransmission();
}

int WarehouseClass::read(int address)
{
  char re = 0xff;

  Wire.beginTransmission(EEPROM_I2C_ADDR);
  Wire.write((int)(address >> 8));   // MSB
  Wire.write((int)(address & 0xff)); // LSB
  Wire.endTransmission();

  Wire.requestFrom(EEPROM_I2C_ADDR, 1);

  re = Wire.read();

  return re;
}

WarehouseClass Warehouse;