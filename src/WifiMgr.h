#ifndef CB_WifiMgr_h
#define CB_WifiMgr_h

enum
{
  WIFIMGR_GET_STATUS_CMD = 0x11,
};

class WifiMgrClass
{
public:
  int getStatus();
};

extern WifiMgrClass WifiMgr;

#endif