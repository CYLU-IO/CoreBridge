#include <Wire.h>
#include <Arduino.h>

#include "Warehouse.h"

void WarehouseClass::begin()
{
  Wire.begin();
}

int WarehouseClass::getHeadAddr()
{
  return (this->read(EEPROM_HEAD_ADDR) & 0xff) | this->read(EEPROM_HEAD_ADDR + 1) << 8;
}

int WarehouseClass::setHeadAddr(int addr)
{
  this->write(addr & 0xff, EEPROM_HEAD_ADDR);
  this->write((addr >> 8) & 0xff, EEPROM_HEAD_ADDR + 1);

  return addr;
}

int WarehouseClass::appendData(int value)
{
  int addr = this->getHeadAddr() + 2;

  this->write(value & 0xff, addr);
  this->write((value >> 8) & 0xff, addr + 1);

  return this->setHeadAddr(addr);
}

void WarehouseClass::getDataPack(int addr, int amount, int *buffer)
{
  int head_addr = this->getHeadAddr();

  //amount: 144
  for (int i = 0; i < amount; i++)
  {
    if (head_addr / 2 <= i)
      addr = EEPROM_BUFFER_LEN / 2 + (EEPROM_HEAD_ADDR + 2);

    int low_byte_addr = addr - (i * 2);
    int high_byte_addr = addr + 1 - (i * 2);

    buffer[i] = (this->read(low_byte_addr) & 0xff) | this->read(high_byte_addr) << 8;
  }
}

int WarehouseClass::clearStorage()
{
  for (int i = 0; i < EEPROM_BUFFER_LEN / 2 + (EEPROM_HEAD_ADDR + 2); i++)
  {
    this->write(0xff, i);
  }

  return this->setHeadAddr(EEPROM_HEAD_ADDR + 2);
}

void WarehouseClass::write(int val, int addr)
{
  Wire.beginTransmission(EEPROM_I2C_ADDR);
  Wire.write((int)(addr >> 8));   // MSB
  Wire.write((int)(addr & 0xff)); // LSB

  Wire.write(val);
  Wire.endTransmission();

  delay(5);
}

int WarehouseClass::read(int addr)
{
  char re = 0xff;

  Wire.beginTransmission(EEPROM_I2C_ADDR);
  Wire.write((int)(addr >> 8));   // MSB
  Wire.write((int)(addr & 0xff)); // LSB
  Wire.endTransmission();

  Wire.requestFrom(EEPROM_I2C_ADDR, 1);

  if (Wire.available())
    re = Wire.read();

  return re;
}

WarehouseClass Warehouse;