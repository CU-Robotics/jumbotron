#include "interface.h"

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <iostream>
#include <string>
#include <XPT2046_Touchscreen.h>

uint16_t rgb(uint8_t r, uint8_t g, uint8_t b) {
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

//R207 G184 B124
//uint16_t CUCOLOR = rgb(255, 215, 124);
uint16_t CUGOLD = 65199;
uint16_t CUDARKGRAY = 21195;
/*
void makeSquare(int16_t x, int16_t y, char size, uint16_t color, std::string text) {
  switch(size) {
    case 'L':
        break;
    case 'M':
        break;
    case 'S':
        break;
  }
}
*/
void mainMenu(Adafruit_ILI9341 tft) {
    tft.fillScreen(ILI9341_BLACK);
    //tft.println(CUDARKGRAY);

    tft.fillRoundRect(64, 37, 60, 60, 10, CUGOLD);
    tft.fillRoundRect(131, 37, 60, 60, 10, ILI9341_LIGHTGREY);
    tft.fillRoundRect(198, 37, 60, 60, 10, CUGOLD);

    tft.fillRoundRect(64, 104, 60, 60, 10, ILI9341_LIGHTGREY);
    tft.fillRoundRect(131, 104, 60, 60, 10, CUGOLD);
    tft.fillRoundRect(198, 104, 60, 60, 10, ILI9341_LIGHTGREY);

    tft.fillRoundRect(64, 171, 60, 60, 10, CUGOLD);
    tft.fillRoundRect(131, 171, 60, 60, 10, ILI9341_LIGHTGREY);
    tft.fillRoundRect(198, 171, 60, 60, 10, CUGOLD);

}

void menuHelper(Adafruit_ILI9341 tft, XPT2046_Touchscreen ts, TS_Point pt) {
    if (ts.touched() == true) {
        pt = ts.getPoint();

        tft.println(pt.x);
        tft.println(pt.y);

        //Check for btn press:
        
        //btn 1
        /*
        if (pt.x >= 64 && pt.x <=198 && pt.y >=37 && pt.y <=171) {
            tft.println(pt.x);
            tft.println(pt.y);
        } else {
            tft.fillRect(0,0,50,50,ILI9341_BLACK);
        }
        */
    }
}
