#include <Arduino.h>
#include <IRremote.hpp>
#include "universalRemote.h"

UniversalRemote::UniversalRemote(int pin, int addr, RemoteProfile profile, bool debug){
  dataPin = pin;
  address = addr;
  activeProfile = profile;
  debugMode = debug;
}

void UniversalRemote::begin(){
  IrReceiver.begin(dataPin, DISABLE_LED_FEEDBACK);
}

void UniversalRemote::test(){
  if (IrReceiver.decode()){
    if (IrReceiver.decodedIRData.flags == 0){

      Serial.println("------------------------------");
      Serial.print("Protocol: ");
      Serial.println(IrReceiver.decodedIRData.protocol);
      Serial.print("Address: ");
      Serial.println(IrReceiver.decodedIRData.address);
      Serial.print("Command: 0x");
      Serial.println(IrReceiver.decodedIRData.command, HEX);
      Serial.println("------------------------------");
      IrReceiver.resume();

    }
  }
}

ButtonAction UniversalRemote::readBtn(){
  if (IrReceiver.decode()){
    if ((IrReceiver.decodedIRData.flags == 0) && (IrReceiver.decodedIRData.address == address)){
      uint16_t receivedCode = IrReceiver.decodedIRData.command;
      for (int i = 0; i < activeProfile.btnAmount; i++){
        if (receivedCode == activeProfile.btns[i].hexValue){
          if (debugMode){
            char debugBuffer[50];
            sprintf(debugBuffer, "Command: 0x%02X | Action: %s", activeProfile.btns[i].hexValue, activeProfile.btns[i].btnName);
            Serial.println(debugBuffer);
          }

          IrReceiver.resume();
          return activeProfile.btns[i].action;
        }
      }

      if (debugMode){
        char errorBuffer[50];
        sprintf(errorBuffer, "Unknown command: 0x%02X", receivedCode);
        Serial.println(errorBuffer);
      }
      IrReceiver.resume();
      return BTN_ERROR;
    }
    IrReceiver.resume();
  }
  return BTN_EMPTY;
}