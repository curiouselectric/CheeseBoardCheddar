#include <Arduino.h>

// Include all dependent libraries so the Arduino IDE knows to add 
// the library paths into the build. Make sure all these libraries
// are installed on your system
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#include <Encoder.h>
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

// Include CheeseBoard headers for the components we'll be using in
// this example
#include <MutilaDebug.h>
#include <Millis.h>
#include <CbOledDisplay.h>
#include <GfxSSIDListBox.h>
#include <CbRotaryInput.h>

#include "Scanner.h"

// Function prototypes.  For the Arduino IDE you don't need these, but they 
// make it possible to build with the Makefile approach without having to put
// functions in the file before they are referenced by other functions.
void setup();
void loop();
void buttonCb(uint16_t durationMs);
void rotaryCb(int8_t diff, int32_t value);
int rssiToQuality(int RSSI);
void scanCb(int16_t numNetworks);
void updateDisplay();

// Global variables
GfxSSIDListBox listbox(128);        // A global listbox object
uint32_t lastDisplayRefresh = 0;    // Timer to refresh display now and then
bool displayUpdate = true;          // Flag to request immediate display update

void setup()
{
    Serial.begin(115200);
    DBLN(F("S:setup"));

    CbOledDisplay.begin();
    CbRotaryInput.begin(buttonCb, rotaryCb);
    Scanner.begin(scanCb);

    Scanner.startScan();
    DBLN(F("E:setup"));
}

void loop()
{
    CbRotaryInput.update();
    Scanner.update();
    updateDisplay();
}

void buttonCb(uint16_t durationMs)
{
    DBLN("buttonCb");
    displayUpdate = true;
}

void rotaryCb(int8_t diff, int32_t value)
{
    DBF("rotaryCb diff=%d value=%d", diff, value);
    int16_t i = listbox.selected();
    int16_t n = diff > 0 ? listbox.findNext(i) : listbox.findPreceding(i);
    DBF(" current=%d new=%d\n", i, n);
    if (n != -1) {
        listbox.select(n);
        listbox.scrollTo(n);
    }
    displayUpdate = true;
}

int rssiToQuality(int RSSI) {
    int quality = 0;

    if (RSSI <= -100) {
        quality = 0;
    } else if (RSSI >= -50) {
        quality = 100;
    } else {
        quality = 2 * (RSSI + 100);
    }   
    return quality;
}

void scanCb(int16_t numNetworks)
{
    DBF("scanCb number of networks found=%d:\n", numNetworks);
    for (int16_t i=0; i<numNetworks; i++) {
        DBF("%d: %s, Ch:%d Qu:%d %s\n", i+1, WiFi.SSID(i).c_str(), WiFi.channel(i), rssiToQuality(WiFi.RSSI(i)), WiFi.encryptionType(i) == ENC_TYPE_NONE ? "open" : "secure");
        listbox.update(WiFi.SSID(i), WiFi.channel(i), rssiToQuality(WiFi.RSSI(i)));
    }
    Scanner.startScan();
}

void updateDisplay()
{
    if (Millis() > lastDisplayRefresh + 3000 || displayUpdate) {
        lastDisplayRefresh = Millis();
        displayUpdate = false;

        CbOledDisplay.clearBuffer();
        if (listbox.count() == 0) { 
            CbOledDisplay.drawText("no networks found\nscanning...", 'C', 'M');
        } else {
            if (listbox.selected() == -1) {
                listbox.select(0);
            }
            listbox.draw();
        }
        CbOledDisplay.sendBuffer();
    }
}

