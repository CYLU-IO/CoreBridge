#ifndef Homekit_Spi_h
#define Homekit_Spi_h

#include <inttypes.h>

enum {
  HOMEKIT_GET_FW_VERSION_CMD              = 0x70,
  HOMEKIT_INIT_CMD 		                    = 0x71,
  HOMEKIT_CREATE_CMD 		                  = 0x72,
  HOMEKIT_ADD_SERVICE_CMD 		            = 0x73,
  HOMEKIT_BEGIN_CMD 		                  = 0x74,
  HOMEKIT_SET_SERVICE_VALUE_CMD 		      = 0x75,
  HOMEKIT_GET_SERVICE_VALUE_CMD 		      = 0x76,
  HOMEKIT_GET_SERVICE_TRIGGERED_CMD       = 0x77,
  HOMEKIT_DELETE_ACCESSORY_CMD 		        = 0x7e,
  HOMEKIT_RESET_TO_FACTORY_CMD 		        = 0x7f,
};
#endif
