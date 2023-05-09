Module 1 - Synthesizer Painting

Overview

The Synthesizer Painting Project is an interactive artwork that utilizes acrylic paint, conductive paint, copper tape, an ESP32 microcontroller, and a laptop. The project aims to create a canvas-based artwork that incorporates touch-sensitive circuits made with conductive paint and copper tape. The touch interactions on the painted canvas generate analog signals, which are then transmitted to the ESP32 microcontroller. The microcontroller communicates with the laptop through the WebSerial API, allowing the laptop to read the values from the serial port and generate corresponding changes on a webpage using Tone.js.

Set-up

Prepare the canvas: Use a canvas or any suitable surface for painting. Apply a layer of acrylic paint as the base color.
Create circuits: Use conductive paint to draw circuits on the canvas. Connect different parts of the circuits using copper tape at the back of the canvas. Ensure proper connections and continuity throughout the circuits.
Connect to ESP32: Solder wires onto the copper tape and connect them to the appropriate pins on the ESP32 microcontroller. Ensure a secure and reliable connection.
Connect to laptop: Connect the ESP32 to the laptop using a USB cable. Make sure the ESP32 is properly recognized by the laptop.
Code configuration: Upload the appropriate code to the ESP32 using the Arduino IDE. Configure the code to read analog values from the connected circuits and transmit them through the serial port.
Webpage setup: Create an HTML file that utilizes the WebSerial API to read values from the serial port. Use Tone.js to generate sound based on the received values. Make sure the HTML file is properly linked to the required libraries.
Test and interact: Open the HTML file in a web browser. Interact with the conductive circuits on the canvas by touching the painted areas. Observe the changes in sound generated on the webpage based on the analog values received.
