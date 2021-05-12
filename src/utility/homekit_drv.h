/*
  Homekit_drv.h - Library for Arduino Homekit shield.
  Copyright (c) 2018 Arduino SA. All rights reserved.
  Copyright (c) 2011-2014 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Homekit_Drv_h
#define Homekit_Drv_h

#include <inttypes.h>
#include "utility/homekit_spi.h"

// Key index length
#define KEY_IDX_LEN 1

class HomekitDrv
{
private:
    // firmware version string in the format a.b.c
    static char _hk_fwVersion[HK_FW_VER_LENGTH];

    // accessory settings
    static char _acc_name[HK_ACC_NAME_MAX_LENGTH];
    static char _acc_code[HK_ACC_CODE_MAX_LENGTH];

public:
    /*
     * Driver initialization
     */
    static void HomekitDriverInit();

    static void HomekitDriverDeinit();

    static const char* getFwVersion();

    static int8_t init(const char* sn, uint8_t sn_len, const char* name, uint8_t name_len, const char* code, const uint8_t code_len, const char *setupId, const uint8_t setupId_len);

    static int8_t updateServices(uint8_t addr, uint8_t id, uint8_t state, const char* name, uint8_t name_len);

    static int8_t begin();

    static int8_t setState(uint8_t addr, uint8_t id, uint8_t state);

    static int8_t getState(uint8_t addr, uint8_t id);

    static int8_t getTriggerState(uint8_t addr, uint8_t id);

    static int8_t cleanModules();

    static int8_t destroy();
};

extern HomekitDrv homekitDrv;

#endif
