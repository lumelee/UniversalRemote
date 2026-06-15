#pragma once

#include <Arduino.h>

enum ButtonAction {
  BTN_ERROR = -1,
  BTN_EMPTY = 0,

  BTN_PWR,
  BTN_VOL_UP,
  BTN_FUNC_STOP,
  BTN_BACK,
  BTN_START_PAUSE,
  BTN_NEXT,
  BTN_DOWN,
  BTN_VOL_DOWN,
  BTN_UP,
  BTN_0,
  BTN_EQ,
  BTN_ST_REPT,
  BTN_1,
  BTN_2,
  BTN_3,
  BTN_4,
  BTN_5,
  BTN_6,
  BTN_7,
  BTN_8,
  BTN_9,
  BTN_A,

  BTN_B,
  BTN_C,
  BTN_D,

  BTN_OFF,
  BTN_ON,
  BTN_R1,
  BTN_G1,
  BTN_B1,
  BTN_W,
  BTN_R2,
  BTN_G2,
  BTN_B2,
  BTN_MODE,
  BTN_R3,
  BTN_G3,
  BTN_B3,
  BTN_M1,
  BTN_R4,
  BTN_G4,
  BTN_B4,
  BTN_M2,
  BTN_R5,
  BTN_G5,
  BTN_B5,
  BTN_M3,
};

struct MapBtn {
  uint16_t hexValue;
  ButtonAction action;
  const char* btnName;
};

struct RemoteProfile{
  const MapBtn* btns;
  int btnAmount;
};

//------------------------------------------------------------

// Address 0, protocol 7

const MapBtn mapRemoteElegoo[] = {
  {0x45, BTN_PWR, "PWR"},
  {0x46, BTN_VOL_UP, "VOL_UP"},
  {0x47, BTN_FUNC_STOP, "FUNC_STOP"},
  {0x44, BTN_BACK, "BACK"},
  {0x40, BTN_START_PAUSE, "START_PAUSE"},
  {0x43, BTN_NEXT, "NEXT"},
  {0x07, BTN_DOWN, "DOWN"},
  {0x15, BTN_VOL_DOWN, "VOL_DOWN"},
  {0x09, BTN_UP, "UP"},
  {0x1E, BTN_0, "0"},
  {0x19, BTN_EQ, "EQ"},
  {0x0D, BTN_ST_REPT, "ST_REPT"},
  {0x0C, BTN_1, "1"},
  {0x18, BTN_2, "2"},
  {0x5E, BTN_3, "3"},
  {0x08, BTN_4, "4"},
  {0x1C, BTN_5, "5"},
  {0x5A, BTN_6, "6"},
  {0x42, BTN_7, "7"},
  {0x52, BTN_8, "8"},
  {0x4A, BTN_9, "9"},
};

const RemoteProfile remoteElegoo = {
  mapRemoteElegoo, 
  sizeof(mapRemoteElegoo) / sizeof(mapRemoteElegoo[0])
};

//------------------------------------------------------------

// Address 0, protocol 7

const MapBtn mapRemoteTest[] = {
  {0x45, BTN_A, "A"},
  {0x46, BTN_B, "B"},
  {0x47, BTN_C, "C"},
};

const RemoteProfile remoteTest = {
  mapRemoteTest, 
  sizeof(mapRemoteTest) / sizeof(mapRemoteTest[0])
};

//------------------------------------------------------------

// Address 61184, protocol 7

const MapBtn mapRemoteLed[] = {
  {0x00, BTN_UP, "UP"},
  {0x01, BTN_DOWN, "DOWN"},
  {0x02, BTN_OFF, "OFF"},
  {0x03, BTN_ON, "ON"},
  {0x04, BTN_R1, "R1"},
  {0x05, BTN_G1, "G1"},
  {0x06, BTN_B1, "B1"},
  {0x07, BTN_W, "W"},
  {0x08, BTN_R2, "R2"},
  {0x09, BTN_G2, "G2"},
  {0x0A, BTN_B2, "B2"},
  {0x0B, BTN_MODE, "MODE"},
  {0x0C, BTN_R3, "R3"},
  {0x0D, BTN_G3, "G3"},
  {0x0E, BTN_B3, "B3"},
  {0x0F, BTN_M1, "M1"},
  {0x10, BTN_R4, "R4"},
  {0x11, BTN_G4, "G4"},
  {0x12, BTN_B4, "B4"},
  {0x13, BTN_M2, "M2"},
  {0x14, BTN_R5, "R5"},
  {0x15, BTN_G5, "G5"},
  {0x16, BTN_B5, "B5"},
  {0x17, BTN_M3, "M3"},
};

const RemoteProfile remoteLed = {
  mapRemoteLed, 
  sizeof(mapRemoteLed) / sizeof(mapRemoteLed[0])
};