/*
  emiterIR Library Basic Example
  Dependencies: IRremote.hpp

  Basic control example with basic led functions to be controlled with an IR remote and receiver module (like KY-022)

  Wiring: connect G to GND, R to 5V and Y to digital pin 2
  This example is already configured with Elegoo's remote control, check "emiterIRLibraries.h" to check for other options

  Working example: 
    turning "debug" to true will cause the Serial Monitor to print out the hex command and the action associated
    turning "test" to true will cause the program to not check for the selected remote, instead prints the protocol, address and hex command
  
  Debug flag is useful if you need to know the associated action to an existing button
  Test flag is useful if you want to configure a new remote and don't know its address or hex commands of each button

  Normal operation:
    With both "debug" and "test" in false, the code will continuously run between reading the data and executing all the functions below it (only blink in this case)
    When "power" button is pressed, the internal led will change its status
    When "start/pause" button is pressed, the internal led will start/stop flickering with a variable speed defined in "flickerSpeed"
    If any other button is pressed, case "Default" will trigger, just to let you know that button does nothing
    If any unwanted hex command is received, case "BTN_ERROR" will trigger, since this is due to a bad configuration in the remote (check "emiterIRLibraries.h")
    If nothing happens, maybe the address is not defined correctly, check with "test" and change it accordingly
    Otherwise, the protocol could be another one, change "#define DECODE_NEC" accordingly

  This project is licensed under the MIT License - see the LICENSE file for details.
  Written by Carlos Garcia Mendizabal
*/

#include <universalRemote.h>

// This ensures only "Protocol = 7" is accounted for, ignoring the rest of the protocols
#define DECODE_NEC 1

// Here we select the digital pin where Y is connected and the remote address
const byte dataPin = 2;
const int address = 0;

// This changes between normal operation of the code
const bool debug = true;
const bool test = false;

// This is used in the auxiliary functions to blink the led
unsigned long int lastTime;
unsigned long int flickerSpeed = 200;
bool blinky = false;

// Here we created a new object of the class "ButtonAction" to register the actual button pressed
ButtonAction pressedButton;

// In here the remote itself is declared, where "remoteElegoo" is the mapped remote we want to use
// If we set the last parameter to "false", we will no longer see the command and the action in the serial monitor
UniversalRemote myRemote(dataPin, address, remoteElegoo, debug);

void setup() {
  Serial.begin(9600);

  // We initialize the remote
  myRemote.begin();
  Serial.println();
  Serial.println("Universal remote successfully configured");
  Serial.println();

  // We will use the internal led of the arduino as a visual representation
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // When "test" is set to "true", we run our test function to check every remote we point at the receiver
  if (test){
    myRemote.test();
  }
  // Otherwise, this is the normal program flow
  else{
    // The program constantly checks if new data is received
    getBtn();
    // But it can still perform other operations if needed
    blink();
  }
}

// This function just reads the data and, with or predefined "pressedButton" we can perform actions based on the received command
// To further use, check "emiterIRLibraries.h" to see the complete mapping or use the "debug" function to see each action independently
// To use one of the actions, just add "BTN_" before the action written in the serial monitor (just follow the case structure below)
void getBtn(){
  pressedButton = myRemote.readBtn();

  // Based on the button pressed, we perform different actions
  switch(pressedButton){
    // In this example, only POWER and START/PAUSE actions are defined
    case BTN_PWR:           // POWER button will cause the led to change its status
      change();
    break;
    case BTN_START_PAUSE:   // START/PAUSE button will cause the flicker effect to start or stop
      blinky = !blinky;
    break;



    case BTN_EMPTY:         // Since we continuously check the status of the buttons, when none is pressed we come here and do nothing
    break;
    case BTN_ERROR:         // If a remote mapping is wrong or we read an strange hex value, this section will trigger
      if (debug){
        Serial.println("ERROR: Unrecognized command");
      }
    break;
    default:                // This section is just to inform the programmer that button is not being used and it does nothing (just in case)
      if (debug){
        Serial.println("WARNING: Command not configured");
      }
    break;
  }
}

/*
  THIS SECTION OF THE CODE IS ONLY FOR THE VISUALIZATION OF THE INTERNAL LED, IT DOES NOT BRING ANYTHING ELSE TO THE LIBRARY
*/

void blink(){
  if (blinky){
    if (millis() - lastTime > flickerSpeed){
      change();
      lastTime = millis();
    }
  }
}

void change(){
  bool ledStatus = digitalRead(LED_BUILTIN);
  digitalWrite(LED_BUILTIN,!ledStatus);
}