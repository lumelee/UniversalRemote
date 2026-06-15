\# UniversalRemote



An object-oriented, non-blocking Arduino library designed to manage infrared (IR) remote controls. Ideal for state machines or complex multi-tasking projects.



\## 🚀 Features



\- \*\*Non-blocking Architecture:\*\* Designed entirely without `delay()`, utilizing asynchronous timing (`millis()`) so your microcontroller can perform other tasks simultaneously.

\- \*\*Dynamic Profile Mapping:\*\* Easily switch between different remote control models (Elegoo, LED controllers, custom remotes) using object-oriented profiles and addresses.



\## 📦 Installation



1\. Download this repository as a `.zip` file.

2\. In the Arduino IDE, go to \*\*Sketch -> Include Library -> Add .ZIP Library...\*\*

3\. Alternatively, clone this repository directly into your `hardware/libraries` folder.



\## 🔌 Basic Wiring



Connect your IR Receiver module (e.g., KY-022) as follows:

\- \*\*G / GND\*\* -> Arduino GND

\- \*\*R / VCC\*\* -> Arduino 5V (or 3.3V for low power boards)

\- \*\*Y / DATA\*\* -> Arduino Digital Pin)



\## 💻 Quick Example



```cpp

\#include <universalRemote.h>



UniversalRemote myRemote(2, 0, remoteElegoo, true); // Pin 2, Address 0, Elegoo Profile, Debug ON



void setup() {

&nbsp; Serial.begin(9600);

&nbsp; myRemote.begin();

}



void loop() {

&nbsp; ButtonAction btn = myRemote.readBtn();

&nbsp; if (btn == BTN\_PWR) {

&nbsp;   // Perform your action here

&nbsp; }

}

