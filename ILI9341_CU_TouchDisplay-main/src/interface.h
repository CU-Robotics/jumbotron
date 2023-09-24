#ifndef INTERFACE
#define INTERFACE

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <iostream>
#include <string>
#include <XPT2046_Touchscreen.h>

uint16_t rgb(uint8_t, uint8_t, uint8_t);

void makeSquare(int, int, char, uint16_t, std::string);

void menuHelper(Adafruit_ILI9341, XPT2046_Touchscreen, TS_Point);

void mainMenu(Adafruit_ILI9341);

#endif