/*
  wifi_spi.h - Library for Arduino Wifi shield.
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

#ifndef Homekit_Spi_h
#define Homekit_Spi_h

#include <inttypes.h>
#include "utility/homekit_definitions.h"

enum {
  GET_HK_FW_VERSION_CMD              = 0x70,
  INIT_HOMEKIT_CMD 		               = 0x71,
  UPDATE_HOMEKIT_SERVICES_CMD 		   = 0x72,
  BEGIN_HOMEKIT_CMD 		             = 0x73,
  HOMEKIT_SET_STATE_CMD 		         = 0x74,
  HOMEKIT_GET_STATE_CMD 		         = 0x75,
  GET_TRIGGER_STATE_CMD 		         = 0x76,
  CLEAN_HOMEKIT_SERVICE_CMD 		     = 0x77,
  STOP_HOMEKIT_CMD 		               = 0x78,
};
#endif
