# Cheese Board - Cheddar


This is an ESP8266 breakout board with small display, user inputs and WS2812 LEDs. 

This is designed as a low cost platform to quickly get started with projects with the ESP8266. We wanted to design something that got you up and running with your project idea quickly and easily.

The main processor is based upon the [ESP8266 system-on-chip from Espressif Systems](https://en.wikipedia.org/wiki/ESP8266).

This can be programmed via the Arduino IDE (or your favourite IDE).

This repository contains the design files, software and hardward files for this project.

We can supply this project in kit form from [The Curious Electric Company](https://www.curiouselectric.co.uk/) and Tindie.

This repository is for the hardware and instructions only. The software is available here:

https://github.com/curiouselectric/CheeseBoard_Software

## Instructions

The instructions are available in this folder as a .pdf

## PCB Overview

It is based upon the NodeMCU Amica ESP8266 module which is low-cost, easy to find and has all regulation and protection required.

There is a small I2C interfaced OLED screen on the unit for displaying data and options.

A rotary encoder is used to select various options and as the user interface.

There are five WS2812 LEDs which can be controlled via the ESP8266, along with a level shifter for good 5V operation.

A connection output is provided for HC12 wireless modules and access to a software serial output is provided through screw terminal pads.

This can be powered via USB-B or Micro-USB connector.

A screw-temrinal connector for 5V power is also supplied, if needed.

PCB design has been produced using [KiCAD](http://kicad-pcb.org/).

Hardware for the enclosure is also provided here.


### Pin Connections:

| Node MCU Conenction | Pin Number     |Function          | Arduino Alias   |
|---------------------|----------------|------------------|-----------------|
| D0                  | 30             | HC-12 SET pin    | 16              |
| D1                  | 29             | Soft Serial Tx   | 5               |
| D2                  | 28             | Soft Serial Rx   | 4               |
| D3                  | 27             | LED WS2812       | 0               |
| D4                  | 26             | I2C SCLK         | 2               |
| D5                  | 23             | I2C SDA          | 14              |
| D6                  | 22             | Enocder B        | 12              |
| D7                  | 21             | Enocder A        | 13              |
| D8                  | 20             | Encoder Switch   | 15              |
| D9                  | 19             | H/W Serial Rx    | 3               |
| D10                 | 18             | H/W Serial Tx    | 1               |
| A0                  | 1              | N/C              | A0              |


## Software Overview

This project has been designed with some interesting software to get you up and running. We wanted this project to do something useful or fun straight away. But it has been designed for hacking and for you to change, alter, adjust and play as you need.

## Hardware Overview

This kit comes with a simple enclosure to house the electronics.

This has been designed to be laser cut in 3mm acrylic. The design files are within this repository, if you would like to make your own or alter the design at all.


# To Do

* Check software in many applications
* Update instructions as required
