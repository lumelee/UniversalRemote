#pragma once

#include <Arduino.h>
#include "universalRemoteLibraries.h"

class UniversalRemote{
  private:
    int dataPin;
    int address;
    bool debugMode;
    RemoteProfile activeProfile;

  public:
    UniversalRemote(int pin, int addr, RemoteProfile profile, bool debug);
    void begin();
    void test();
    ButtonAction readBtn();
};