Module 1 - Interactive Devices

Overview

A project on interactive devices using a TTGO T1, ESP32, some wires, a joystick and a button. The code is written using C++ on Arduino IDE and Java on Processing IDE. The codes generate a claw machine game where the player picks up a toy at a randomly generated position within the machine. 

Set-up
On a breadboard, insert an ESP32 at the bottom side, a joystick and a button on top of it. A decent amount of space in between is good. Alternatively, solder the components to each other.
Connect GND on joystick to pin G on ESP32.
Connect +5V on joystick to pin 3V on ESP32.
Connect VRX on joystick to pin 27 on ESP32.
Connect VRY on joystick to pin 26 on ESP32.
Connect SW on joystick to pin 2 on ESP32. 
Connect button to pins 22 and G on ESP32. 

Arduino IDE
Load up the code to read data on Arduino.
View serial monitor to see if data is being read in carefully.
Re-orientate components if all pins are correct but data is not being read correctly.

Processing IDE
Read in data from serial port in Processing.
Access individual values of the data being read from the port.
Use the values as inputs to draw graphics on Processing.
