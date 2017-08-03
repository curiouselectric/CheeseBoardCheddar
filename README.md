# WiFiESP
An ESP8266 breakout board with Display and WS2812 LEDs. Its based upon the NodeMCU Amica ESP8266 module which is low-cos, easy to find and has all regulation and protection required.

There is a small OLED screen on the unit for displaying data and options.

A rotary encoder is used to select various options and as the user interface.

There are 5 WS2812 LEDs which can be controlled via the ESP8266, along with a level shifter for good 5V operation.#

A connection output is provided for HC12 wireless modules and access to a software serial output is provided through screw terminal pads.

This can be powered via USB-B or Micro-USB connector.

Also a connector for 5V power is supplied.

PCB design has been produced using KiCAD and is available here.

Hardware for the enclosure is also provided here.


##Pin Connections:

| Node MCU Conenction | Pin Number     |Function          |
|---------------------|----------------|------------------|
| D0                  | 30             | HC-12 SET pin    |
| D1                  | 29             | HC-12 SET pin    |
| D2                  | 28             | HC-12 SET pin    |
| D3                  | 27             | HC-12 SET pin    |
| D4                  | 26             | HC-12 SET pin    |
| D5                  | 23             | HC-12 SET pin    |
| D6                  | 22             | HC-12 SET pin    |
| D7                  | 21             | HC-12 SET pin    |
| D8                  | 20             | HC-12 SET pin    |
| D9                  | 19             | HC-12 SET pin    |
| A0                  | 1              | HC-12 SET pin    |



