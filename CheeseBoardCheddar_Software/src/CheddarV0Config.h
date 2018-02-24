#pragma once

/*! Configuration for CheeseBoard: Cheddar v0 (prototype with track error) */

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <stdint.h>

const uint8_t   ROT_PUSH_PIN                = D8;
const uint8_t   ROT_A_PIN                   = D7;
const uint8_t   ROT_B_PIN                   = D6;

const uint8_t   CBOLED_SDA_PIN              = D5;
const uint8_t   CBOLED_SCK_PIN              = D4;
#define         CBOLED_CLASS                U8G2_SSD1306_128X64_NONAME_F_SW_I2C
#define         CBOLED_MESSAGE_FONT         u8g2_font_helvR08_tf
const uint8_t   CBOLED_MESSAGE_FONT_HEIGHT  = 8;
const uint8_t   CBOLED_MESSAGE_FONT_VSEP    = 3;

const uint8_t   RGBLED_DATA_PIN             = D3;
const uint8_t   RGBLED_COUNT                = 5;
const uint8_t   RGBLED_BRIGHTNESS           = 16;
const float     RGBLED_CORRECTION           = 25.4;
#define         RGBLED_TYPE                 (NEO_GRB + NEO_KHZ800)

const uint8_t   HC12_RX_PIN                 = D2;
const uint8_t   HC12_TX_PIN                 = D1;
const uint8_t   HC12_SET_PIN                = D0;

#define         TEXTLISTITEM_FONT           u8g2_font_helvR08_tf
const uint8_t   TEXTLISTITEM_FONT_HEIGHT    = 8;
const uint8_t   TEXTLISTITEM_FONT_PADDING   = 1;
const uint8_t   TEXTLISTITEM_HEIGHT         = TEXTLISTITEM_FONT_HEIGHT + 2*TEXTLISTITEM_FONT_PADDING + 2;

// This should be defined only when using the "version 0", preproduction
// boards with the button hack.  For production boards, delete this 
// BOARD_V0 #define.
#define BOARD_V0                            true


